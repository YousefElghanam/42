#!/usr/bin/env bash
#
# Usage: ./extract_prototypes.sh file1.c file2.c …
#
# This script runs ctags on each .c file to list all function definitions,
# then prints just the “return_type name(parameter_list);” part into prototypes.txt.

OUTPUT="prototypes.txt"
> "$OUTPUT"

for src in "$@"; do
  # -x: emit a human‐readable “tag listing” instead of a binary .tags file
  # --c-kinds=f: only look for C functions (not variables, macros, etc.)
  ctags -x --c-kinds=f "$src" \
    | awk '
        {
          # ctags -x output fields:
          #   $1 = function name
          #   $2 = line number
          #   $3 = “function”
          #   $4…$NF = the rest of the “signature” (return type + name + params)
          # We want fields 4…NF, joined, then append “;”
          for(i=4; i<=NF; i++) {
            printf "%s%s", $i, (i==NF? ";\n" : " ")
          }
        }
      '
done >> "$OUTPUT"

echo "Prototypes written to $OUTPUT"
