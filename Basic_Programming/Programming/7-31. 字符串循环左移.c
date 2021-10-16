#include <stdio.h>
#include <string.h>
#define MAXN 110
int main()
{
    char str[MAXN], result[MAXN];
    int num, i;
    for(int i = 0 ; i < MAXN; i++) {
        scanf("%c", &str[i]);
        if(str[i] == '\n') {
            str[i] = '\0'; break;
        }
    }
    scanf("%d", &num);
    num %= strlen(str);         // 如果左移次数大于字符串长度，将其取余
    for(int i = 0; i < strlen(str); i++) {
        int location = i - num;  // 得到左移后原字符的所在位置
        if(location < 0) location += strlen(str);  // 如果减去左移次数小于零，+字符串长度
        result[location] = str[i];  // 储存至新数组
    }
    for(int i = 0; i < strlen(str); i++)
        printf("%c", result[i]);
    return 0;
}