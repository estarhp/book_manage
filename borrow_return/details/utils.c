//
// Created by 86139 on 2023/5/16.
//
#include <stdio.h>
#include <time.h>
#include "string.h"
#include "malloc.h"
#include "../borrow_return.h"


void createTime(char time_str[]) {
    time_t raw_time;
    struct tm* time_info;

    // 获取当前时间戳
    time(&raw_time);

    // 将时间戳转换为本地时间
    time_info = localtime(&raw_time);

    strftime(time_str, 20, "%Y-%m-%d-%H:%M:%S", time_info);  // 使用固定大小的缓冲区

}

void close(Borrow *bhead,Return *rhead){
    for (Borrow *p = bhead,*q = NULL; p!=NULL; q=p,p=p->next) {
        free(q);
    }
    for (Return *p = rhead,*q = NULL; p!=NULL; q=p,p=p->next) {
        free(q);
    }
}

