////
//// Created by Vinci on 2023/4/5.
////
///*
//C语言编程实现控制台上光标的随意移动
//上下左右方向键移动光标
//回车键光标换行
//普通键盘区输入字符
//*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//#define N 1024
//
////定位箭头
//static COORD coord;
//
//void Move(char dir)
//{
//    COORD originCoord = coord;
//    if (dir == 'w' && coord.Y <= 8 && coord.Y > 2)
//    {
//        coord.Y--;
//    }
//    else if (dir == 's' && coord.Y < 8 && coord.Y >= 2)
//    {
//        coord.Y++;
//    }
//    /*else if (dir == '1')
//    {
//        coord.Y = 2;
//    }
//    else if (dir == '2')
//    {
//        coord.Y = 3;
//    }
//    else if (dir == '3')
//    {
//        coord.Y = 4;
//    }*/
//
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), originCoord);
//    printf("   ");
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//    printf("\033[m<==\033[?25l");
//
//}
////\033参数1背景色，参数二字体色
//static char menuContent[8][N] = {
//        {"\033[46;33m********                图书管理系统                ********\033[0m"},
//        {"\033[46;33m##########################欢迎进入##########################\033[0m"},
//        {"\033[46;33m#                        0->谢谢使用                       #\033[0m"},
//        {"\033[46;33m#                        1->图书管理                       #\033[0m"},
//        {"\033[46;33m#                        2->读者管理                       #\033[0m"},
//        {"\033[46;33m#                        3->借还书登记                     #\033[0m"},
//        {"\033[46;33m#                        其他->请重输                      #\033[0m"},
//        {"\033[46;33m#######################请数字选择进入#######################\033[0m"}
//};
//
//void printMenu() {
//    coord.X = 10;//列
//    coord.Y = 2;//行
//    for (int i = coord.Y, j = 0; i <= 9; i++)
//    {
//        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//        coord.Y++;
//        printf("%s\n", menuContent[j++]);
//    }
//
//    coord.X = 20;
//    coord.Y = 2;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//    printf("\033[m<==\033[?25l");
//}
//
//int main()
//{
//    printMenu();
//    while (1)
//    {
//        if (_kbhit())
//        {/*
//C语言编程实现控制台上光标的随意移动
//上下左右方向键移动光标
//回车键光标换行
//普通键盘区输入字符
//*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//#define N 1024
//
////定位箭头
//            static COORD coord;
//
//            void Move(char dir)
//            {
//                COORD originCoord = coord;
//                if (dir == 'w' && coord.Y <= 8 && coord.Y > 2)
//                {
//                    coord.Y--;
//                }
//                else if (dir == 's' && coord.Y < 8 && coord.Y >= 2)
//                {
//                    coord.Y++;
//                }
//                /*else if (dir == '1')
//                {
//                    coord.Y = 2;
//                }
//                else if (dir == '2')
//                {
//                    coord.Y = 3;
//                }
//                else if (dir == '3')
//                {
//                    coord.Y = 4;
//                }*/
//
//                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), originCoord);
//                printf("   ");
//                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//                printf("\033[m<==\033[?25l");
//
//            }
////\033参数1背景色，参数二字体色
//            static char menuContent[8][N] = {
//                    {"\033[46;33m********                图书管理系统                ********\033[0m"},
//                    {"\033[46;33m##########################欢迎进入##########################\033[0m"},
//                    {"\033[46;33m#                        0->谢谢使用                       #\033[0m"},
//                    {"\033[46;33m#                        1->图书管理                       #\033[0m"},
//                    {"\033[46;33m#                        2->读者管理                       #\033[0m"},
//                    {"\033[46;33m#                        3->借还书登记                     #\033[0m"},
//                    {"\033[46;33m#                        其他->请重输                      #\033[0m"},
//                    {"\033[46;33m#######################请数字选择进入#######################\033[0m"}
//            };
//
//            void printMenu() {
//                coord.X = 10;//列
//                coord.Y = 2;//行
//                for (int i = coord.Y, j = 0; i <= 9; i++)
//                {
//                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//                    coord.Y++;
//                    printf("%s\n", menuContent[j++]);
//                }
//
//                coord.X = 20;
//                coord.Y = 2;
//                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//                printf("\033[m<==\033[?25l");
//            }
//
//            int main()
//            {
//                printMenu();
//                while (1)
//                {
//                    if (_kbhit())
//                    {
//                        char Direction = _getch();
//                        if (Direction == 'w' || Direction == 's' || Direction == '1' || Direction == '2' || Direction == '3')
//                        {
//                            Move(Direction);
//                        }
//                    }
//                }
//                return 0;
//            }
//
//            char Direction = _getch();
//            if (Direction == 'w' || Direction == 's' || Direction == '1' || Direction == '2' || Direction == '3')
//            {
//                Move(Direction);
//            }
//        }
//    }
//    return 0;
//}
