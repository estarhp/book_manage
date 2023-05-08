//
// Created by Vinci on 2023/5/8.
//
#include "string.h"
#include "stdio.h"
#include "../reader_manage.h"

void delete_reader(int readers_number,Reader readers[]){
    int delete_input;
    printf("1 -> 通过id删除\n"
           "2 -> 通过名字删除\n"
    );
    scanf("%d",&delete_input);
    switch (delete_input) {
        case 1:
            delete_reader_by_id(readers_number,readers);
            break;
        case 2:
            delete_reader_by_name(readers_number,readers);
            break;

    }
}
void open_delete_reader(int will_delete[],int number,int readers_number,Reader readers[]){
    FILE *fp;
    if ((fp = fopen("../reader_manage/name.txt", "w+")) == NULL){
        if ((fp = fopen("reader_manage/name.txt", "w+")) == NULL){
            printf("文件路径Error!\n");
        }
    }
    printf("%p",fp);

    rewind(fp);
    for (int j = 0; j < readers_number; ++j) {
        int flag=1;
        for (int k = 0; k < number; ++k) {
            if(will_delete[k]==j) flag=0;
        }
        if(flag)
            fprintf(fp,"%d %s %s\n",readers[j].id,readers[j].name);
    }
    fclose(fp);

}
void delete_reader_by_id(int readers_number,Reader readers[]){
    int number=0;
    int will_delete[10];
    int id;
    printf("请输入读者的id");
    scanf("%d",&id);

    for (int i = 0; i < readers_number; ++i) {
        if(readers[i].id==id){
            will_delete[number]=i;
            number++;
        }
    }
    open_delete_reader(will_delete,number,readers_number,readers);
}
void delete_reader_by_name(int readers_number,Reader readers[]){
    int number=0;
    int will_delete[10];
    char readername[20];
    printf("请输入读者的名字");
    scanf("%s",readername);

    for (int i = 0; i < readers_number; ++i) {
        if(strcmp(readername,readers[i].name)==0){
            will_delete[number]=i;
            number++;
        }
    }
    open_delete_reader(will_delete,number,readers_number,readers);

}