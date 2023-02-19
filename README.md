# cmake-cpp-starter-kit

[![CI](https://github.com/ChenKS12138/cmake-cpp-starter-kit/actions/workflows/CI.yml/badge.svg)](https://github.com/ChenKS12138/cmake-cpp-starter-kit/actions/workflows/CI.yml)

cmake-cpp-starter-kit

## How To Run

```shell
git submodule update --init --recursive
# Create build directory
cmake -S . -B build
# Or build with Ninja (Recommend)
# cmake -S . -B buld -GNinja 

# Run build
cmake --build build

# Run Application
./build/main

# Format your code
cmake --build build --target format
```

## TODO

- [x] Generate `compile-commands.json`
- [x] `abseil` support
- [x] `clang-format` support
- [ ] `gtest` support

