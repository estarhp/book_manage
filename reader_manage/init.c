//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "reader_manage.h"

int Readers_number(FILE *fp) {

    int flag = 0, file_row = 0, count = 0;
    while (!feof(fp)) {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count; //获得行数（人的数量）

    rewind(fp);
    return file_row;
}

FILE * name_open(){
    FILE *fp;

    if ((fp = fopen("../reader_manage/name.txt", "r")) == NULL){
        if ((fp = fopen("reader/name.txt", "r")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}

void put_reader(int number,FILE *fp,Reader readers[]) {
    for (int i = 0; i < number; ++i) {
        fscanf(fp,"%s %s %s",&readers[i].id,&readers[i].name,&readers[i].sex);
    }//从文件读入人名

    fclose(fp);

}