# Q3 — Merge Sort with CSV File Handling: Viva Terms and Answers

## Algorithm in one sentence
Read product rows from a CSV file into a `vector<Record>`, **recursively divide** the vector, **merge** sorted halves by a chosen field, and write a new CSV.

## Every important term in the given code
| Term / syntax | Definition and role |
|---|---|
| `#include <iostream>` | Standard input/output: `cin`, `cout`, `endl`. |
| `#include <fstream>` | File streams: `ifstream` and `ofstream`. |
| `#include <sstream>` | `stringstream` to parse one text line as a stream. |
| `#include <vector>` | `vector` dynamic array container. |
| `#include <string>` | `string` text class. |
| `#include <algorithm>` | Included but not needed for this hand-written Merge Sort. |
| `struct Record` | Defines a user-defined aggregate containing multiple product fields. |
| `name` | Product name, a `string`. |
| `sold_out` | Integer product field representing sold-out count. |
| `pricing`, `rating` | Numeric fields stored as `double`. |
| `Record r` | Creates an individual product record. |
| `r.name`, `r.pricing` | The dot operator accesses a structure member. |
| `vector<Record> data` | Dynamic sequence of product records; size need not be known beforehand. |
| `vector<Record>& data` | Reference parameter; functions modify the caller's vector without copying it. |
| `void` | Function's return type when no value is returned. |
| `mergeSort(data,low,high,ch)` | Recursive sort of the inclusive range `low..high`. |
| `merge(data,low,mid,high,ch)` | Merges two sorted ranges: `low..mid` and `mid+1..high`. |
| `low`, `high` | Inclusive start and end indices for the current range. |
| `mid=(high+low)/2` | Middle index dividing a range into two roughly equal halves. |
| `ch` | Sorting choice: 1 for pricing, 2 for rating, 3 for sold_out. |
| `i` | Current index of the left half during a merge. |
| `j` | Current index of the right half during a merge. |
| `k` | Destination index in the temporary merged sequence. |
| `temp(data.size())` | Auxiliary vector used during merging. |
| `while(i<=mid && j<=high)` | Continue while both halves have remaining records. |
| `data[i].pricing <= data[j].pricing` | Chooses lower price first; similar comparisons exist for rating and sold-out. |
| `temp[k++]=data[i++]` | Copy left record to destination, then advance both indices. |
| `for(int p=low;p<=high;p++)` | Copies merged records back to the main vector. |
| **Divide and conquer** | Divide a problem into halves, solve each, then combine solutions. |
| **Recursion** | A function calls itself on smaller ranges. |
| **Base case** | `low>=high`: range has at most one element and is sorted. |
| **Merge** | Linear-time combination of two already sorted ranges. |
| **Stable sort** | Equal-key records retain original relative order; using `<=` chooses from the left first. |
| **Ascending order** | From the smallest selected field value to the largest. |
| `ifstream file("ecommerce.csv")` | Input file stream; tries opening a file in the process's working directory. |
| `if(!file)` | Checks for a file-stream failure (e.g., failed open). |
| `getline(file,line)` | Reads an entire line; first call skips the header row. |
| `while(getline(file,line))` | Reads records until no more successful line reads. |
| `stringstream ss(line)` | Wraps a line in a stream to extract comma-separated fields. |
| `getline(ss,temp,',')` | Reads one CSV field up to the comma delimiter. |
| **Delimiter** | Character separating fields, here `,`. |
| **CSV** | Comma-Separated Values, a plain-text table format. |
| **Parsing** | Interpreting a text row and converting its fields into typed data. |
| `stod(temp)` | Convert a numeric string to `double` (string-to-double). |
| `stoi(temp)` | Convert a numeric string to `int` (string-to-integer). |
| `data.push_back(r)` | Appends one record to the dynamic vector. |
| `data.size()` | Returns number of stored records. |
| `data.empty()` | Checks whether vector is empty. |
| `file.close()` | Explicitly closes the input stream. |
| `ofstream outFile(filename)` | Creates/opens CSV file for output. |
| `for(Record r : data)` | Range-based for loop; copies each record into `r` (use `const Record&` to avoid copies). |
| `outFile << ...` | Serializes records as comma-delimited output. |
| **Serialization** | Converting in-memory records to a file representation. |
| `return 1` | Nonzero exit status for an error. |
| **Time complexity** | Merge Sort O(n log n) in best, average, and worst cases, assuming correct merge code. |
| **Auxiliary space** | O(n) for temporary storage, plus O(log n) recursive call stack. |

## Why the algorithm works
1. Compute `mid` and recursively sort the left and right halves.
2. During the merge, repeatedly copy the smaller of the two current keys to `temp[k]`.
3. Copy any remainder from each half.
4. Copy `temp[low..high]` back into `data[low..high]`.
5. Use the chosen `ch` field to decide which comparison to perform.

## Code bug that MUST be understood
The supplied code contains:
```cpp
while(i<=mid) temp[i++] = data[i++];
while(j<=high) temp[j++] = data[j++];
```
Both lines are **incorrect**: they use the input cursor as the destination and increment the same variable twice. Correct:
```cpp
while(i<=mid) temp[k++] = data[i++];
while(j<=high) temp[k++] = data[j++];
```
The original C++ source is preserved as pasted; this fix is explained, **not silently applied**.

## Other limitations
- `getline(ss,temp,',')` after reading a line skips the first **field**, not an entire line.
- The file must have the expected field order: ignored ID, name, pricing, rating, sold_out.
- Simple comma parsing does not handle quoted commas in product names.
- `stoi` and `stod` can throw if input strings are invalid.
- File output is not an in-place modification of the source CSV.

## Common viva questions — short answers
**Why Merge Sort?** It guarantees O(n log n) sorting time independent of input order.

**Which paradigm?** Divide and conquer.

**What does mid represent?** Split point of the current range.

**What is a base case?** When `low>=high`, the subarray is already sorted.

**Is it stable?** Yes, when equal keys are taken from the left half first.

**Is it in-place?** Not this implementation; it uses an auxiliary vector.

**Why use vector?** It can grow as an unknown number of file rows are read.

**What do ifstream and ofstream do?** Read input and write output files.

**Difference between stod and stoi?** String-to-double versus string-to-integer.

**Why might the program crash during a merge?** Its two remainder-copy loops are wrong.
