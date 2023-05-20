//
// Created by 86139 on 2023/5/3.
//
#include "stdio.h"
#include "../book_manage.h"
#include "windows.h"
#include "unistd.h"
void show_book(int books_number,Book *books){
    system("cls");
    int start=0,end=0;
    printf("请输入要看的书本的序数范围：\n从序数(大于等于1)__开始：\n");
    scanf("%d",&start);
    printf("从序数(小于等于%d)__结束：\n",books_number);
    scanf("%d",&end);

    if (start>end||end>books_number||start<=0){
        printf("输入数据错误!!!");
        sleep(2);
        system("cls");
        return;
    }

    printf("以下为书本序数在%d~%d范围之内的图书：\n",start,end);

    for (int i = start-1; i < end; ++i) {
        printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
    }

    printf("5s后自动退出");

    sleep(5);
    system("cls");



}
