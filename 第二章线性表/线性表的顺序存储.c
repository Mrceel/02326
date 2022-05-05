#include <stdio.h>
//  线性表的顺序存储

#define LISTSIZE 100
typedef int DataType;
typedef struct {
    DataType data[LISTSIZE];
    int length;
} SeqList;
// 初始化顺序表
void initList (SeqList *list){
    list->length = 0;
}
// 顺序表插入数据，在第i个之前插入x
void insert(SeqList *list, int i, DataType x);

// 顺序表逆置
SeqList revert(SeqList list);

// 取出顺序表中最大元素(max)和最小元素(min)及其位置x、n。
void MaxMin(SeqList *list, DataType *max, DataType *min, DataType *x, DataType *n);

int main(int argc, char const *argv[])
{
    SeqList list;
    initList(&list);
    for (int k = 1; k <= 10; k++)
    {
        insert(&list, k, k + 2);
    }
    
    for (int j = 0; j < 10; j++)
    {
       printf("%d,", list.data[j]);
    }
    printf("\n");
    // SeqList reverList = revert(list);
    int x=0, n= 0;
    DataType Max, Min;

    MaxMin(&list, &Max, &Min, &x, &n);
    printf("%d --第%d个, %d -- 第%d个", Max, x, Min, n);
    // for (int j = 0; j < 10; j++)
    // {
    //    printf("%d,", reverList.data[j]);
    // }


    return 0;
}

void MaxMin(SeqList *list, DataType *max, DataType *min, DataType *x, DataType *n){
    *max = list->data[0];
    *min = list->data[0];
    *x = 0;
    *n = 0;
    for (int i = 0; i < list->length; i++)
    {
        if (*max < list->data[i])
        {
            *max = list->data[i];
            *x = i;
        }else if (*min > list->data[i])
        {
            *min = list->data[i];
            *n = i;
        }
    }
}

SeqList revert(SeqList list){
    for (int n = 0; n < list.length / 2; n++)
    {
        int em = list.data[n];
        list.data[n] = list.data[list.length - n - 1];
        list.data[list.length - n - 1] = em;
    }
    return list;
}

void insert (SeqList *list, int i, DataType x){
    if(list->length >= LISTSIZE){
        printf("超出");
        return;
    }
        
    if (i < 1 || i > list->length + 1 )
    {
        printf("插入位置出错");
        return;
    }

    for (int k = list->length - 1; k >= i - 1; k--)
    {
        list->data[k + 1] = list->data[k];
    }
    list->data[i - 1] = x;
    list->length++;
}