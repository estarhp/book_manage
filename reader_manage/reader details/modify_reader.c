//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"
#include "unistd.h"
void modify_reader_by_id(int readers_number, Reader  readers[]){
    int index = Search_byreaderid(readers_number,readers);
    if (index == -1){
        printf("没有这个读者哟");
        sleep(2);
        return;
    }
    char newName[14];
    char newSex[5];
    printf("请输入新的姓名：\n");

    fflush(stdin);
    fgets(newName, 14, stdin);

    if (strlen(newName) == 13) {

        printf("你输的也太长了吧！！！！");
        sleep(2);
        return;
    }

    newName[strcspn(newName, "\n")] = '\0';


    printf("请输入读者的性别（男/女）");
    fflush(stdin);

    fgets(newSex, 5, stdin);

    if (strlen(newSex) == 4) {

        printf("你输的也太长了吧！！！！");
        sleep(2);
        return ;
    }

    newSex[strcspn(newSex, "\n")] = '\0';

    if(strcmp(newSex,"男") != 0 && strcmp(newSex,"女") != 0 )
    {
        printf("请输入正确的性别！！！！");
        sleep(2);
        return;
    }
    strcpy(readers[index].name,newName);
    strcpy(readers[index].sex,newSex);

    printf("%s,%s",readers[index].name,readers[index].sex);

    int will_delete[]={-1};
    int number=0;

    open_delete_reader(will_delete,number,readers_number,readers);

    printf("修改完毕");
    sleep(2);




}