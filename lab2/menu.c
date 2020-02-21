/*
文件的注释信息模块与代码规范
头部：版权和描述信息
命令行菜单小程序v1.0
*/

/*
Revision log: 

Created by Chixinning, 2020/2/20
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int Help();
 
/*Magic number:尽量不要有神奇数，定义成宏来方便以后的维护*/
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct  DataNode *next;
}tDataNode;
static tDataNode head[] =
{
    {"help","this is help cmd!", Help,&head[1]},
    {"version","menu program v1.0",NULL,NULL}
};

int main()
{
    /* cmdline begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s",cmd);
        tDataNode *p = head;
        /*关于代码的复用，发现代码这有重复的部分*/
        while(p != NULL)
        {
            if(strcmp(p->cmd, cmd) == 0)
            {
                printf("%s - %s\n", p->cmd, p->desc);
                if(p->handler != NULL)
                {
                    /*面向对象的多态机制与这里的相似性？*/
                    p->handler();
                }
                break;
            }
            p = p->next;
        }
        if(p == NULL)
        {
            printf("This is a wrong cmd!\n"); 
        }
    }
}

int Help()
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}
/*
复用修改：
- 功能性修改： 某些数据结构
- 菜单逻辑
- 菜单数据的存储：使用链表，这种存储很通用
- 数据存储通用 -> 数据存储层
- 菜单逻辑(design pattern，即我设计时的使用) -> 业务逻辑层 
*/