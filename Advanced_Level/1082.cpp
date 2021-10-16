/*
1082 Read Number in Chinese (25point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

Given an integer with no more than 9 digits, you are supposed to read it in
the traditional Chinese way. Output Fu first if it is negative. For example, 
-123456789 is read as Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi 
Bai ba Shi jiu. Note: zero (ling) must be handled correctly according to the 
Chinese tradition. For example, 100800 is yi Shi Wan ling ba Bai.

Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:
For each test case, print in a line the Chinese way of reading the number. 
The characters are separated by a space and there must be no extra space 
at the end of the line.

Sample Input 1:

-123456789

Sample Output 1:

Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu

Sample Input 2:

100800

Sample Output 2:

yi Shi Wan ling ba Bai

*/

#include <cstdio>

char num[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
bool flag = false;

void judge(void)
{
    if(flag) printf(" "); 
    else     flag = true;
}

void Read(int n)
{
    int a = n / 1000, b = n / 100 % 10, c = n / 10 % 10, d = n % 10;

    if(a) {judge(); printf("%s Qian", num[a]);}

    if(b) {judge(); printf("%s Bai", num[b]);}
    else if(a && (c || d)) {judge(); printf("ling");}

    if(c) {judge(); printf("%s Shi", num[c]);}
    else if((a || b) && d) {judge(); printf("ling");}

    if(d) {judge(); printf("%s", num[d]);}
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 0) {printf("Fu"); n *= -1; flag = true;}

    int a = n / 100000000, b = n / 10000 % 10000, c = n % 10000;

    if(a) {Read(a); printf(" Yi");}

    if(a && b && b < 1000) {judge(); printf("ling");}

    if(b) {Read(b); judge(); printf("Wan");}

    if(b && c && c < 1000) {judge(); printf("ling");}

    if(c) Read(c);
    else if(!a && !b) {judge(); printf("ling");}

    return 0;
}