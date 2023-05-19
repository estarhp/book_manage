//
// Created by 86139 on 2023/5/4.
//

#include "../borrow_return.h"
#include "malloc.h"
#include "unistd.h"
#include "string.h"
void showReturn(Return *head){
    for (Return *p= head->next; p!=NULL; p= p->next) {


        printf("还书时间：%s 还书人：%d %s %s 所还书：%d %s %s\n",
               p->time,
               p->reader.id,
               p->reader.name,
               p->reader.sex,
               p->book.id,
               p->book.writer,
               p->book.name);
    }
    sleep(2);
    system("cls");
}

void register_return(Return *head,Book books[],int books_number,Reader readers[],int readers_number,FILE *fp){

    Return *p = head->next;
    while (p->next != NULL)p=p->next;

    Return *q=(Return *)malloc(sizeof(Return));


    int index_reader = Search_byreaderid(readers_number,readers);

    q->reader = readers[index_reader];

    int index_book = query_byid(books_number,books);

    q->book = books[index_book];

    createTime(q->time);

    q->next = NULL;

    p->next = q;



    fprintf(fp,"%s %d %s %s %d %s %s\n",q->time,
            q->reader.id,
            q->reader.name,
            q->reader.sex,
            q->book.id,
            q->book.writer,
            q->book.name);

}
