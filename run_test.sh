mkdir -p "build"
cd "build"
conan install ..
cmake ..
cmake --build .
ctest --verbose .