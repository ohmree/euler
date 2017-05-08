#!/usr/bin/env bash
# ~/make
# compile all non empty c files into correct binary files

_compile='cc -O0 -Wall -std=gnu11' # command to compile
_release_compile='cc -O2 -Wall -std=gnu11' # command to compile for release build
_ldflags='-lm'

# check for invalid args
if [ ! -z "$1" ] && [ ! "$1" == "release" ]
then
    printf "Usage: %s # debug build\n%s release #release build\n"
    exit 1
fi    

# iterate over c files in src directory
find './src' -name '*.c' |
while read -r filename
do
    _outfilename="$(echo ${filename%.c}     | awk 'gsub("./src/", "")')"
    _outfilepath="$(echo ${filename%.c}     | awk 'gsub("src", "bin")')"
    _release_filename="$(echo $_outfilepath | awk 'gsub("bin", "bin/release")')"
    _debug_filename="$(echo $_outfilepath   | awk 'gsub("bin", "bin/debug")')"
    
    #if  [ ! -f "$filename" ] && [ -f "$_outfilename" ] # remove output files that
                                                      #+don't have corresponding
                                                      #+source files, why
                                                      #+doesn't this work???
    # this version also doesn't work
    # if  [[ ! -f "$filename"  &&  -f "$outfilename" ]]
    #then
    #    rm "$_outfilename"
    #fi
    
    if [ -s "$filename" ] # if file is not empty
    then # compile file into correct output
        $_release_compile "$filename" -o "bin/release/$_outfilename" $_ldflags
        $_compile "$filename" -o "bin/debug/$_outfilename" $_ldflags
    fi
done