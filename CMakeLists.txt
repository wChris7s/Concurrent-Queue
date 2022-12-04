cmake_minimum_required(VERSION 3.24)
project("CQueue-Queue")

set(CMAKE_CXX_STANDARD 23)

find_package(Threads)
include_directories(CMAKE_CURRENT_SOURCE_DIR/src)

add_executable(CQueue src/main.cpp src/queue.h src/concurrent-queue.h)
target_link_libraries(CQueue Threads::Threads)
