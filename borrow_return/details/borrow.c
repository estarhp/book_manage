//
// Created by 86139 on 2023/5/4.
//
#include "../borrow_return.h"
#include "malloc.h"
#include "string.h"
void showBorrow(Borrow *head){
    for (Borrow *p= head->next; p !=NULL; p= p->next) {
        printf("借书时间：%s 借书人：%d %s %s 所借书：%d %s %s\n",
               p->time,
               p->reader.id,
               p->reader.name,
               p->reader.sex,
               p->book.id,
               p->book.writer,
               p->book.name);
    }
}

void register_borrow(Borrow *head,Book books[],int books_number,Reader readers[],int readers_number,FILE *fp) {
    Borrow *p = head->next;
    while (p->next != NULL)p=p->next;
    Borrow *q=(Borrow *)malloc(sizeof(Borrow));
    int index_reader = Search_byreaderid(readers_number,readers);
    if (index_reader==-1) {
        printf("数据库中没有这位读者的信息，请先添加读者");
        return;
    }
    q->reader = readers[index_reader];
    int index_book = query_byid(books_number,books);
    if (index_book==-1) {
        printf("数据库中没有这本图书的信息，请先添加书本");
        return;
    }
    q->book = books[index_book];
    createTime(q->time);
    q->next = NULL;
    p->next = q;

}
