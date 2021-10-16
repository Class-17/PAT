#include <stdio.h>
#include <string.h>
#define MAXN 100

int judge(char S1[], char S2[])
{
    for(int i = 0, count = 0; i < strlen(S1); i++) {
        if(S1[i] == S2[0]) { // 发现可能出现 S2字符串的部分
            for(int j = 0; j < strlen(S2); j++)  // 检测该子字符串是否与 S2相等
                if(S1[i + j] == S2[j]) count++;
            if(count == strlen(S2)) {    // count = S2的长度 说明此子字符串与 S2相等
                // 从 S1中删除 S2
                for(int j = i + count; j < strlen(S1); j++) // 把原来 S1中存在的 S2覆盖
                    S1[j - count] = S1[j];
                S1[strlen(S1) - count] = '\0';  // 将 S1的结尾点设置为覆盖后的结尾位置
                return 1;           // 直接返回 1表示此次字符串已有改动，需要再次检测
            }
            count = 0;  // count 清零进行下一次检测
        }      
    }
    return 0;   // 返回 0 表明此次没有改动字符串，S1中已无 S2
}

int main()
{
    char S1[MAXN], S2[MAXN];
    for (int i = 0; i < MAXN; i++) {
        scanf("%c", &S1[i]);
        if(S1[i] == '\n') {
           S1[i] ='\0'; break;
        } 
    }
    for (int i = 0; i < MAXN; i++) {
        scanf("%c", &S2[i]);
        if(S2[i] == '\n'){
            S2[i] = '\0'; break;
        }
    }
    while (judge(S1, S2));   // 反复执行判断操作，直到 flag为 0，表明经过检测 S1无改动
    for(int i = 0, len = strlen(S1); i < len; i++) 
        printf("%c", S1[i]);
    return 0;
}
/*
本题要点：
1.如何从 S1中检测到并删除S2；
2.删除后的 S1 可能还存在S2，
例： Heello从中删除 el得到 helo 就需要再删除一次，得到 ho
*/