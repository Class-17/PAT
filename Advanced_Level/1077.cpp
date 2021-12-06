/*
1077 Kuchiguse (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

The Japanese language is notorious for its sentence ending particles. Personal preference of 
such particles can be considered as a reflection of the speaker's personality. Such a preference 
is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, 
the artificial sentence ending particle "nyan~" is often used as a stereotype for characters 
with a cat-like personality:

Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:
Each input file contains one test case. For each case, the first line is an integer N (2≤N≤100). 
Following are N file lines of 0~256 (inclusive) characters in length, each representing a 
character's spoken line. The spoken lines are case sensitive.

Output Specification:
For each test case, print in one line the kuchiguse of the character, i.e., the longest common 
suffix of all N lines. If there is no such suffix, write nai.

Sample Input 1:

3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

Sample Output 1:

nyan~

Sample Input 2:

3
Itai!
Ninjinnwaiyada T_T
T_T

Sample Output 2:

nai

*/

#include<cstdio>
#include<cstring>
char s[100][256];
int main()
{
    int num, count = 0;
    scanf("%d\n", &num);
    for(int i = 0, temp = 0; i < num; temp = 0, i++)
        while (scanf("%c", &s[i][temp]) != EOF && s[i][temp++] != '\n');
    for(int i = strlen(s[0]) - 2, j = strlen(s[1]) - 2; i >= 0 && j >= 0; i--, j--)
        if(s[0][i] == s[1][j]) count++;
        else                   break;
    for(int i = 2; i < num; i++)
        for(int j = strlen(s[i]) - 2, t = strlen(s[0]) - 2, temp = 0; temp < count; j--, t--, temp++)
        {
            if(j < 0)              {count = temp - 1; break;}
            if(s[i][j] != s[0][t]) {count = temp; break;}
        }
    if(count == 0) printf("nai\n");
    else 
    for(int i = strlen(s[0]) - 1 - count; i < strlen(s[0]); i++)
        printf("%c", s[0][i]);
    return 0;
}