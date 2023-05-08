//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "string.h"
#include "../reader_manage.h"

void add_reader(Reader readers[],int readers_number,FILE *fp){
    rewind(fp);
    Reader addreader;
    printf("请输入要添加的读者名");
    scanf("%s",&addreader.name);
    addreader.id=readers[readers_number-1].id+1;
    fprintf(fp, "%d %s\n", addreader.id, addreader.name);

}