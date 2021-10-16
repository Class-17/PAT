#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b)      printf("C\n");
    else if(a == c) printf("B\n"); // a!=b 比较a与c
    else            printf("A\n"); // a！=b且 a！=c 说明b=c 
    return 0;  
}