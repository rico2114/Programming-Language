cmake_minimum_required(VERSION 3.4)
project(Compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/tokenizer/StringTokenizer.cpp src/tokenizer/StringTokenizer.h src/core/Main.cpp src/tests/StringTokenizerTest1.cpp src/output/ActionOpcode.cpp src/output/Instruction.h src/tokenizer/FileReader.h src/tokenizer/FileReader.cpp src/core/Compiler.cpp src/core/Compiler.h)
add_executable(Compiler ${SOURCE_FILES})