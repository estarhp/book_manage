//
// Created by 86139 on 2023/5/4.
//
#include "../borrow_return.h"
#include "malloc.h"
#include "string.h"
void showBorrow(Borrow *head){
    for (Borrow *p= head->next; p !=NULL; p= p->next) {
        printf("%s %d %s %s %d %s %s\n",
               p->time,
               p->reader.id,
               p->reader.name,
               p->reader.sex,
               p->book.id,
               p->book.writer,
               p->book.name);
    }
}

void register_borrow(Borrow *head,Book books[],int books_number,Reader readers[],int readers_number) {
    Borrow *p = head->next;
    while (p->next != NULL)p=p->next;
    Borrow *q=(Borrow *)malloc(sizeof(Borrow));
    int index_reader = Search_byreaderid(readers_number,readers);
    q->reader = readers[index_reader];
    int index_book = query_byid(books_number,books);
    q->book = books[index_book];
    createTime(q->time);
    q->next = NULL;
    p->next = q;

}
