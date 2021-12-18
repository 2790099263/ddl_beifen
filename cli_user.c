#include "cli_user.h"
//检查两个字符串是否匹配
int kmp(char *s1,char *s2)
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(len1!=len2)return 0;
    for(int i=0;i<len1;i++)
        if(s1[i]!=s2[i])return 0;
    return 1;
}
void q10017()
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    SEND_MSG(buffer,"10017",REV);
    return ;
}
//读取存档函数，发送请求后，服务器读取用用户存档
void c10001(void)
{
    puts("正在读取存档\n(如果长时间在读取存档，可能当前服务器正在被占用，建议错峰使用)\n........................");
    char s[MAX_LENGTH],rev[MAX_LENGTH];
    SEND_MSG(s,"10001",rev);
    puts("存档读取完成!");
    return ;
}
//10002号操作，在用户注册的模块下，新建一个新用户并且传入用户名
void c10002(void)
{
    put_col("请输入您的用户名：",6,0);
    char user_name[MAX_LENGTH];
    char rev[MAX_LENGTH];
    scanf("%s",&user_name);
    SEND_MSG(user_name,"10002",rev);
    return; 
}
//10003号操作，输入用户密码，再次确认无误之后传到服务器
//服务器收录用户密码
void c10003(void)
{
    flag1:
    puts("请输入您的密码:");
    char key1[MAX_LENGTH],key2[MAX_LENGTH],rev[MAX_LENGTH];
    scanf("%s",&key1);
    puts("请再次输入密码确认;");
    scanf("%s",&key2);
    if(!kmp(key1,key2))goto flag1;
    SEND_MSG(key1,"10003",rev);
    return ;
}
//10004号操作，输入用户的email，并且传入服务器
void c10004(void)
{
    puts("请输入您的邮箱:");
    char mail[MAX_LENGTH],rev[MAX_LENGTH];
    scanf("%s",&mail);
    SEND_MSG(mail,"10004",rev);
    puts("用户创建成功，欢迎！");
    return ;
}
//存档函数
void c10007(void)
{
    char opt[MAX_LENGTH],rev[MAX_LENGTH];
    SEND_MSG(opt,"10007",rev);
    return ;
}
//用户注册函数
void USER_REG(void)
{
    c10001();
    c10002();
    c10003();
    c10004();
    c10007();
    q10017();
    return ;
}
//#10005
//10005函数是寻找用户函数
void c10005(void)
{
    flag1:
    put_col("请输入您的用户名：",6,0);
    char user_name[MAX_LENGTH];
    char rev[MAX_LENGTH];
    scanf("%s",&user_name);
    SEND_MSG(user_name,"10005",rev);
    if(rev[0]=='0')
    {
        puts("未找到该用户，请重新输入:");
        goto flag1;
    }
    return ;
}
//10006函数是输入密码和密码传输函数
void c10006(void)
{
    flag1:
    put_col("请输入您的密码：",6,0);
    char user_key[MAX_LENGTH];
    char rev[MAX_LENGTH];
    scanf("%s",&user_key);
    SEND_MSG(user_key,"10006",rev);
    if(rev[0]=='0')
    {
        puts("密码错误，请重试！");
        goto flag1;
    }
    puts("欢迎！");
    return ;
}
void USER_LOG(void)
{
    c10001();
    c10005();
    c10006();
    c10007();
    q10017();
    return ;
}

