#!/bin/bash

# ml LLVM/9.0.0-GCCcore-8.3.0
llvm_dir=/apps/software/LLVM/9.0.0-GCCcore-8.3.0
install_path=$HOME/local/f18/022920

LLVM=$llvm_dir/lib/cmake/llvm \
    cmake .. \
    -DGCC=/apps/software/GCCcore/8.3.0 \
    -DLLVM_DIR=$LLVM \
    -DCMAKE_INSTALL_PREFIX=$install_path \
    -DCMAKE_BUILD_TYPE=Debug

    # CXX=g++ \
