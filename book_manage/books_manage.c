#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
//创建图书容器
typedef struct book {
    int id;
    char name[50];
    char writer[20];
} Book;
void add_book(Book books[],int books_number,FILE *fp);
FILE * file_open();
void put_book(int number,FILE *fp,Book books[]);//初始化图书
int Books_number(FILE *fp);//计算文件中图书的数目
void Menu_book();
void Collect(int books_number,Book books[],FILE *fp);//收集用户的选择
void delete_book();
void modify_book();
void query_book(int books_number,Book books[]);//查询图书
void show_book(int books_number,Book *books);//展示图书
void query_byid(int books_number,Book books[]);
void query_bywriter(int books_number,Book books[]);
void query_bybookname(int books_number,Book books[]);
int wherex_book();
int wherey_book();
void gotoxy_book(int x, int y);


void Main_book_mana(){

    FILE *fp=file_open();//打开书本文件

    int books_number=Books_number(fp);//计算图书数量

    Book books[books_number];//创建图书容器

    put_book(books_number,fp,books);//将书本放入容器

    Menu_book();

    Collect(books_number,books,fp);

    fclose(fp);//关闭文件



}

void show_book(int books_number,Book *books){
    int start=0,end=0;
    printf("请输入要看的书本的序数范围：\n从序数__开始：");
    scanf("%d",&start);
    printf("从序数__结束：");
    scanf("%d",&end);
    printf("以下为书本序数在%d~%d范围之内的图书：\n",start,end);

    for (int i = start; i <= end; ++i) {
        printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
    }

}

void query_book(int books_number,Book books[]){
    int select_mode=0;
    printf("\n\t                        1->通过id                        \t\n"
           "\n\t                        2->通过作者                        \t\n"
           "\n\t                        3->通过书名                        \t\n"
    );
    scanf("%d",&select_mode);
    switch (select_mode) {
        case 1:query_byid(books_number,books);
            break;
        case 2:query_bywriter(books_number,books);
            break;
        case 3:query_bybookname(books_number,books);

    }

}

void query_byid(int books_number,Book books[]){
    int id;
    printf("请输入书本的id");
    scanf("%d",&id);
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < books_number; ++i) {
        if(books[i].id==id){

            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }
    }
}

void query_bywriter(int books_number,Book books[]){
    char writer[50];
    printf("请输入书本的作者");
    scanf("%s",&writer);
    printf("以下是匹配的查询结果：\n");
    for (int i = 0; i < books_number; ++i) {
        if(strcmp(writer,books[i].writer)==0){

            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }
}

void query_bybookname(int books_number,Book books[]){
    char bookname[20];
    printf("请输入书本的书名");
    scanf("%s",&bookname);
    printf("以下是匹配的查询结果：\n");

    for (int i = 0; i < books_number; ++i) {
        if(strcmp(bookname,books[i].name)==0){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }

}

void modify_book(){
    printf("开发中");

}


void delete_book(){
    printf("开发中");
}

void add_book(Book books[],int books_number,FILE *fp){
    rewind(fp);
    Book addbook;
    printf("请输入要添加的书名");
    scanf("%s",&addbook.name);
    printf("请输入要添加图书的作者");
    scanf("%s",&addbook.writer);
    addbook.id=books[books_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addbook.id, addbook.writer, addbook.name);

}

void Collect(int books_number,Book books[],FILE *fp){
    int Scanf;
    //收集用户的选择
    scanf("%d",&Scanf);
    //跳入不同模块
    switch (Scanf) {

        case 1:add_book(books,books_number,fp);
            break;
        case 2:delete_book();
            break;
        case 3:modify_book();
            break;
        case 4:query_book(books_number,books);
            break;
        case 5:show_book(books_number,books);
            break;

    }
}
int wherex_book()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.X + 1);

}

//获取光标的位置y

int wherey_book()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.Y + 1);

}

//设置光标的位置

void gotoxy_book(int x, int y)

{

    COORD c;

    c.X = x - 1;

    c.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}


void Menu_book(){



    setbuf(stdout,0);//缓冲

    int x, y;

    //int select;

    gotoxy_book(24, 5);

    printf("********欢迎图书管理系统********");

    gotoxy_book(15, 8);

    printf("*********************主菜单*********************");

    gotoxy_book(15, 9);

    printf("*                  1->新增图书                 *");

    gotoxy_book(15, 10);

    printf("*                  2->删除图书                 *");

    gotoxy_book(15, 11);

    printf("*                  3->修改图书                 *");

    gotoxy_book(15, 12);

    printf("*                  4->查询图书                 *");

    gotoxy_book(15, 13);

    printf("*                  5->显示图书                 *");

    gotoxy_book(15, 14);

    printf("************************************************");

    gotoxy_book(28, 16);

    printf("请输入你的选择(数字):[ ]");

    x = wherex_book();

    y = wherey_book();

    gotoxy_book(x - 2, y);

    //scanf_s("%d", &select);
    //Collect_operation();


    void Collect(int books_number,Book books[],FILE *fp);
    system("pause");

    //return 0;*/

}

int Books_number(FILE *fp) {

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

void put_book(int number,FILE *fp,Book books[]){


    for (int i = 0; i<number ; i++) {
        fscanf(fp,"%d %s %s",&books[i].id,&books[i].writer,&books[i].name);
    }//从文件读入书本



}

FILE * file_open(){
    FILE *fp;
    if ((fp = fopen("../book_manage/books.txt", "a+")) == NULL){
        if ((fp = fopen("book_manage/books.txt", "a+")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}





