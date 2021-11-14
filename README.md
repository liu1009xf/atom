# Automated Trading Operation Manager(ATOM)

[![Unit Test(Linux)](https://github.com/liu1009xf/atom/actions/workflows/linux_ut.yml/badge.svg)](https://github.com/liu1009xf/atom/actions/workflows/linux_ut.yml)
[![Unit Test(Mac)](https://github.com/liu1009xf/atom/actions/workflows/mac_ut.yml/badge.svg)](https://github.com/liu1009xf/atom/actions/workflows/mac_ut.yml)
[![Unit Test(Windows)](https://github.com/liu1009xf/atom/actions/workflows/windows_ut.yml/badge.svg)](https://github.com/liu1009xf/atom/actions/workflows/windows_ut.yml)

### Still implementing very basic stuffs. Currently nothing works at all.

## Build and Test:
```
cd path/to/atom
mkdir build
cd build
conan install ..
cmake ..
cmake --build .
```
  
To run tests, in addition to above commends:
```
ctest --verbose
```