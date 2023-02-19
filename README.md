# cmake-cpp-starter-kit

[![CI](https://github.com/ChenKS12138/cmake-cpp-starter-kit/actions/workflows/CI.yml/badge.svg)](https://github.com/ChenKS12138/cmake-cpp-starter-kit/actions/workflows/CI.yml)

cmake-cpp-starter-kit

## Requirement

> cmake >= 3.11  
gcc >= 7 or clang >= 5 (To Support c++17)  
(Optional) Ninja >= 1.10.0 (For faster build)

## How To Run

```shell
# Fetch submodule
git submodule update --init --recursive

# Create build directory
cmake -S . -B build
# Or build with Ninja (Recommend)
# cmake -S . -B buld -GNinja 

# Run build
cmake --build build

# Run Application
./build/main

# Run Test
cmake --build build --target test

# Format your code
cmake --build build --target format
```

## TODO

- [x] Generate `compile-commands.json`
- [x] `abseil` support
- [x] `clang-format` support
- [x] `googletest` support
