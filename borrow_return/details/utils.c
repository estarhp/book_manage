//
// Created by 86139 on 2023/5/16.
//
#include <stdio.h>
#include <time.h>
#include "string.h"
#include "malloc.h"


char* createTime() {
    time_t raw_time;
    struct tm* time_info;

    // 获取当前时间戳
    time(&raw_time);

    // 将时间戳转换为本地时间
    time_info = localtime(&raw_time);

    char* time_str = (char*)malloc(20*sizeof(char));  // 动态内存分配

    strftime(time_str, 20, "%Y-%m-%d-%H:%M:%S", time_info);  // 使用固定大小的缓冲区

    return time_str;
}

