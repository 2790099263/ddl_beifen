#include "user.h"
#include "color.h"
#define MAX_LENGTH 1024
#define MID_LENGTH 512
#define SML_LENGTH 128
char buffer_get[MAX_LENGTH];
int user_number=0,now_number=0;
struct user{
    char name[SML_LENGTH];
    char key[SML_LENGTH];
    char mail[SML_LENGTH];
}user_msg[MID_LENGTH];
FILE *f1,*f2;
void user_init(int i,char *user_name,char *user_key,char *user_mail)
{
    strcpy(user_msg[i].name,user_name);
    strcpy(user_msg[i].key,user_key);
    strcpy(user_msg[i].mail,user_mail);
    return ;
}
void user_cun()
{
    puts("正在读取存档.....");
    
    f1=fopen("user.txt","r");
    if(NULL==f1)
    {
        puts("Fail to open the file!");
        exit(0);
    }
    fscanf(f1,"%d",&user_number);
    for(int i=1;i<=user_number;i++)
        fscanf(f1,"%s %s %s"
        ,&user_msg[i].name
        ,&user_msg[i].key
        ,&user_msg[i].mail);
    puts("存档读取完成！");
}
void output_cun()
{
    f2=fopen("user.txt","w");
    fprintf(f2,"%d\n",user_number);
    for(int i=1;i<=user_number;i++)
        fprintf(f2,"%s %s %s\n"
        ,user_msg[i].name
        ,user_msg[i].key
        ,user_msg[i].mail);
}
int kmp(char *s1,char *s2)
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(len1!=len2)return 0;
    for(int i=0;i<len1;i++)
        if(s1[i]!=s2[i])return 0;
    return 1;
}
void user_debug()
{
    puts("********Debug*****start*************");
    printf("%d\n",user_number);
    for(int i=1;i<=user_number;i++)
        printf(f1,"%s %s %s\n"
        ,user_msg[i].name
        ,user_msg[i].key
        ,user_msg[i].mail);
    puts("********Debug*****end***************");
    return ;
}
//register a new user
void register_user()
{
    put_col("请输入您的用户名：",6,0);
    char user_name[MAX_LENGTH];
    scanf("%s",&user_name);
    user_number++;
    put_col("请输入您的密码：",6,0);
    char user_key[MAX_LENGTH],user_key2[MAX_LENGTH];
    scanf("%s",&user_key);
    flag2:
    put_col("请再次输入密码：",6,0);
    scanf("%s",&user_key2);
    if(kmp(user_key,user_key2)==0)
    {
        put_col("您输入的密码错误",4,0);
        goto flag2;
    }
    char user_mail[MAX_LENGTH];
    put_col("请输入您的邮箱：",6,0);
    scanf("%s",&user_mail);
    user_init(user_number,user_name,user_key,user_mail);
    put_col("用户创建成功!",2,1);
    now_number=user_number;
    return ;
}
int find_user(char *enter_name)
{
    int enter_len=strlen(enter_name);
    for(int i=1;i<=user_number;i++)
    {
        // int user_len=strlen(user_msg[i].name);
        // if(user_len!=enter_len)continue;
        int flag=0;
        for(int j=0;j<enter_len;j++)
        {
            if(enter_name[j]!=user_msg[i].name[j])flag=1;
        }
        if(flag==0)return i;
    }
    system("pause");
    return -1;
}
void log_in()
{
    put_col("请输入您的用户名：",6,0);
    char user_name[MAX_LENGTH];
    scanf("%s",&user_name);
    int NUM=0;
    flag1:
    NUM=find_user(user_name);
    if(NUM==-1)
    {
        put_col("未找到该用户，请再次输入用户名：",4,1);
        goto flag1;
    }
    char user_key[MAX_LENGTH];
    flag2:
    put_col("请输入您的密码：",6,0);
    scanf("%s",&user_key);
    if(!kmp(user_key,user_msg[NUM].key))
    {
        put_col("您输入的密码有误，请再次输入",4,1);
        goto flag2;
    }
    now_number=NUM;
    put_col("登录成功，欢迎！",2,1);
    return ;
}
void welcome()
{
    system("cls");
    for(int i=1;i<=3;i++) puts("");
    put_col("欢迎来到ddl管理系统！",10,1);
    user_cun();
    //
    user_debug();
    //
    put_col("您是否是新用户？（y/n）",9,1);
    char user_judge;
    scanf("%c",&user_judge);
    if(user_judge=='y'||user_judge=='Y')
    {
        register_user();
    }
    else if(user_judge=='n'||user_judge=='N')
    {
        log_in();
    }
    output_cun();
    return ;
}