#include<stdio.h>
#include "stdlib.h"

void  ShowMainMenu(){
    system("cls");

    printf("\n\t##########################欢迎进入##########################\t\n"
                  "\n\t                        1->图书管理                         \t\n"
                  "\n\t                        2->读者管理                         \t\n"
                  "\n\t                        3->借还书登记                       \t\n"
                  "\n\t#######################请数字选择进入########################\t\n"
                  );




}



int main(int argc, char const *argv[])
{   int Scan_number=0;


    ShowMainMenu();



    scanf("%d",&Scan_number);

    return 0;
}
