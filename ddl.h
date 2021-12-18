#pragma once
#ifndef _DDL_H
#define _DDL_H
#define MAX_LENGTH 1024
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "client.h"
#include "color.h"
void int_to_char(int x,char *buf);
void q10008(void);
void q10009(int i);
void q10010(int year);
void q10011(int mon);
void q10012(int day);
void q10013(char *name);
void q10014(char *oth);
void q10015(void);
void q10016(int i);
void LIST_DDL(void);
void INSERT_DDL(void);
void DEL(void);
void q10018(void);
void SORT(void);
void q10019(void);
void q10020(void);
void q10021(void);
void q10022(void);
void SEND_OUT(void);
void MENU(void);
#endif