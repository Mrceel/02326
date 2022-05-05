#include <stdio.h>
#include <stdlib.h>
#define StackSize 10

typedef char DataType;
typedef struct {
    DataType data[StackSize];
    int top;
} SeqStack;

SeqStack s;

// 置空栈
void InitStack(SeqStack *list);

// 栈空判断
int StackEmpty(SeqStack *list);

// 溢栈判断
int StackFull(SeqStack *list);

// 入栈
void push(SeqStack *list, DataType x);

// 出栈
DataType pop(SeqStack *list);

// 取栈顶元素
DataType getTop(SeqStack *list);

// 安出栈顺序打印栈的各个元素
void printElement(SeqStack *list);

int main(int argc, char const *argv[])
{
    InitStack(&s);
    DataType a = 'a';
    push(&s, a);
    DataType c = 'c';
    push(&s, c);
    DataType b = 'b';
    push(&s, b);
    printElement(&s);
    // DataType w = getTop(&s);
    // printf("%c", w);

    // DataType test = pop(&s);
    // printf("%c", test);

    // DataType ww = getTop(&s);
    // printf("%c", ww);
    return 0;
}


// 置空栈
void InitStack(SeqStack *list){
    // 置空顺序栈，C下标是从0开始的。
    list->top = -1;
}

// 栈空判断
int StackEmpty(SeqStack *list){
    return list->top == -1;
}

// 溢栈判断
int StackFull(SeqStack *list){
    return list->top == StackSize - 1;
}

// 入栈
void push(SeqStack *list, DataType x){
    if (StackFull(list))
    {
        printf("栈满");
    }else {
        list->top = list->top+1;
        list->data[list->top] = x;
    }
}

// 出栈
DataType pop(SeqStack *list){
    if (StackEmpty(list))
    {
        printf("栈空");
        exit(0);
    }else{
        return list->data[list->top--];
    }
    
}

// 取栈顶元素
DataType getTop(SeqStack *list){
    if (StackEmpty(list))
    {
        printf("栈空");
        exit(0);
    }else{
        return list->data[list->top];
    }
    
}

// 安出栈顺序打印栈的各个元素
void printElement(SeqStack *list){
    if (StackEmpty(list))
    {
        printf("栈空");
        exit(0);
    }else{
        int x = list->top;

        for (int i = x; i > -1; i--)
        {
            printf("\n%c", list->data[i]);
        }
    }
}