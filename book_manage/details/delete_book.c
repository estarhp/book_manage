//
// Created by 86139 on 2023/5/3.
//
#include "../book_manage.h"
#include "stdio.h"
#include "string.h"

void delete_book(int books_number,Book books[]){
    int delete_input;
    printf("1 -> 通过id删除\n"
           "2 -> 通过书名删除\n"
           "3 -> 通过作者删除\n");
    scanf("%d",&delete_input);
    switch (delete_input) {
        case 1:
            delete_book_by_id(books_number,books);
            break;
        case 2:
            delete_book_by_name(books_number,books);
            break;
        case 3:
            delete_book_by_writer(books_number,books);
            break;
    }
}

void open_delete_book(int will_delete[],int number,int books_number,Book books[]){
    FILE *fp;
    if ((fp = fopen("../book_manage/books.txt", "w+")) == NULL){
        if ((fp = fopen("book_manage/books.txt", "w+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    printf("%p",fp);

    rewind(fp);
    for (int j = 0; j < books_number; ++j) {
        int flag=1;
        for (int k = 0; k < number; ++k) {
            if(will_delete[k]==j) flag=0;
        }
        if(flag)
            fprintf(fp,"%d %s %s\n",books[j].id,books[j].writer,books[j].name);
    }
    fclose(fp);

}

void delete_book_by_id(int books_number,Book books[]){
    int number=0;
    int will_delete[10];
    int id;
    printf("请输入书本的id");
    scanf("%d",&id);

    for (int i = 0; i < books_number; ++i) {
        if(books[i].id==id){
            will_delete[number]=i;
            number++;
        }
    }
    if(number == 0 ) {printf("没有符合要求的图书！！");
        return;}
    open_delete_book(will_delete,number,books_number,books);
    printf("删除书本成功！");
}
void delete_book_by_writer(int books_number,Book books[]){
    int number=0;
    int will_delete[10];
    char writer[50];
    printf("请输入书本的作者");
    scanf("%s",writer);
    for (int i = 0; i < books_number; ++i) {
        if(strcmp(writer,books[i].writer)==0){
            will_delete[number]=i;
            number++;
        }
    }
    if(number == 0 ) {printf("没有符合要求的图书！！");
        return;}
    open_delete_book(will_delete,number,books_number,books);
}
void delete_book_by_name(int books_number,Book books[]){
    int number=0;
    int will_delete[10];
    char bookname[20];
    printf("请输入书本的书名");
    scanf("%s",bookname);

    for (int i = 0; i < books_number; ++i) {
        if(strcmp(bookname,books[i].name)==0){
            will_delete[number]=i;
            number++;
        }
    }
    if(number == 0 ) {printf("没有符合要求的图书！！");
        return;}
    open_delete_book(will_delete,number,books_number,books);

}