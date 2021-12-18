#pragma once
#ifndef _COLOR_H
#define _COLOR_H
#include <stdio.h>
#include <string.h>
#include <windows.h>

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
void set_color(int x);
void put_col(char *s,int color,int jud);
void put_red_front(char *s,int jud);
void clean_pr(void);
#endif