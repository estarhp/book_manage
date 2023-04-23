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


//程序入口
void Main_reader_mana(){
    FILE *fp=name_open();

    int readers_number= Readers_number(fp);//获得读者数量

    Reader readers[readers_number];//创建读者容器

    put_reader(readers_number,fp,readers);//将读者信息放入容器
    //???????
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
    file_row = count; //获得行数（人的数量）

    rewind(fp);
    return file_row;
}

FILE * name_open(){
    FILE *fp;

    if ((fp = fopen("../reader_manage/name.txt", "r")) == NULL){
        if ((fp = fopen("reader/name.txt", "r")) == NULL){
            printf("???·??Error!\n");
        }
    }

    return fp;
}

void put_reader(int number,FILE *fp,Reader readers[]) {
    for (int i = 0; i < number; ++i) {
        fscanf(fp,"%s %s %s",&readers[i].id,&readers[i].name,&readers[i].sex);
    }//从文件读入人名

    fclose(fp);

}
//??????????
//void  SearchbyName(long num[], char name[][MAX_LEN],char sex[][5],char book_name[100][30],char writer_name[100][10],int n,int m)
//{
//    int i,j,t=0;//??????
//    char se[MAX_LEN];
//    scanf("%s",&se);
//
//    for(i=0;i<n;i++)
//    {
//        if(strcmp(se,name[i])==0) //?????????????????????????
//        {
//            printf("%ld\t%s\t",num[i],name[i],sex[i]);
//            //??????????,????????????
//            for(j=0;j<m;j++)
//            {
//                printf("%s%s\t", book_name[i][j], writer_name[i][j]);
//            }
//
//            t=1;
//        }
//    }
//    //??????????????
//    if(t==0)
//    {
//        printf("???????!\n");
//    }
//}
