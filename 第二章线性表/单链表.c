#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>

typedef char DataType;
typedef struct Node {
    DataType data;
    struct Node *next;
} ListNode;

// 头插法
ListNode CreateListHead();
// 尾插法
ListNode CreateListFooter();
// 循环打印链表数据
void PrintListNode(ListNode const *list);
// 查找第i节点 返回节点。
ListNode searchNode(ListNode const *list, int i);
// 指定位置i后插入节点x
bool insertAfterNode(ListNode *list, int i, ListNode *x);
// 删除指定位置i的节点 并返回节点数据
DataType deleteNode(ListNode *list, int i);

int main(int argc, char const *argv[])
{
    ListNode list = CreateListFooter();
    // ListNode n = searchNode(&list, 3);

    // insertAfterNode(&list, 1, &n);

    DataType m = deleteNode(&list, 2);

    printf("\n");
    printf("%c", m);
    printf("\n");
    PrintListNode(&list);
    return 0;
}

// 删除指定位置i的节点 并返回节点数据
DataType deleteNode(ListNode *list, int i){
    
    ListNode *p = list;
    ListNode *per, *f;
    DataType x;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        printf("位置错误!");
        exit(0);
    }else {
        f = p->next;
        p->next = f->next;
        x = f->data;
        free(f);
        return x;
    }
    

    
}

// 指定节点后插入节点
bool insertAfterNode(ListNode *list, int i, ListNode *x){
    if (list == NULL || list->next == NULL || x == NULL || i<1)
    {
        return false;
    }
    int j = 1;
    ListNode *p = list->next;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if(j == i){
        ListNode *next = p->next;
        p->next = x; 
        x->next = next;
        return true;
    }else{
        return false;
    }
    
}
// 查找第i节点 返回节点。
ListNode searchNode(ListNode const *list, int i){
    if (list == NULL)
    {
        exit(0);
    }
    ListNode *p = list->next;
    int j = 1;
    while (p->data != NULL && j<i)
    {
        p = p->next;
        j++;
    }
    if (j == i)
    {
        return *p;
    }
    
    
}

void PrintListNode(ListNode const *list){
    if (list->next == NULL)
    {
        exit(0);
    }
    ListNode *p;
    p = list->next;
    while (p != NULL)
    {
        printf("\n");
        printf("%c", p->data);
        p = p->next;
    }
}

// 尾插法
ListNode CreateListFooter(){
    ListNode *head, *footer;
    ListNode *p;
    char ch;
    head = (ListNode *) malloc(sizeof(ListNode));
    footer = head;
    while ((ch = getchar()) != '\n')
    {
        p = (ListNode *)malloc(sizeof(ListNode));
        p->data = ch;
        footer->next = p;
        footer = p;
    }
    footer->next = NULL;
    return *head;
}

// 头插法
ListNode CreateListHead(){
    ListNode *head;
    ListNode *p;
    char ch;
    ch = getchar();
    head = NULL;
    while (ch != '\n')
    {
        p = (ListNode *)malloc(sizeof(ListNode));
        p->data = ch;
        p->next = head;
        head = p;  //head 永远指向头节点
        ch = getchar();
    }

    return *head;
}