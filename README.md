# pcreator
Creates a simple C++ project including CMake build script
The current focus is building Qt Hello World style projects quickly. 

Compile pcreator:
Compile like any Qt CMake project.

```
    mkdir <build_dir>
    cd <build_dir>
    cmake <src_dir> -DCMAKE_PREFIX_PATH=<QtDir>/lib/cmake
    make
```


Usage: 

```
    cd <root-directory-of future-project>
    pcreator MyCosmicProject
    cd MyCosmicProject
    ... hack hack hack ...
```




