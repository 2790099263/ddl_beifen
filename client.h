#pragma once
#ifndef _CLIENT_H
#define _CLIENT_H
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <winsock2.h>
void set_buffer(char *s);
void get_buffer(char *s);
void cli_init(char *IP_ADD);
void cli_do(void);
void cli_close(void);
void sock_file_send(void);
void sock_file_recv(void);
void client_msg_send(char *msg_code);
void get_rev_msg(char *s);
void SEND_MSG(char *S,char *CODE,char *REV);
void c10007(void);
void q10017(void);
#endif