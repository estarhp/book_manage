//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"
void modify_reader_by_id(int readers_number, Reader  readers[]){
    int index = Search_byreaderid(readers_number,readers);
    if (index == -1){
        printf("没有这个读者哟");
        return;
    }
    char newName[12];
    char newSex[3];
    printf("请输入新的书名：\n");

    scanf("%s",newName);

    printf("请输入新的性别(选填男女)：\n");

    scanf("%s",newSex);

    if(strcmp(newSex,"男") != 0 && strcmp(newSex,"男") != 0 )
    {
        printf("请输入正确的性别！！！！");
        return;
    }
    strcpy(readers[index].name,newName);
    strcpy(readers[index].sex,newSex);

    printf("%s,%s",readers[index].name,readers[index].sex);

    int will_delete[]={-1};
    int number=0;

    open_delete_reader(will_delete,number,readers_number,readers);



}