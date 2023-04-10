#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "book_manage/book_manage.h"
#include "reader_manage/reader_manage.h"
#include "borrow_return/borrow_return.h"
#define N 1024
void Collect_operation();
void printMenu();
void Move(char dir);
//定位箭头
static COORD coord;
void Move(char dir)
{
    COORD originCoord = coord;
    if (dir == 'w' && coord.Y <= 6&& coord.Y > 2)
    {
        coord.Y--;
    }
    else if (dir == 's' && coord.Y < 6 && coord.Y >= 2)
    {
        coord.Y++;
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), originCoord);
    printf("   ");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("==>");

}
static char menuContent[8][N] = {
        {"********                图书管理系统                ********"},
        {"##########################欢迎进入##########################"},
        {"#                        0->谢谢使用                       #"},
        {"#                        1->图书管理                       #"},
        {"#                        2->读者管理                       #"},
        {"#                        3->借还书登记                     #"},
        {"#                        其他->请重输                      #"},
        {"#######################请选择数字进入#######################"}
};
void printMenu() {
    //system("cls")
    coord.X = 24;//列
    coord.Y = 0;//行
    for (int i = coord.Y, j = 0; i <= 9; i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        coord.Y++;
        printf("%s\n", menuContent[j++]);
    }

    coord.X = 20;
    coord.Y = 2;//行数从哪儿开始
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("==>");
}



int main(int argc, char const *argv[])
{
    //打印窗口
    //ShowMainMenu();
   //收集输入的数字


    printMenu();




    while (1)
    {
        if (_kbhit())
        {
            char Direction = _getch();
            if (Direction == 'w' || Direction == 's' || Direction == '1' || Direction == '2' || Direction == '3')
            {
                Move(Direction);
            }
        }
    }
    Collect_operation();
    return 0;


}

/*void  ShowMainMenu() {

    printf("\n\t********                图书管理系统                ********\t\n");
    printf(
            "\n\t##########################欢迎进入##########################\t"
            "\n\t#                        0->谢谢使用                       #\t"
            "\n\t#                        1->图书管理                       #\t"
            "\n\t#                        2->读者管理                       #\t"
            "\n\t#                        3->借还书登记                     #\t"
            "\n\t#                        其他->请重输                      #\t"
            "\n\t#######################请数字选择进入########################\t"
    );
}*/
void Collect_operation(){
    int Scan_number=0;

    //收集用户的选择
    scanf("%d",&Scan_number);
   //跳入不同模块
    switch (Scan_number) {
        case 0:
            printf("谢谢使用！");
            break;
        case 1:Main_book_mana();
            break;
        case 2:Main_reader_mana();
            break;
        case 3:Main_br_mana();
            break;
        default:
            printf("输入错误，请重输");
            break;

    }
}