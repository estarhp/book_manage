//
// Created by 86139 on 2023/5/3.
//

#include "stdio.h"
#include "book_manage.h"


int Books_number(FILE *fp) {

    int flag = 0, file_row = 0, count = 0;
    while (!feof(fp)) {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count; //加上最后一行

    rewind(fp);
    return file_row;
}

void put_book(int number,FILE *fp,Book books[]){


    for (int i = 0; i<number ; i++) {
        fscanf(fp,"%d %s %s",&books[i].id,&books[i].writer,&books[i].name);
    }//从文件读入书本

}

FILE * file_open(){
    FILE *fp;
    if ((fp = fopen("../book_manage/books.txt", "a+")) == NULL){
        if ((fp = fopen("book_manage/books.txt", "a+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}
