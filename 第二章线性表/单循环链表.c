#include <stdio.h>
#include <malloc.h>  // 分配空间

// strcmp(str1, str2) 比较字符大小 相等返回0 
//str1 若大于str2 则返回大于0 的值。str1 若小于str2 则返回小于0 的值。
#include <string.h>  

typedef char DataType;

typedef struct Node {
    DataType data;
    struct Node *next;

} ListNode;

// 创建单循环链表
ListNode* CreateListNode();
// 查看指定值的下一个节点， 看看循环链表是否创建成功
void LookData(ListNode *list);
// 排序 0从小到大  1从大到小
ListNode * SortList(ListNode *list, int type);
// 输出链表
void printList(ListNode *list);

int main(int argc, char const *argv[])
{
    ListNode *list = CreateListNode();
    ListNode *list1 = SortList(list,  1);
    // printf("%c", list1->next->data);
    printList(list1);
    return 0;
}

// 输出链表
void printList(ListNode *list){
    ListNode *head,*L;
    head = list->next;
    L = list;

    while (head != L)
    { 
        printf("%c", head->data);
        head = head->next;

    }
    
}

// 排序 0从小到大  1从大到小
ListNode * SortList(ListNode *list, int type){
    ListNode *head = list;
    ListNode *newlist = (ListNode *)malloc(sizeof(ListNode));
    ListNode *head1 = newlist;
    ListNode *p, *n, *k;

    p = list->next;
    n = list->next;
    while (n != head)
    {
        // printf("%c", n->data);
        // printf("\n");
        k = n;
        // printf("%c", k->data);
        while (p != head)
        {
             printf("%c", p->data);
             printf("%d", strcmp(&(p->data), &(k->data)) > 0);
             printf("\n");
            if (strcmp(&(p->data), &(k->data)) > 0)
            {
                k = p;
            }
            p = p->next;
        }
        head1->next = k; // 最大项添加到新的list后面
        head1 = k;
        k = n->next; 
        n = n->next;   
    }
    head1->next = newlist;
    return newlist;
}

// 查看指定值的下一个节点， 看看循环链表是否创建成功
void LookData(ListNode *list){
    ListNode *head = list;
    ListNode *p;
    int j = 0;
    p = head;
    while (j<8)
    {
        j++;
        printf("%c", p->data);
        p = p->next;
    }
    
}

// 创建单循环链表
ListNode* CreateListNode(){
    ListNode *p, *f, *head;

    head = (ListNode *) malloc(sizeof(ListNode));
    f = head;
    DataType ch;
    while ((ch = getchar()) != '\n')
    {
        p = (ListNode *)malloc(sizeof(ListNode));
        p->data = ch;
        f->next = p;
        f = p;
    }
    f->next = head;
    return head;
} 