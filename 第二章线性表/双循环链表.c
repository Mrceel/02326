#include <stdio.h>
#include <malloc.h>

typedef char DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
    struct Node *pre;
} ListNode;

ListNode* createlist();

int main(int argc, char const *argv[])
{
    ListNode *list = createlist();
    printf("%c", list->pre->pre->data);
    return 0;
}


ListNode* createlist(){

    ListNode *p, *lin, *head;
    head = (ListNode *)malloc(sizeof(ListNode));
    lin = head;
    DataType ch;
    while ((ch = getchar()) != '\n')
    {
        p = (ListNode *)malloc(sizeof(ListNode));
        p->data = ch;
        p->pre = lin;
        lin->next = p;
        lin = p;
    }
    lin->next = head;
    head->pre = lin;
    return head;
}