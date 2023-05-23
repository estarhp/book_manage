//
// Created by Vinci on 2023/5/8.
//
#include "string.h"
#include "stdio.h"
#include "../reader_manage.h"
#include "windows.h"
#include "unistd.h"
void delete_reader(int readers_number,Reader readers[]){
    system("cls");
    int delete_input;

    gotoxy_reader(2000, 5);
    printf("1 -> 通过id删除\n");
    gotoxy_reader(2000, 6);
    printf("2 -> 通过名字删除\n");
    gotoxy_reader(2000, 7);
    printf("请输入你的选择：（数字）");
    scanf("%d",&delete_input);

    switch (delete_input) {
        case 1:
            delete_reader_by_id(readers_number,readers);
            break;
        case 2:
            delete_reader_by_name(readers_number,readers);
            break;

    }
    sleep(2);
    system("cls");
}
void open_delete_reader(int will_delete[],int number,int readers_number,Reader readers[]){
    FILE *fp;
    if ((fp = fopen("../reader_manage/name.txt", "w+")) == NULL){
        if ((fp = fopen("reader_manage/name.txt", "w+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    rewind(fp);
    for (int j = 0; j < readers_number; ++j) {
        int flag=1;
        for (int k = 0; k < number; ++k) {
            if(will_delete[k]==j) flag=0;
        }
        if(flag)
            fprintf(fp,"%d %s %s\n",readers[j].id,readers[j].name,readers[j].sex);
    }
    fclose(fp);

}
void delete_reader_by_id(int readers_number,Reader readers[]){
    int number=0;
    int will_delete[10];
    int id;
    printf("请输入读者的id：\n");
    scanf("%d",&id);

    for (int i = 0; i < readers_number; ++i) {
        if(readers[i].id==id){
            will_delete[number]=i;
            number++;
        }
    }
    if(number == 0 ){
        printf("没有找到满足要求的读者！\n");
        sleep(2);
        return;
    }
    open_delete_reader(will_delete,number,readers_number,readers);
    printf("删除成功！");

}
void delete_reader_by_name(int readers_number,Reader readers[]){
    int number=0;
    int will_delete[10];
    char readername[20];
    printf("请输入读者的名字：\n");
    scanf("%s",readername);

    for (int i = 0; i < readers_number; ++i) {
        if(strcmp(readername,readers[i].name)==0){
            will_delete[number]=i;
            number++;
        }
    }
    if(number == 0 ){
        printf("没有找到满足要求的读者！");
        sleep(2);
        return;
    }
    open_delete_reader(will_delete,number,readers_number,readers);
    printf("删除成功！");


}