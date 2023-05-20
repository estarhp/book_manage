
#include <stdio.h>
#include <windows.h>
#include "book_manage/book_manage.h"
#include "reader_manage/reader_manage.h"
#include "borrow_return/borrow_return.h"
#include "unistd.h"
void Main_Muen();
void Collect_operation();

//定位箭头
int wherex()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.X + 1);

}

//获取光标的位置y

int wherey()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.Y + 1);

}

//设置光标的位置

void gotoxy(int x, int y)

{

    COORD c;

    c.X = x - 1;

    c.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
void Main_Muen()
{

    setbuf(stdout,0);

    int x, y;

    //int select;

    gotoxy(25, 5);

    printf("********图书管理系统********");

    gotoxy(15, 8);

    printf("*********************主菜单*********************");

    gotoxy(15, 9);

    printf("*                  0->感谢使用系统（自动关闭） *");

    gotoxy(15, 10);

    printf("*                  1->图书管理                 *");

    gotoxy(15, 11);

    printf("*                  2->读者管理                 *");

    gotoxy(15, 12);

    printf("*                  3->借还书登记               *");

    gotoxy(15, 13);

    printf("*                  其他->请重输                *");
    gotoxy(15, 14);

    printf("***********************************************");

    gotoxy(28, 16);



    printf("请输入你的选择(数字):[ ]");


    x = wherex();

    y = wherey();

    gotoxy(x - 2, y);

}
int main()

{
    Main_Muen();
    Collect_operation();
    return 0;

}
void Collect_operation() {
    system("cls");
    Main_Muen();
    int Scan_number = 0;
    int will_reload;

    //收集用户的选择
    scanf("%d", &Scan_number);
    //跳入不同模块
    //getchar();
    while(Scan_number) {
        switch (Scan_number) {
            case 0:
                printf("感谢使用该系统（自动关闭）！！！");
                break;
            case 1:
               will_reload = Main_book_mana();
                if (will_reload == 1){
                    system("cls");
                    Main_book_mana();
                }
                break;
            case 2:
                will_reload = Main_reader_mana();
                if (will_reload == 1){
                    system("cls");
                    Main_reader_mana();
                }
                break;
            case 3:
                Main_br_mana();
                break;
            default:
                printf("输入错误，请重输");
                break;

                }


            system("cls");
            Main_Muen();
            //getchar();//从控件获取字符而无需回显;
            scanf("%d", &Scan_number);
            sleep(2);




        }
    }
//hhh