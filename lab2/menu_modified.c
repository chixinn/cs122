/*
头部：版权和描述信息
命令行菜单小程序 v1.1
描述：此版本在上版本之上进行了代码规范和模块化
*/

/*
Revision log: 

Created by Chixinning, 2020/2/20
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/*data struct and its opeartions*/
typedef struct DataNode
{
    char* cmd;
    char* desc;
    int   (*handler)();
    struct DataNode *next;
}tDataNode;

/*将对链表的查询孤立出来变成一个函数*/
tDataNode* FindCmd(tDataNode* head, char* cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode* p = head;
    while(p != NULL)
    {
        if(strcmp(p->cmd, cmd) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

static tDataNode head[] =
{
    {"help","this is help cmd!", Help,&head[1]},
    {"version","menu program v1.0",NULL,NULL}
};

int ShowAllCmd(tDataNode* head)
{
    printf("Menu List:\n");
    tDataNode* p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}

int Help();

int main()
{
    /*cmd line begins*/
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode* p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}