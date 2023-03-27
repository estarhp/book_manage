//读者管理模块
//新增读者
//删除
//修改
//查询
//显示
//创建读者信息
#include "stdio.h"
#include "stdlib.h"
typedef struct reader {
    char id[15];
    char name[12];
    char sex[3];
} Reader;

int Readers_number(FILE *fp);
void put_reader(int number,FILE *fp,Reader readers[]);
FILE * name_open();
int Readers_number(FILE *fp);

void Main_reader_mana(){
    FILE *fp=name_open();

    int readers_number= Readers_number(fp);//计算读者数量

    Reader readers[readers_number];//创建读者容器

    put_reader(readers_number,fp,readers);//将读者放入容器

    for (int i = 0; i < readers_number; ++i) {
        printf("%s %s %s\n",readers[i].id,readers[i].name,readers[i].sex);
    }
}

int Readers_number(FILE *fp) {

    int flag = 0, file_row = 0, count = 0;
    while (!feof(fp)) {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count; //加上最后一行

    rewind(fp);
    return file_row;
}

FILE * name_open(){
    FILE *fp;

    if ((fp = fopen("../name.txt", "r")) == NULL){
        if ((fp = fopen("name.txt", "r")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}

void put_reader(int number,FILE *fp,Reader readers[]) {
    for (int i = 0; i < number; ++i) {
        fscanf(fp,"%s %s %s",&readers[i].id,&readers[i].name,&readers[i].sex);
    }//从文件读入书本

    fclose(fp);

}

