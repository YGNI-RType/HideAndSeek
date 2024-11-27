#!/bin/bash

mkdir -p build
cd build
touch .gitkeep

cmake .. -DCMAKE_TOOLCHAIN_FILE=./cmake/define-compilers.cmake -DCMAKE_BUILD_TYPE=Release || { echo "CMake configuration failed"; exit 1; }
cmake --build . || { echo "CMake build failed"; exit 1; }

echo "Running server..."
mkfifo pipe
./hs_server > pipe &
SERVER_PID=$!
tee server_output.log < pipe &
TEE_PID=$!

cleanup() {
    echo "\nCleaning up..."
    kill $SERVER_PID 2>/dev/null
    kill $TEE_PID 2>/dev/null
    rm pipe
    kill $CLIENT_PID 2>/dev/null
    exit 0
}

# Trap CTRL + C (SIGINT)
trap cleanup SIGINT

sleep 5

echo "Running client..."
./hs_client

kill $SERVER_PID 2>/dev/null
kill $TEE_PID 2>/dev/null
rm pipe

cd ..
exit 0
