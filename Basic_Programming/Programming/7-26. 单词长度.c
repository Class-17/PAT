#include <stdio.h>
int main()
{
    char c;
    int count = 0, i = 0, recrod[20] = {0};  // 用 record数组储存每一个单词的字母个数
    do {
        scanf("%c", &c);
        if(c != ' ' && c != '.')  // 如果当前读入字符不为空格或'.' 计数器 +1
            count++;
        else if(count != 0) {     // 读入字符为空格或'.' 准备计入本次单词个数
            recrod[i++] = count;  // record 记录完成后，i++，准备储存下一个字母
            count = 0;            // 令计数器为零，防止连续的空格导致储存当前单词数过多
        }
    } while (c != '.');        // 检测到结束标志，退出循环
    for(int j = 0; j < i; j++) // 依次输出每个单词的字母个数
        printf("%d%c", recrod[j], j < i - 1 ? ' ' : '\n');
    return 0;
}