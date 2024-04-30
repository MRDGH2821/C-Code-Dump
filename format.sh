#!/usr/bin/env bash

echo -----------------------------------
echo "Formatting with Astyle"
astyle --style=google --indent=spaces=2 --indent-classes --indent-modifiers --indent-switches --indent-cases --indent-namespaces --indent-preproc-block --indent-col1-comments --min-conditional-indent=2 --break-blocks=all --delete-empty-lines --break-one-line-headers --fill-empty-lines --suffix=none --add-braces --attach-return-type --mode=c --lineend=linux --recursive "./src/*.c"

echo -----------------------------------
echo "Formatting with Clang tidy"
clang-tidy --fix --fix-errors ./src/*.c

echo -----------------------------------
echo "Formatting with Clang format"
clang-format -i ./src/*.c
