#include <stdio.h>
/**
 * 指针的理解。
 * 指针存放一个地址， 例如：int num = 99;  int *p = &num; 或 int *p = NULL;  p=&num; 
 * &：取地址运算符。
 * 
 * 那么 *p 在定义以外使用的时候，就是提取（解析）所存放（指向）的地址。
 * 输出*p 就会输出该地址里存放的东西。*p就代表 num变量的内存地址。
 * 
 * 若 *p = 66; 这时候就会改变 num的值，因为。*p 代表num变量的地址，
 * 当改变这个地址存放的东西，num也会变。因为他们都是同一个内存地址。只是名字不同。
 * 就像你老婆喊你老公，你女儿叫你爸爸。
 */
// void sw(int *n){
//     int num = 99;
//     printf("%s", n);
//     n = &num; // 给指针变量赋值。
//     // *n = num;
//     printf("%d\n", *n);
// }

int main(){

    int m = 100;
    int k = 12;
    // sw(&m);
    int *s = NULL;
    s = &m;
    *s = k;
    *s += 1;
    *s = 66;
    printf("%d\n", *s);
    printf("%d\n", m);
    printf("%d", k);
    return 0;
}