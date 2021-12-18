#include "ddl.h"
//#10008 号操作，向服务器请求ddl列表,返回ddl数量
void int_to_char(int x,char* buf)
{
    // printf("enter!!\n");
    int sta[128];
    int tot=0;
    while(x)
    {
        // printf("test %d\n",x);
        sta[tot]=x%10;
        tot++;
        x/=10;
    }
    // printf("en2!\n");
    for(int i=0;i<tot;i++)buf[tot-i-1]=sta[i]+'0';
    buf[tot]='\0';
    // printf("int_to_char %s\n",buf);
    return;
}
int char_to_int(char *buf)
{
    int len=strlen(buf);
    int res=0;
    for(int i=0;i<len;i++)
    {
        res=res*10+(buf[i]-'0');
    }
    return res;
}
void q10009(int i)
{
    char buffer[MAX_LENGTH];
    char REV[MAX_LENGTH];
    // itoa(i,buffer,MAX_LENGTH);
    int_to_char(i,buffer);
    SEND_MSG(buffer,"10009",REV);
    printf("ddl: %s\n",REV);
    return ;
}
int num=0;
void q10008(void)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    SEND_MSG(buffer,"10008",REV);
    printf("q10008 %s\n",REV);
    num=char_to_int(REV);
    printf("您当前的ddl数量为：%d\n",num);
    // system("pause");
    
}
void LIST_DDL(void)
{
    puts("您的当前DDL有以下：");
    q10008();
    for(int i=1;i<=num;i++)
        q10009(i);
    return ;
}
//#10010号操作，发送year
void q10010(int year)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    int_to_char(year,buffer);
    // printf("int_to_char %s\n",buffer);
    // itoa(year,buffer,4);
    SEND_MSG(buffer,"10010",REV);
    puts("10010 end");
    return ;
}
void q10011(int mon)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    int_to_char(mon,buffer);
    // itoa(mon,buffer,2);
    SEND_MSG(buffer,"10011",REV);
    puts("10011 end");
    return ;
}
void q10012(int day)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    // itoa(day,buffer,2);
    int_to_char(day,buffer);
    SEND_MSG(buffer,"10012",REV);
    puts("10012 end");
    return ;
}
void q10013(char *name)
{
    char REV[MAX_LENGTH];
    SEND_MSG(name,"10013",REV);
    puts("10013 end");
    return ;
}
void q10014(char *oth)
{
    char REV[MAX_LENGTH];
    SEND_MSG(oth,"10014",REV);
    puts("10014 end");
    return ;
}
void q10015(void)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    SEND_MSG(buffer,"10015",REV);
    puts("10015 end");
    return ;
}
void INSERT_DDL(void)
{
    int year,mon,day;
    char name[MAX_LENGTH],oth[MAX_LENGTH];
    puts("请输入您的DDL的年:");scanf("%d",&year);
    q10010(year);
    puts("请输入您的DDL的月:");scanf("%d",&mon);
    q10011(mon);
    puts("请输入您的DDL的日:");scanf("%d",&day);
    q10012(day);
    puts("请输入您的DDL的事件:");scanf("%s",&name);
    q10013(name);
    puts("请输入您的DDL的备注:");scanf("%s",&oth);
    q10014(oth);
    char buf[MAX_LENGTH];
    // sprintf(buf,"%d",year);
    
    // sprintf(buf,"%d",mon);
    
    // sprintf(buf,"%d",day);
    q10015();
    puts("DDL创建成功！");
    q10019();
    return ;
}
//删除操作
void q10016(int i)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    SEND_MSG(buffer,"10016",REV);
    return ;
}
void DEL()
{
    // LIST_DDL();
    puts("请输入您要修改的序号：");
    int num=0;
    scanf("%d",&num);
    q10016(num);
    puts("删除成功!");
    q10019();
    return ;
}
//#10018 sever排序
void q10018(void)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    SEND_MSG(buffer,"10018",REV);
    return ;
}
void SORT(void)
{
    q10018();
    return;
}
//#10019 用户ddl存档
void q10019(void)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    SEND_MSG(buffer,"10019",REV);
    return ;
}
//传递需要导出的片段的左端点
void q10020(void)
{
    int l=0;
    printf("请输入需要导出的ddl的左端点：");
    scanf("%d",&l);
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    int_to_char(l,buffer);
    SEND_MSG(buffer,"10020",REV);
    return ;
}
//传递需要导出的片段的右端点
void q10021(void)
{
    int r=0;
    printf("请输入需要导出的ddl的右端点：");
    scanf("%d",&r);
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    int_to_char(r,buffer);
    SEND_MSG(buffer,"10021",REV);
    return ;
}
//传递导出指令
void q10022(void)
{
    char buffer[MAX_LENGTH],REV[MAX_LENGTH];
    SEND_MSG(buffer,"10022",REV);
    return ;
}
void SEND_OUT(void)
{
    q10020();
    q10021();
    q10022();
    return ;
}