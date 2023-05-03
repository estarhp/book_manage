cmake_minimum_required(VERSION 3.23)
project(Book_manage C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c
        book_manage/books_manage.c
        borrow_return/borrow_return.c
        reader_manage/reader_manage.c
        book_manage/init_book.c
        book_manage/details/add_book.c
        book_manage/details/delete_book.c
        book_manage/details/modify_book.c
        book_manage/details/qurry_book.c
        book_manage/details/show_book.c)
