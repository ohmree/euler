#!/usr/bin/env bash
# ~/make
# compile all non empty c files into correct binary files

_compile='cc -O2 -Wall -std=gnu11' # command to compile

# iterate over c files in src directory
find './src' -name '*.c' |
while read -r filename
do
    if [ -s "$filename" ] # if file is not empty
    then # compile file into correct output
        $_compile "$filename" -o "$(echo ${filename%.c} | awk 'gsub("src", "bin")')"
    fi
done