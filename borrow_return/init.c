//
// Created by 86139 on 2023/5/4.
//

#include "stdio.h"
#include "borrow_return.h"
#include "malloc.h"


FILE * r_file_open(){
    FILE *fp;
    if ((fp = fopen("../borrow_return/return.txt", "a+")) == NULL){
        if ((fp = fopen("borrow_return/return.txt", "a+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}

FILE * b_file_open(){
    FILE *fp;
    if ((fp = fopen("../borrow_return/borrow.txt", "a+")) == NULL){
        if ((fp = fopen("borrow_return/borrow.txt", "a+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}

void put_return(FILE *fp,Return *head){
    Return *p= head;
    for (;  ; ) {
        Return *q=(Return *)malloc(sizeof(Return));
        if ( fscanf(fp,"%s %d %s %s %d %s %s",
                    &q->time,
                    &q->reader.id,
                    &q->reader.name,
                    &q->reader.sex,
                    &q->book.id,
                    &q->book.writer,
                    &q->book.name) ==EOF)
            break;

        q->next=NULL;

        p->next=q;
        p=q;

    }
}

void put_borrow(FILE *fp,Borrow *head){
    Borrow *p= head;

    for (;  ; ) {


    Borrow *q=(Borrow *)malloc(sizeof(Borrow));
   if( fscanf(fp,"%s %d %s %s %d %s %s",
              &q->time,
              &q->reader.id,
              &q->reader.name,
              &q->reader.sex,
              &q->book.id,
              &q->book.writer,
              &q->book.name) == EOF)
       break;

    q->next=NULL;

    p->next=q;
    p=q;
    }


}

