#ifndef UNTITLED_READER_MANAGE_H
#define UNTITLED_READER_MANAGE_H
#include "stdio.h"
typedef struct reader {
    int id;
    char name[12];
    char sex[3];
} Reader;
int Main_reader_mana();
int Readers_number(FILE *fp);
void put_reader(int number,FILE *fp,Reader readers[]);//初始化
FILE * name_open();
void Menu_reader();
int Collect_reader(int readers_number,Reader readers[],FILE *fp);//收集用户的选择
int Readers_number(FILE *fp);
void show_reader(int readers_number,Reader *readers);//展示读者信息
void search_reader(int readers_number,Reader readers[]);//查询读者信息
int Search_byreaderid(int readers_number,Reader readers[]);//通过id
void Search_byreadername(int readers_number,Reader readers[]);//通过读者名字
void delete_reader(int readers_number,Reader readers[]);//删除
void open_delete_reader(int will_delete[],int number,int readers_number,Reader books[]);
void delete_reader_by_id(int readers_number,Reader readers[]);
void delete_reader_by_name(int readers_number,Reader readers[]);
void modify_reader_by_id(int readers_number,Reader readers[]);
int add_reader(Reader readers[],int readers_number,FILE *fp);//新增
int wherex_reader();
int wherey_reader();
void gotoxy_reader(int x, int y);
//程序入口
#endif //UNTITLED_READER_MANAGE_H
