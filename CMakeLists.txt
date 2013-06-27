cmake_minimum_required(VERSION 2.6)
project(test_odbc)

add_executable(test_odbc main.c)

target_link_libraries(test_odbc
   odbc
   )
