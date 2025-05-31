cmake_minimum_required(VERSION 3.28.3)

project(loki LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(loki src/main.c src/setup.c src/package.c)

install(TARGETS loki RUNTIME DESTINATION bin)

