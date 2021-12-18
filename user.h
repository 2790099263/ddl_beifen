#ifndef _USER_H
#define _USER_H
#include <stdio.h>
#include <string.h>
void user_init(int i,char *user_name,char *user_key,char *user_mail);
void user_cun(void);
void output_cun(void);
int kmp(char *s1,char *s2);
void user_debug(void);
void register_user(void);
int find_user(char *enter_name);
void log_in(void);
void welcome(void);
#endif
