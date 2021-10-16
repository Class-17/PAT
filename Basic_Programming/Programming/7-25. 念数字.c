#include <stdio.h>
#include <string.h>
#define MAXN 10
int main()
{
    char num[MAXN], cast[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    // 采用字符型数组读入数字，利于处理，使用 cast 储存数字对应的拼音
    scanf("%s", num);
    for(int i = 0, len = strlen(num); i < len; i++) {
        if(num[i] != '-') printf("%s%c", cast[num[i] - '0'], i < len - 1 ? ' ' : '\n');
        else              printf("fu ");  // 读入数字为负数，第一个字符为'-'
    }
    return 0;
}