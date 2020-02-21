#include"linklist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

tDataNode* FindCmd(tDataNode* head, char* cmd)
{
    tDataNode* p = head;
    while((p != NULL) && (strcmp(cmd, p->cmd) != 0))
    {
        p = p->next;
    }
    return p;
}

void ShowAllCmd(tDataNode* head)
{
    tDataNode* p = head;
    while(p)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
}