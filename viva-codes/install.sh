#!/usr/bin/env bash
set -euo pipefail
install_dir="$HOME/.local/bin"
mkdir -p "$install_dir"
curl -fsSL "https://raw.githubusercontent.com/IchigoSolos69/DAA-Assignments/main/viva-codes/get.sh" -o "$install_dir/daa"
chmod +x "$install_dir/daa"
case ":$PATH:" in
  *":$install_dir:"*) ;;
  *)
    if ! grep -Fqs 'export PATH="$HOME/.local/bin:$PATH"' "$HOME/.bashrc" 2>/dev/null; then
      printf '\nexport PATH="$HOME/.local/bin:$PATH"\n' >> "$HOME/.bashrc"
    fi
    ;;
esac
printf 'Installed daa at %s\n' "$install_dir/daa"
printf 'Run: ~/.local/bin/daa 1   (or reopen terminal and run: daa 1)\n'
