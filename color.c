#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "color.h"
/*

前景颜色对应值： 
　　0=黑色                8=灰色　　
  　1=蓝色                9=淡蓝色      　　                        
　　2=绿色                10=淡绿色             　　
　　3=湖蓝色              11=淡浅绿色    
　　4=红色                12=淡红色      　　
　　5=紫色                13=淡紫色             　　
　　6=黄色                14=淡黄色            　　
　　7=白色                15=亮白色
*/
void set_color(int x)
{
    if (x >= 0 && x <= 15)                                           //参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x); //只有一个参数，改变字体颜色
    else                                                             //默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return;
}
//s是传入的需要输出的字符串，color是字体的颜色,jud是是否换行，jud==1换行
void put_col(char *s, int color, int jud)
{
    set_color(color);
    printf("%s", s);
    if (jud == 1)
        puts("");
    set_color(7);
    return;
}
void put_red_front(char *s, int jud)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    printf("%s", s);
    if (jud == 1)
        puts("");
    return;
}
void clean_pr()
{
    system("cls");
    return ;
}