#!/bin/bash

# ml LLVM/9.0.0-GCCcore-8.3.0
llvm_dir=/apps/software/LLVM/9.0.0-GCCcore-8.3.0
install_path=$HOME/local/f18/021720

LLVM=$llvm_dir/lib/cmake/llvm \
    CXX=g++ \
    cmake .. \
    -DLLVM_DIR=$LLVM \
    -DCMAKE_INSTALL_PREFIX=$install_path \
    -DCMAKE_BUILD_TYPE=Debug
