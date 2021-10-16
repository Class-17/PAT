#include <stdio.h>
#include <string.h>
#define MAXN 500001

int main()
{
    char str[MAXN], temp[MAXN];
    for(int i = 0; i < MAXN; i++) {
        scanf("%c", &str[i]);
        if(str[i] == '\n') {
            str[i] = '\0'; break;
        }
    }
    for(int i = strlen(str) - 1, flag = 0; i >= 0; i--) {
        if(str[i] != ' ') {     // 读入字符不为空格，开始操作
            int j = 0;
            if(flag == 1) printf(" ");      // 控制输出格式
            while(str[i] != ' ' && i >= 0)     // 开始将当前单词存入临时字符数组
                temp[j++] = str[i--];
            j--; i++;        // 抵消上式做出的多余的j++，i--操作
            while(j >= 0)   // 将 temp字符数组倒序输出
                printf("%c", temp[j--]);
            flag = 1;   // 控制输出格式
        }        
    } 
    return 0;
}