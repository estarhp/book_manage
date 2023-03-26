#include "stdio.h"
//创建图书容器
typedef struct book {
    int id;
    char name[50];
    char writer[20];
} Book;

void add_book();

FILE * file_open();

void put_book(int number,FILE *fp,Book books[]);//初始化图书

int Books_number(FILE *fp);//计算文件中图书的数目

void Menu_book();

void Collect(int books_number,Book *books);

void delete_book();

void modify_book();

void query_book();

void show_book(int books_number,Book *books);

void Main_book_mana(){

    FILE *fp=file_open();

    int books_number=Books_number(fp);//计算图书数量

    Book books[books_number];//创建图书容器

    put_book(books_number,fp,books);//将书本放入容器



    Menu_book();

    Collect(books_number,books);





}

void show_book(int books_number,Book *books){
    for (int i = 0; i < books_number; ++i) {
        printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
    }

}

void query_book(){
    printf("开发中");

}

void modify_book(){
    printf("开发中");

}


void delete_book(){
    printf("开发中");
}

void add_book(){
    printf("开发中");

}

void Collect(int books_number,Book *books){
    int Scanf;
    //收集用户的选择
    scanf("%d",&Scanf);
    //跳入不同模块
    switch (Scanf) {

        case 1:add_book();
            break;
        case 2:delete_book();
            break;
        case 3:modify_book();
            break;
        case 4:query_book();
            break;
        case 5:show_book(books_number,books);
            break;

    }
}

void Menu_book(){

    printf("\n\t##########################欢迎进入图书管理系统##########################\t\n"
           "\n\t                        1->新增图书                        \t\n"
           "\n\t                        2->删除图书                        \t\n"
           "\n\t                        3->修改图书                        \t\n"
           "\n\t                        4->查询图书                        \t\n"
           "\n\t                        5->显示图书                        \t\n"
           "\n\t#######################请数字选择进入########################\t\n"
    );

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


    for (int i = 0; i < number; ++i) {
        fscanf(fp,"%d %s %s",&books[i].id,&books[i].writer,&books[i].name);
    }//从文件读入书本

    fclose(fp);

}

FILE * file_open(){
    FILE *fp;

    if ((fp = fopen("../books.txt", "r")) == NULL){
        if ((fp = fopen("../books.txt", "r")) == NULL){
            printf("文件路径Error!\n");
        }
    }

    return fp;
}





