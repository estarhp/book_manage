//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"
#include "unistd.h"

int add_reader(Reader readers[],int readers_number,FILE *fp){
    fflush(stdin);
    rewind(fp);
    Reader addreader;
    printf("请输入要添加的读者名：\n");
    fgets(addreader.name, 12, stdin);

    if (strlen(addreader.name) == 11) {

        printf("你输的也太长了吧！！！！");
        sleep(2);
        return -1;
    }

    addreader.name[strcspn(addreader.name, "\n")] = '\0';

    printf("请输入读者的性别（男/女）");

    fgets(addreader.sex, 5, stdin);

    if (strlen(addreader.sex) == 4) {

        printf("你输的也太长了吧！！！！");
        sleep(2);
        return -1;
    }

    addreader.sex[strcspn(addreader.sex, "\n")] = '\0';
    if(strcmp(addreader.sex,"男") !=0 && strcmp(addreader.sex , "女") !=0 ){
        printf("输入了错误的性别!!!!");
        sleep(2);
        return -1;
    }
    addreader.id=readers[readers_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addreader.id, addreader.name,addreader.sex);

    printf("您已成功添加新的读者!");
    sleep(2);

    return 1;

}