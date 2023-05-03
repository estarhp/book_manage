//
// Created by 86139 on 2023/5/3.
//
#include "../book_manage.h"
#include "stdio.h"
#include "string.h"

void query_book(int books_number,Book books[]){
    setbuf(stdout,0);//缓冲
    int select_mode=0;
    int x,y;
    gotoxy_book(2000, 5);
    printf("\n\t                        1->通过id                         \t\n");
    gotoxy_book(2001, 6);
    printf("\n\t                        2->通过作者                        \t\n");
    gotoxy_book(2002, 7);
    printf("\n\t                        3->通过书名                        \t\n");
    gotoxy_book(2003, 8);
    printf("\n\t                      请输入你的选择（数字）：                \n\t");
    x = wherex_book();

    y = wherey_book();

    gotoxy_book(x - 2, y);
    //system("pause");
    scanf("%d",&select_mode);
    switch (select_mode) {
        case 1:query_byid(books_number,books);
            break;
        case 2:query_bywriter(books_number,books);
            break;
        case 3:query_bybookname(books_number,books);

    }

}

int  query_byid(int books_number,Book books[]){
    int id;
    printf("请输入书本的id");
    scanf("%d",&id);
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < books_number; ++i) {
        if(books[i].id==id){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
            return i;
        }
    }
}

void query_bywriter(int books_number,Book books[]){
    char writer[50];
    printf("请输入书本的作者");
    scanf("%s",writer);
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < books_number; ++i) {
        if(strcmp(writer,books[i].writer)==0){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }
}

void query_bybookname(int books_number,Book books[]){
    char bookname[20];
    printf("请输入书本的书名");
    scanf("%s",bookname);
    printf("以下是匹配的查询结果：\n");

    for (int i = 0; i < books_number; ++i) {
        if(strcmp(bookname,books[i].name)==0){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }

}

