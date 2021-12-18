#include "user.h"
#include "client.h"
#include "ddl.h"
// #include "cli_user.c"
#define MAXN 1024
char sen[MAXN],rev[MAXN];
void cls()
{
    system("cls");
    for(int i=1;i<=5;i++)puts("");
    return ;
}
int main(int argc, char* argv[])
{
    cli_init(argv[1]);
    int choice=0;
    cls();
    puts("请输入您的选择(输入选项的数字):\n1.注册\n2.登录\n");
    scanf("%d",&choice);
    cls();
    if(choice==1)USER_REG();
    else USER_LOG();
    cls();
/*********************/
    while(1)
    {
        puts("请选择您要进行的操作：");
        puts("1.查看目前的DDL");
        puts("2.插入DDL");
        puts("3.删除DDL");
        puts("4.导出DDL");
        puts("5.退出系统");
        int res=0;
        scanf("%d",&res);
        if(res==1)
        {
            SORT();
            LIST_DDL();
            system("pause");
        }
        if(res==2)
        {
            INSERT_DDL();
            SORT();
        }
        if(res==3)
        {
            SORT();
            LIST_DDL();
            DEL();
        }
        if(res==4)
        {
            SORT();
            LIST_DDL();
            SEND_OUT();
        }
        if(res==5)
        {
            break;
        }
        cls();
    }
/*********************/
    cli_close();
    return 0; 
}