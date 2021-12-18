#include "client.h"

#pragma comment(lib,"ws2_32.lib")
#define  PORT 4000
#define  IP_ADDRESS "192.168.26.128"
#define BUF_SIZE 1024
WSADATA  Ws;
SOCKET ClientSocket;
struct sockaddr_in ClientAddr;
int Ret = 0;
char SendBuffer[BUF_SIZE],RecvBuffer[BUF_SIZE];
//改变buffer
void set_buffer(char *s)
{
    strcpy(SendBuffer,s);
    // printf("Buffer : %s\n",SendBuffer);
    return ;
}
//获取buffer
void get_buffer(char *s)
{
    strcpy(s,SendBuffer);
    return ;
}
//socket初始化
void cli_init(char *IP_ADD)
{
    /* Init Windows Socket */
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        printf("Init Windows Socket Failed::%d\n", GetLastError());
        return -1;
    }
    /* Create Socket */
    ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( ClientSocket == INVALID_SOCKET )
    {
        printf("Create Socket Failed::%d\n", GetLastError());
        return -1;
    }
 
    ClientAddr.sin_family = AF_INET;
    ClientAddr.sin_addr.s_addr = inet_addr(IP_ADD);
    ClientAddr.sin_port = htons(PORT);
    memset(ClientAddr.sin_zero, 0x00, 8);
 
	/* connect socket */
    Ret = connect(ClientSocket,(struct sockaddr*)&ClientAddr, sizeof(ClientAddr));
    if ( Ret == SOCKET_ERROR )
    {
        printf("Connect Error::%d\n", GetLastError());
        return -1;
    }
    else
    {
        printf("Connect succedded!\n");
    }
    return ;
}
//发送sendbuffer里的内容，返回的内容在传入的spc数组中
//msg_code是对应的操作代码。
void client_msg_send(char *msg_code)
{
    // memset(SendBuffer,0,sizeof(SendBuffer));
    // memset(RecvBuffer,0,sizeof(RecvBuffer));
    char lin[BUF_SIZE];
    strcpy(lin,msg_code);
    strcat(lin,SendBuffer);
    strcpy(SendBuffer,lin);
    Ret = send(ClientSocket, SendBuffer, (int)strlen(SendBuffer), 0);
    if ( Ret == SOCKET_ERROR )
    {
        printf("Send Info Error::%d\n", GetLastError());
        return ;
    }
    recv(ClientSocket, RecvBuffer, 1023, NULL);
}
//将recvbufferreturn；
void get_rev_msg(char *s)
{
    strcpy(s,RecvBuffer);
    return ;
}
//测试函数，输入什么返回什么。
void cli_do()
{
    while (1)
    {
        scanf("%s", SendBuffer);
 
		/* send data to server */
        Ret = send(ClientSocket, SendBuffer, (int)strlen(SendBuffer), 0);
        if ( Ret == SOCKET_ERROR )
        {
            printf("Send Info Error::%d\n", GetLastError());
            break;
        }
        if('q' == SendBuffer[0])
		{
			break;
		}
		recv(ClientSocket, RecvBuffer, MAXBYTE, NULL);
        // printf("%s\n",RecvBuffer);
    }
    return ;
}
//发送文件的内容，用于文件传输，等待施工
void sock_file_send(void)
{
    char *filename = "E:\\1.mkv";  //文件名
    FILE *fp = fopen(filename, "rb");  //以二进制方式打开文件
    if(fp == NULL){
        printf("Cannot open file, press any key to exit!\n");
        system("pause");
        exit(0);
    }
    struct sockaddr_in client_addr;
	int client_socket;
    char buffer[BUF_SIZE] = {0};  //缓冲区
    int nCount;
    while( (nCount = fread(buffer, 1, BUF_SIZE, fp)) > 0 ){
        send(ClientSocket, buffer, nCount, 0);
    }
    shutdown(ClientSocket, SD_SEND);  //文件读取完毕，断开输出流，向客户端发送FIN包
    recv(ClientSocket, buffer, BUF_SIZE, 0);  //阻塞，等待客户端接收完毕
    fclose(fp);
    return ;
}
//接受文件内容，用于文件传输，同样只是demo，还没有考虑全面
void sock_file_recv()
{
    char filename[100]={0};
    printf("Input filename to save: ");
    scanf("%s",filename);
    FILE *fp= fopen(filename, "wb");
    if(fp == NULL){
        printf("Cannot open file, press any key to exit!\n");
        system("pause");
        exit(0);
    }
    puts("file is transporting!!");
    char buffer[BUF_SIZE] = {0};  //文件缓冲区
    int nCount;
    while( (nCount = recv(ClientSocket, buffer, BUF_SIZE, 0)) > 0 ){
        fwrite(buffer, nCount, 1, fp);
    }
    puts("File transfer success!");
}
//关闭socket
void cli_close()
{
    /* close socket */
    send(ClientSocket, "quit", (int)strlen("quit"), 0);
    closesocket(ClientSocket);
    WSACleanup();
}
//对外总收发函数
void SEND_MSG(char *S,char *CODE,char *REV)
{
    memset(SendBuffer,0,sizeof(SendBuffer));
    memset(RecvBuffer,0,sizeof(RecvBuffer));
    set_buffer(S);
    client_msg_send(CODE);
    get_rev_msg(REV);
    // printf("receive from sever : %s\n",REV);
    return ;
}
