#include <stdio.h>
int main()
{
    int num, temp = 0;
    scanf("%d", &num);
    while(num > 0) {
        temp = temp * 10 + num % 10; // 用 temp 储存倒过来数字的结果
        num /= 10;
    }
    printf("%d\n", temp);
    return 0;
}
/*
转换的方法：对num按10取余会得到它的个位，然后将num除以10.
反复做此操作即可得到num的各个位置上的数字。
temp用于存储结果，每次需要加入num上一个位置的数字，就将当前num*10，空出个位，
留给新的数字。
*/