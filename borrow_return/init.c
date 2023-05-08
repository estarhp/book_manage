//
// Created by 86139 on 2023/5/4.
//

#include "stdio.h"
#include "borrow_return.h"


FILE * r_file_open(){
    FILE *fp;
    if ((fp = fopen("../borrow_return/return.txt", "a+")) == NULL){
        if ((fp = fopen("borrow_return/return.txt", "a+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}

FILE * b_file_open(){
    FILE *fp;
    if ((fp = fopen("../borrow_return/borrow.txt", "a+")) == NULL){
        if ((fp = fopen("borrow_return/borrow.txt", "a+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}

void put_return(){

}

void put_borrow(){

}

