//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "string.h"
#include "../reader_manage.h"
#include "windows.h"
#include "unistd.h"
void search_reader(int readers_number,Reader readers[])
{
    fflush(stdin);
    system("cls");
    int select_mode=0;
    printf("\n\t                        1->通过id                         \t\n");
    printf("\n\t                        2->通过读者                        \t\n");
    printf("\n\t                      请输入你的选择（数字）：                \n\t");

    int right = scanf("%d",&select_mode);
    if (right  == 0){
        printf("输入错误！！");
        sleep(2);
        system("cls");
        return;
    }
    switch (select_mode) {
        case 1:
            Search_byreaderid(readers_number,readers);
            break;
        case 2:Search_byreadername(readers_number,readers);


    }
    sleep(2);
    system("cls");


}
int Search_byreaderid(int readers_number,Reader readers[])
{
    int id;
    printf("请输入读者的id:\n");
    scanf("%d",&id);
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < readers_number; ++i) {
        if(readers[i].id==id){
            printf("%d %s %s\n",readers[i].id,readers[i].sex,readers[i].name);
            return i;
        }

    }
    printf("无(没有找到满足条件的读者)\n");
    return -1;



}
void Search_byreadername(int readers_number,Reader readers[])
{
    char readername[14];
    int flag = 1;
    printf("请输入读者的姓名:\n");
    fflush(stdin);
    fgets(readername, 14, stdin);

    if (strlen(readername) == 13) {

        printf("你输的也太长了吧！！！！");
        sleep(2);
        return;
    }

    readername[strcspn(readername, "\n")] = '\0';
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < readers_number; ++i) {
        if(strcmp(readername,readers[i].name)==0){

            printf("%d %s %s\n",readers[i].id,readers[i].sex,readers[i].name);
            flag = 0;
        }



    }
    if(flag)
        printf("无(没有找到满足条件的读者)\n");
}