//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "windows.h"
#include "unistd.h"
void show_reader(int readers_number,Reader *readers){
    system("cls");
    int start=0,end=0;
    printf("请输入要看的读者的序数范围：\n从序数(大于等于1)__开始：\n");
    scanf("%d",&start);
    printf("从序数(小于等于%d)__结束：\n",readers_number);
    scanf("%d",&end);


    if (start>end||end>readers_number||start<=0){
        printf("输入数据错误!!!");
        sleep(2);
        system("cls");
        return;
    }
    printf("以下为读者序数在%d~%d范围之内的读者：\n",start,end);


    for (int i = start-1; i < end; ++i) {
        printf("%d %s\n",readers[i].id,readers[i].name);
    }

    printf("5s后自动退出");

    sleep(5);
    system("cls");


}

