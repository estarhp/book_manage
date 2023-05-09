//
// Created by 86139 on 2023/5/3.
//

#include "stdio.h"
#include "string.h"
#include "../book_manage.h"
void modify_book(int books_number,Book books[]){


    int i=query_byid(books_number,books);




}
void modify_book_by_id(int books_number,Book books[]){
    int index = query_byid(books_number,books);
    char newName[40];
    char newWriter[20];
    printf("请输入新的书名");

    scanf("%s",newName);

    printf("请输入新的作者名");

    scanf("%s",newWriter);
    strcpy(books[index].name,newName);
    strcpy(books[index].writer ,newWriter);

    printf("%s,%s",books[index].name,books[index].writer);

    int will_delete[]={-1};
    int number=0;

    open_delete_book(will_delete,number,books_number,books);



}


//void modify_book_by_name(int books_number,Book books[]){
//    query_bybookname(books_number,books);
//}
//void modify_book_by_writer(int books_number,Book books[]){
//    query_bywriter(books_number,books);
//}