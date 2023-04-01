//读者管理模块
//新增读者
//删除
//修改
//查询
//显示
//创建读者信息
#include "stdio.h"
#include "stdlib.h"
# define MAX_LEN 50
typedef struct reader {
    char id[15];
    char name[12];
    char sex[3];
} Reader;

int Readers_number(FILE *fp);
void put_reader(int number,FILE *fp,Reader readers[]);
FILE * name_open();
int Readers_number(FILE *fp);
void  SearchbyName(long num[], char name[][MAX_LEN],char sex[][5],char book_name[100][30],char writer_name[100][10],int n,int m);

void Main_reader_mana(){
    FILE *fp=name_open();

    int readers_number= Readers_number(fp);//计算读者数量

    Reader readers[readers_number];//创建读者容器

    put_reader(readers_number,fp,readers);//将读者放入容器
    //打印读者
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

    if ((fp = fopen("../reader_manage/name.txt", "r")) == NULL){
        if ((fp = fopen("reader/name.txt", "r")) == NULL){
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
//查询读者信息
//void  SearchbyName(long num[], char name[][MAX_LEN],char sex[][5],char book_name[100][30],char writer_name[100][10],int n,int m)
//{
//    int i,j,t=0;//放个标记
//    char se[MAX_LEN];
//    scanf("%s",&se);
//
//    for(i=0;i<n;i++)
//    {
//        if(strcmp(se,name[i])==0) //如果存在则输出姓名，学号，性别
//        {
//            printf("%ld\t%s\t",num[i],name[i],sex[i]);
//            //输出借阅信息,书名及作者名
//            for(j=0;j<m;j++)
//            {
//                printf("%s%s\t", book_name[i][j], writer_name[i][j]);
//            }
//
//            t=1;
//        }
//    }
//    //不存在，则不能借阅
//    if(t==0)
//    {
//        printf("不能借阅!\n");
//    }
//}
