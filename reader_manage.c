//读者管理模块
//新增读者
//删除
//修改
//查询
//显示
//创建读者信息
# include "stdio.h"
# define MAX-LEN 50
void Main_reader_mana();
void  SearchbyName(long num[], char name[][MAX_LEN],char sex[][5],char book_name[100][30],char writer_name[100][10],int n,int m);

int main()
{
    //void  SearchbyName(long num[], char name[][MAX_LEN],char sex[][5],char book_name[100][30],char writer_name[100][10],int n,int m);

    return 0;
}
void Main_reader_mana(){

}
//查询读者信息
//void  SearchbyName(long num[], char name[][MAX_LEN],char sex[][5],char book_name[100][30],char writer_name[100][10],int n,int m)
//{
//    int i,j,t=0;//放个标记
//    char se[MAX_LEN];
//    scanf("%s",&se);
//
//    for(i=0;i<n;i++)
//    {
//        if(strcmp(se,name[i])==0) //如果存在则输出姓名，学号，性别
//        {
//            printf("%ld\t%s\t",num[i],name[i],sex[i]);
//            //输出借阅信息,书名及作者名
//            for(j=0;j<m;j++)
//            {
//                printf("%s%s\t", book_name[i][j], writer_name[i][j]);
//            }
//
//            t=1;
//        }
//    }
//    //不存在，则不能借阅
//    if(t==0)
//    {
//        printf("不能借阅!\n");
//    }
//}
