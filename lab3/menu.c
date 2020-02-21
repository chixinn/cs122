#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

void hello();
void help();
void quit();

tDataNode head[]=
{
    {"hello", "hello world!", hello, &head[1]},
    {"help", "the help cmd", help, &head[2]},
    {"quit", "input quit to quit", quit, NULL}
};

int main()
{
    char cmd[CMD_MAX_LEN];
    while(1)
    {
        scanf("%s", cmd);
        tDataNode* p = FindCmd(head, cmd);
        if(p)
        {
            p->handler();
        }
        else
        {
            printf("No cmd is found!\n");
        }
    }
    
    return 0;
}

void help()
{
    ShowAllCmd(head);
}

void quit()
{
    printf("quit from cmd!\n");
    exit(0);
}

void hello()
{
    printf("hello world!\n");
}