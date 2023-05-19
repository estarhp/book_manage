//
// Created by 86139 on 2023/5/3.
//

#include "../book_manage.h"
#include "stdio.h"


void add_book(Book books[],int books_number,FILE *fp){
    rewind(fp);
    Book addbook;
    printf("请输入要添加的书名:\n");
    scanf("%s",&addbook.name);
    printf("请输入要添加图书的作者:\n");
    scanf("%s",&addbook.writer);
    addbook.id=books[books_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addbook.id, addbook.writer, addbook.name);
    printf("您已添加成功新的书籍（重新进入系统时刷新数据）\n");
}
