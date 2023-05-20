#ifndef UNTITLED_BOOK_MANAGE_H
#define UNTITLED_BOOK_MANAGE_H

#include "stdio.h"

//创建图书容器
typedef struct book {
    int id;
    char name[50];
    char writer[20];
} Book;

int Main_book_mana();
void add_book(Book books[],int books_number,FILE *fp);
FILE * file_open();
void put_book(int number,FILE *fp,Book books[]);//初始化图书
int Books_number(FILE *fp);//计算文件中图书的数目
void Menu_book();
int Collect(int books_number,Book books[],FILE *fp);//收集用户的选择
void delete_book(int books_number,Book books[]);//删除
void modify_book(int books_number,Book books[]);
void query_book(int books_number,Book books[]);//查询图书
void show_book(int books_number,Book *books);//展示图书
int query_byid(int books_number,Book books[]);//通过id
void query_bywriter(int books_number,Book books[]);//通过作者
void query_bybookname(int books_number,Book books[]);//通过书名
int wherex_book();
int wherey_book();
void gotoxy_book(int x, int y);
void delete_book_by_id(int books_number,Book books[]);
void delete_book_by_writer(int books_number,Book books[]);
void delete_book_by_name(int books_number,Book books[]);
void modify_book_by_id(int books_number,Book books[]);
void modify_book_by_name(int books_number,Book books[]);
void modify_book_by_writer(int books_number,Book books[]);
void open_delete_book(int will_delete[],int number, int books_number,Book books[]);

#endif //UNTITLED_BOOK_MANAGE_H
