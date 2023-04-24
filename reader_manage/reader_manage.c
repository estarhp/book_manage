#include "stdio.h"
#include "stdlib.h"
#include "string.h"
# define MAX_LEN 50
typedef struct reader {
    char id[15];
    char name[12];
    char sex[3];
} Reader;

int Readers_number(FILE *fp);
void put_reader(int number,FILE *fp,Reader readers[]);//初始化
FILE * name_open();
void Menu_reader();
void Collect_reader(int readers_number,Reader readers[],FILE *fp);//收集用户的选择
int Readers_number(FILE *fp);
void query_reader(int readers_number,Reader readers[]);//查询读者
void show_reader(int readers_number,Reader *readers);//展示读者信息
void Search_by_id(int readers_number,Reader readers[]);//通过id
void Search_by_name(int readers_number,Reader readers[]);//通过读者名字
void delete_reader();//删除
void modify_reader();//修改
void add_reader(Reader readers[],int readers_number,FILE *fp);//新增
//程序入口
void Main_reader_mana(){
    FILE *fp=name_open();

    int readers_number= Readers_number(fp);//获得读者数量

    Reader readers[readers_number];//创建读者容器

    put_reader(readers_number,fp,readers);//将读者信息放入容器
    //???????
//    for (int i = 0; i < readers_number; ++i) {
//        printf("%s %s %s\n",readers[i].id,readers[i].name,readers[i].sex);
//    }2
    Menu_reader();

    Collect_reader(readers_number,readers,fp);

    fclose(fp);//关闭文件

}
void show_reader(int readers_number,Reader readers[])
{
    int start=0,end=0;
    printf("请输入要查询的读者的序数范围：\n从序数__开始：");
    scanf("%d",&start);
    printf("从序数__结束：");
    scanf("%d",&end);
    printf("以下为读者序数在%d~%d范围之内的读者：\n",start,end);

    for (int i = start; i <= end; ++i) {
        printf("%d %s %s\n",readers[i].id,readers[i].name,readers[i].sex);
    }
}
void query_reader(int readers_number,Reader readers[])
{

    int select_mode=0;
    printf("\n\t                        1->通过id                         \t\n");
    printf("\n\t                        2->通过作者                        \t\n");
    printf("\n\t                        3->通过书名                        \t\n");
    printf("\n\t                      请输入你的选择（数字）：                \n\t");

    scanf("%d",&select_mode);
    switch (select_mode) {
        case 1:
            Search_by_id(readers_number,readers);
            break;
        case 2:Search_by_name(readers_number,readers);


    }

}
void Search_by_id(int readers_number,Reader readers[])
{
    char id[40];
    printf("请输入读者的id");
    scanf("%d",&id);
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < readers_number; ++i) {
        if(readers[i].id == id){

            printf("%d %s %s ",readers[i].id,readers[i].name,readers[i].sex);
        }
    }

}
void Search_by_name(int readers_number,Reader readers[])
{
    char name[50];
    printf("请输入读者的姓名");
    scanf("%s",&name);
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < readers_number; ++i) {
        if(strcmp(name,readers[i].name)==0){

            printf("%d %s %s ",readers[i].id,readers[i].sex,readers[i].name);
        }

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
void Collect_reader(int readers_number,Reader readers[],FILE *fp){
    int Scanf;
    //收集用户的选择
    scanf("%d",&Scanf);
    //跳入不同模块
    switch (Scanf) {

        case 1:add_reader(readers,readers_number,fp);
            break;
        case 2:delete_reader();
            break;
        case 3:modify_reader();
            break;
        case 4:query_reader(readers_number,readers);
            break;
        case 5:show_reader(readers_number,readers);
            break;

    }
}
void Menu_reader(){


    //system("cls");

    //int select;
    //printf("hhhhhhh");
    printf("\n*******************读者管理系统******************\t\n");
    printf("\n*********************主菜单*********************\t\n");
    printf("\n*                  1->新增读者                 *\t\n");
    printf("\n*                  2->删除读者                 *\t\n");
    printf("\n*                  3->修改读者                 *\t\n");
    printf("\n*                  4->查询读者                 *\t\n");
    printf("\n*                  5->显示读者                 *\t\n");
    printf("\n***********************************************\t\n");
    printf("\n请输入你的选择(数字):\t\n");



    //scanf_s("%d", &select);
    //Collect_operation();


    void Collect_reader(int readers_number,Reader readers[],FILE *fp);
    system("pause");

    //return 0;*/

}
