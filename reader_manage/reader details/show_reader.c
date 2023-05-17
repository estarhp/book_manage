//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "string.h"
#include "../reader_manage.h"
void show_reader(int readers_number,Reader *readers){
    int start=0,end=0;
    printf("请输入要看的读者的序数范围：\n从序数__开始：");
    scanf("%d",&start);
    printf("从序数__结束：");
    scanf("%d",&end);


    if (start<end||end>=readers_number||start<0){
        printf("输入数据错误");
        return;
    }
    printf("以下为读者序数在%d~%d范围之内的读者：\n",start,end);


    for (int i = start; i <= end; ++i) {
        printf("%d %s\n",readers[i].id,readers[i].name);
    }

}

