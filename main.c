#include<stdio.h>
#include "stdlib.h"
#include "book_manage.h"
#include "reader_manage.h"
#include "borrow_return.h"


void  ShowMainMenu();

void Collect_operation();

int main(int argc, char const *argv[])
{
    //打印窗口
    ShowMainMenu();
   //收集输入的数字
    Collect_operation();




    return 0;
}


void  ShowMainMenu(){
    system("cls");

    printf("\n\t##########################欢迎进入##########################\t\n"
           "\n\t                        1->图书管理                         \t\n"
           "\n\t                        2->读者管理                         \t\n"
           "\n\t                        3->借还书登记                       \t\n"
           "\n\t#######################请数字选择进入########################\t\n"
    );




}
void Collect_operation(){
    int Scan_number=0;

    //收集用户的选择
    scanf("%d",&Scan_number);
   //跳入不同模块
    switch (Scan_number) {

        case 1:Main_book_mana();
            break;
        case 2:Main_reader_mana();
            break;
        case 3:Main_br_mana();
            break;

    }
}