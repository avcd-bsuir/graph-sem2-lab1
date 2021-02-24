[![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue.svg)](https://bit.ly/cc-by-nc-sa-40)

# Usage

build.json for Unix:
```json
{
    "project": "program",
    "compiler": {
        "path": "g++",
        "flags": "-std=c++17 -static-libstdc++ -static-libgcc",
        "include_path": [
            "include/",
            "third-party/toolbox/"
        ],
        "library_path": [
            "lib/"
        ]
    },
    "main": {
        "path": "src/main.cpp",
        "output_name": "main.out",
        "flags": "",
        "binaries": "-lpthread -lSDL2main -lSDL2"
    },
    "sources": [
        { "path": "src/Engine.cpp", "flags": "", "binaries": "" },
        { "path": "src/utils.cpp", "flags": "", "binaries": "" }
    ],
    "extra_commands": [
        "cp build/src/main.out bin/main",
        "echo -- Starting",
        "cd bin",
        "./main",
        "cd ..",
        "echo -- Done"
    ]
}
```

for Windows:
```json
{
    "project": "program",
    "compiler": {
        "path": "g++.exe",
        "flags": "-std=c++17 -static-libstdc++ -static-libgcc",
        "include_path": [
            "include/",
            "third-party/toolbox/",
            "C:\\MinGW\\include"
        ],
        "library_path": [
            "lib/",
            "C:\\MinGW\\lib"
        ]
    },
    "main": {
        "path": "src/main.cpp",
        "output_name": "main.out",
        "flags": "",
        "binaries": "-lpthread -lmingw32 -lSDL2main -lSDL2"
    },
    "sources": [
        { "path": "src/Engine.cpp", "flags": "", "binaries": "" },
        { "path": "src/utils.cpp", "flags": "", "binaries": "" }
    ],
    "extra_commands": [
        "cp build/src/main.out bin/main",
        "echo -- Starting",
        "cd bin",
        "./main",
        "cd ..",
        "echo -- Done"
    ]
}
```

To compile and run a program use:
```
$ ./build.sh
```

Executable will be started automatically. It can be found in `bin/` folder.

# Semester \<2\> lab \<1\>

Вариант 3. Улитка Паскаля

# Credits

Written by Alexey Filich.

# License

This repository is licensed under [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International](LICENCE.md).
