#!/usr/bin/env bash
set -euo pipefail

BASE="https://raw.githubusercontent.com/IchigoSolos69/DAA-Assignments/main/viva-codes"
declare -a NAMES=(fractional_knapsack zero_one_knapsack merge_sort graph_coloring dijkstra)

usage() {
  printf '%s\n' "DAA Viva Code + Notes Downloader" \
    "1) Fractional Knapsack" \
    "2) 0/1 Knapsack" \
    "3) Merge Sort with File Handling" \
    "4) Graph Coloring" \
    "5) Dijkstra's Algorithm" \
    "a) Download all five (code + viva notes)" \
    "q) Quit"
}

download_one() {
  local index="$1" name
  name="${NAMES[index-1]}"
  curl -fL --retry 2 --silent --show-error "$BASE/$name.cpp" -o "$name.cpp"
  curl -fL --retry 2 --silent --show-error "$BASE/${name}_viva.md" -o "${name}_viva.md"
  printf 'Downloaded %s.cpp and %s_viva.md\n' "$name" "$name"
}
selection="${1:-}"
if [[ -z "$selection" ]]; then
  usage
  read -r -p "Select (1-5/a): " selection </dev/tty
fi

case "$selection" in
  1|2|3|4|5) download_one "$selection" ;;
  a|A|all|ALL)
    for i in 1 2 3 4 5; do download_one "$i"; done ;;
  q|Q|quit|QUIT) exit 0 ;;
  *) usage; printf 'Invalid choice: %s\n' "$selection" >&2; exit 2 ;;
esac
printf '%s\n' 'Viva notes are in *_viva.md; read with: less filename_viva.md'
printf '%s\n' 'Original C++ source is preserved as pasted; known bugs have NOT been fixed.'
