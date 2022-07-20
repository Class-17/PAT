/*
1073 Scientific Notation (20point(s))

Code Size Limit 16 KB   Time Limit 200 ms  Memory Limit 64 MB

Scientific notation is the way that scientists easily handle very large
numbers or very small numbers. The notation matches the regular expression
[+-][1-9].[0-9]+E[+-][0-9]+ which means that the integer portion has 
exactly one digit, there is at least one digit in the fractional portion, 
and the number and its exponent's signs are always provided even when they 
are positive.

Now given a real number A in scientific notation, you are supposed to print 
A in the conventional notation while keeping all the significant figures.

Input Specification:
Each input contains one test case. For each case, there is one line containing 
the real number A in scientific notation. The number is no more than 9999 bytes 
in length and the exponent's absolute value is no more than 9999.

Output Specification:
For each test case, print in one line the input number A in the conventional 
notation, with all the significant figures kept, including trailing zeros.

Sample Input 1:

+1.23400E-03

Sample Output 1:

0.00123400

Sample Input 2:

-1.2E+10

Sample Output 2:

-12000000000

*/

#include<cstdio>
char num[20000];
int main()
{
    int pow = 0, poPosition = 2, ePosition = 0;
    scanf("%s", num);
    if(num[0] == '-') printf("-");
    for(int i = 4; num[i] != '\0'; i++)
        if(num[i] == 'E')
        {
            for(int j = i + 2; num[j] != '\0'; j++)
            {
                pow = pow * 10 + num[j] - '0';
                num[j] = '\0';
            }
            if(num[i + 1] == '-') pow *= -1;
            num[i] = num[i + 1] = '\0';
            ePosition = i;
        }
    if(pow > 0)
        while(pow > 0)
        {
            num[poPosition] = num[poPosition + 1];
            if(num[poPosition] == '\0') num[poPosition] = '0';
            num[++poPosition] = '.';
            pow--;
            if(pow == 0 && num[poPosition + 1] == '\0')
                num[poPosition] = 0; 
        }   
    else if(pow < 0)
    {
        num[0] = '0'; num[2] = num[1]; num[1] = '.'; pow = (pow + 1) * -1;
        if(pow > 0)
            for(int i = ePosition - 1; i > 1; i--)
                 num[i + pow] = num[i]; 
        for(int i = 1 + pow; i > 1; i--)
            num[i] = '0';
    }
    for(int i = (num[0] == '0' ? 0 : 1); num[i] != '\0'; i++)
        printf("%c", num[i]);
    return 0;
}