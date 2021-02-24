#!/bin/bash
# Generated using BSHA - Build .sh assembler for C++
# GitHub: https://github.com/AlexeyFilich/bsha

if [ "$1" == "--full" ] || [ "$1" == "-f" ]; then
    rm -rf build
fi

[ ! -d build ] && mkdir build

main_should_recompile="False"
total=3
current=1

start=$(date '+%s')

printHeader() {
    perc=$((100 * $current / $total))
    leading=${#perc}
    printf -- "[\e[38;05;2;49;24;27m"
    [ $leading == "1" ] && printf -- "  "
    [ $leading == "2" ] && printf -- " "
    printf -- "$perc\e[0m] Building \e[38;05;3;49;04;27m$1\e[0m\n"
    current=$(($current + 1))
}

checkRecomp() {
    [ ! -d $3 ] && mkdir -p $3
    [ ! -f $2 ] && touch $2
    file_hash=$(md5sum $1)
    last_hash=$(cat $2)
    if [ "$file_hash" != "$last_hash" ]
    then
        main_should_recompile="True"
        recompile="True"
        [ -f $4 ] && rm $4
    else
        printf -- "..... \e[38;05;3;49;04;27m$1\e[0m \e[38;05;10;49;24;27mis up to date\e[0m\n"
    fi
}

checkSuccess() {
    if [ ! -f $1 ]
    then
        echo > $2
        printf -- "\e[38;05;1;49;24;27m-- Compilation failed!\e[0m\n"
        exit 1
    fi
}

printf -- "\e[38;05;2;49;24;27m--\e[0m \e[38;05;2;49;04;27mStarting build process\e[0m\n"
printf -- "\e[38;05;2;49;24;27m-- Compiler: \e[0m \e[38;05;3;49;04;27mg++\e[0m\n\n"

recompile="False"
printHeader src/Engine.cpp
checkRecomp src/Engine.cpp build/src/Engine.hash build/src/ build/src/Engine.o 
if [ $recompile == "True" ]
then
    g++ -c -std=c++17 -static-libstdc++ -static-libgcc -I"include/" -I"third-party/toolbox/" -L"lib/" src/Engine.cpp -o build/src/Engine.o 
    checkSuccess build/src/Engine.o build/src/Engine.hash
    echo "$(md5sum src/Engine.cpp)" > build/src/Engine.hash
fi

recompile="False"
printHeader src/utils.cpp
checkRecomp src/utils.cpp build/src/utils.hash build/src/ build/src/utils.o 
if [ $recompile == "True" ]
then
    g++ -c -std=c++17 -static-libstdc++ -static-libgcc -I"include/" -I"third-party/toolbox/" -L"lib/" src/utils.cpp -o build/src/utils.o 
    checkSuccess build/src/utils.o build/src/utils.hash
    echo "$(md5sum src/utils.cpp)" > build/src/utils.hash
fi

recompile="False"
printHeader src/main.cpp
checkRecomp src/main.cpp build/src/main.hash build/src/ build/src/main.out
if [ $recompile == "True" ] || [ $main_should_recompile == "True" ]
then
    printf -- "..... \e[38;05;3;49;04;27mmain.cpp\e[0m \e[38;05;10;49;24;27mis updating, because other files have changed\e[0m\n"
    g++ -std=c++17 -static-libstdc++ -static-libgcc -I"include/" -I"third-party/toolbox/" -L"lib/" src/main.cpp -o build/src/main.out build/src/Engine.o build/src/utils.o -lpthread -lSDL2main -lSDL2
    checkSuccess build/src/main.out build/src/main.hash
    echo "$(md5sum src/main.cpp)" > build/src/main.hash
fi

cp build/src/main.out bin/main
echo -- Starting
cd bin
./main
cd ..
echo -- Done

printf -- "\n\e[38;05;2;49;24;27mDone! in \e[0m[38;05;3;49;04;27m$(($(date '+%s') - $start))sec.[0m\n"
