#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "book_manage.h"

void Main_book_mana(){

    FILE *fp=file_open();//打开书本文件

    int books_number=Books_number(fp);//计算图书数量

    Book books[books_number];//创建图书容器

    put_book(books_number,fp,books);//将书本放入容器

    Menu_book();

    Collect(books_number,books,fp);

    fclose(fp);//关闭文件

}

void Collect(int books_number,Book books[],FILE *fp){
    int Scanf;
    //收集用户的选择
    scanf("%d",&Scanf);
    //跳入不同模块
    switch (Scanf) {

        case 1:add_book(books,books_number,fp);
            break;
        case 2:delete_book(books_number,books);
            break;
        case 3:modify_book_by_id(books_number,books);
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



}
