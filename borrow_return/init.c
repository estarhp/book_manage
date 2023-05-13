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

void put_return(FILE *fp,Borrow *p){
    for (int i = 0; !feof(fp); ++i) {
        Borrow *q=(Borrow *)malloc(sizeof(Borrow));
        fscanf(fp,"%d %s %s %d %s %s",
               &q->reader.id,
               &q->reader.name,
               &q->reader.sex,
               &q->book.id,
               &q->book.writer,
               &q->book.name);

        q->next=NULL;

        p->next=q;
        p=q;

    }
}

void put_borrow(FILE *fp,Borrow *p){
    Borrow *q=(Borrow *)malloc(sizeof(Borrow));
    fscanf(fp,"%d %s %s %d %s %s",
           &q->reader.id,
           &q->reader.name,
           &q->reader.sex,
           &q->book.id,
           &q->book.writer,
           &q->book.name);

    q->next=NULL;

    p->next=q;
    p=q;


}

