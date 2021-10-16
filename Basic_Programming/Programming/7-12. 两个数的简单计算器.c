#include <stdio.h>
int main()
{
    int a, b; char operator;
    scanf("%d %c %d", &a, &operator, &b); // 注意输入格式，%d %c 中间的空格不能少
    switch (operator) {
        case '+': printf("%d\n", a + b); break;
        case '-': printf("%d\n", a - b); break;
        case '*': printf("%d\n", a * b); break;
        case '/': printf("%d\n", a / b); break;
        case '%': printf("%d\n", a % b); break;
        default:  printf("ERROR\n");     break;
    }
    return 0;
}