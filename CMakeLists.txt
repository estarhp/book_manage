cmake_minimum_required(VERSION 3.23)
project(Book_manage C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c books_manage.c borrow_return.c reader_manage.c)
