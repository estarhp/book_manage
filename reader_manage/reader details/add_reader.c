//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"

void add_reader(Reader readers[],int readers_number,FILE *fp){
    rewind(fp);
    Reader addreader;
    printf("请输入要添加的读者名：\n");
    scanf("%s",&addreader.name);
    printf("请输入读者的性别（男/女）");
    scanf("%s",&addreader.sex);
    if(strcmp(addreader.sex,"男") !=0 && strcmp(addreader.sex , "女") !=0 ){
        printf("输入了错误的性别!!!!");
        return;
    }
    addreader.id=readers[readers_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addreader.id, addreader.name,addreader.sex);
    printf("您已成功添加新的读者!");

}