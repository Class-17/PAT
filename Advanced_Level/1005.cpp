/*
1005 Spell It Right (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and 
output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10^100).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one 
space between two consecutive words, but no extra space at the end of a line.

Sample Input:

12345

Sample Output:

one five

*/

#include<cstdio>
int main()
{
    char temp, cast[10][10] = {"zero", "one", "two", "three", "four", 
                               "five", "six", "seven", "eight", "nine"};
    int num = 0, i = 0, record[3] = {0};
    while (scanf("%c", &temp) != EOF && temp >= '0' && temp <= '9')
        num += temp - '0';
    while (num > 0)
    {
        record[i++] = num % 10;
        num /= 10;
    }
    for(i -= 1; i > 0; i--)
        printf("%s ", cast[record[i]]);
    printf("%s\n" ,cast[record[0]]);
    return 0;
}