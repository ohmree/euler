debug() {
    if [ -z "$1" ]
    then
        printf "No arguments\n"
    else
        bin/debug/$1
    fi
}

release() {
    if [ -z "$1" ]
    then
        printf "No arguments\n"
    else
        bin/release/$1
    fi
}