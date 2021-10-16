#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++) {  // 对每一行的乘法表做处理   
        for(int j = 1; j <= i; j++) // 对该行每一列的乘法式处理
            printf("%d*%d=%-4d", j, i, j * i); // 靠右对齐输出等式结果
        printf("\n");   // 输出完该行的乘法表，换行
    }
    return 0;
}
/*
本题要点：
注意观察乘法表中数字和行数列数的关系，找对关系，即可求解；
靠左对齐数字占位的方法： %-nd  （n为占位数）
*/