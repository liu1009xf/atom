#!/bin/bash

# This script can be called from anywhere and allows to build out of source.

# Determine script absolute path
SCRIPT_ABS_PATH=$(readlink -f ${BASH_SOURCE[0]})
SCRIPT_ABS_PATH=$(dirname ${SCRIPT_ABS_PATH})

# switch to root folder, where top-level CMakeLists.txt lives
ROOT=$(readlink -f ${SCRIPT_ABS_PATH}/../)
cd $ROOT

# Choose build type
BUILD_TYPE=Release
# BUILD_TYPE=Debug

# Choose build type
BUILD_DIR=_build

# Choose install folder
INSTALL_DIR=_install

# Options summary
echo ""
echo "BUILD_TYPE  =" ${BUILD_TYPE}
echo "BUILD_DIR   =" ${ROOT}/test/${BUILD_DIR}/
echo "INSTALL_DIR =" ${ROOT}/test/${INSTALL_DIR}/
echo ""


# ------------------------------
# test (for testing)
# ------------------------------
printf "\n\n ----- test ----- \n\n"

# clean
# rm -fr test/${BUILD_DIR}

cd ${ROOT}/test/${BUILD_DIR}/
conan install ..
cd $ROOT

SO=`uname`
if [[ $SO == "Linux" ]]; then
    echo "Running on Linux"

    # cmake
    cmake \
        -S ${ROOT}/test/ \
        -B ${ROOT}/test/${BUILD_DIR} \
        -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
        -DATOM_DIR="${ROOT}/${INSTALL_DIR}/lib/cmake/ATOM/"

    # compile
    cmake \
        --build ${ROOT}/test/${BUILD_DIR} \
        -j 8

else
    echo "Running on Windows"

    # cmake
    cmake \
        -S ${ROOT}/test/ \
        -B ${ROOT}/test/${BUILD_DIR} \
        -DATOM_DIR="${ROOT}/${INSTALL_DIR}/lib/cmake/ATOM/"

    # compile
    cmake \
        --build ${ROOT}/test/${BUILD_DIR} \
        --config ${BUILD_TYPE} \
        -j 8
fi

cd ${ROOT}/test/${BUILD_DIR}/
ctest -R atom_test -C $BUILD_TYPE --verbose --timeout 600
cd ${ROOT}
