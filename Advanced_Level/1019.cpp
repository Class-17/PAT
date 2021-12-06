/*
1019 General Palindromic Number (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

A number that will be the same when it is written forwards or backwards is 
known as a Palindromic Number. For example, 1234321 is a palindromic number. 
All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, 
the concept of palindromicity can be applied to the natural numbers in any 
numeral system. Consider a number N>0 in base b≥2, where it is written in 
standard notation with k+1 digits a​i as ∑k i=0 (aib^i​​). 
Here, as usual, 0≤ai​​ <b for all i and ak  is non-zero. Then N is palindromic 
if and only if ai​ =ak−i  for all i. Zero is written 0 in any base and is 
also palindromic by definition.

Given any positive decimal integer N and a base b, you are supposed to tell 
if N is a palindromic number in base b.

Input Specification:
Each input file contains one test case. Each case consists of two positive 
numbers N and b, where 0<N≤10^9​​ is the decimal number and 2≤b≤10^9​​ is the base.
The numbers are separated by a space.

Output Specification:
For each test case, first print in one line Yes if N is a palindromic number 
in base b, or No if not. Then in the next line, print N as the number in base 
b in the form "a​k ak−1​​ ... a0​​". Notice that there must be no extra space at
the end of output.

Sample Input 1:

27 2

Sample Output 1:

Yes
1 1 0 1 1

Sample Input 2:

121 5

Sample Output 2:

No
4 4 1

*/

#include<cstdio>
int main()
{
    int num, base, j, i = 0, record[50];
    scanf("%d %d", &num, &base);
    do
    {
        record[i++] = num % base;
        num /= base;
    } while (num > 0);
    for(j = 0; j < i / 2; j++)
        if(record[j] != record[ i - j - 1]) break;
    if( j != i / 2) printf("No\n");z
    else            printf("Yes\n");
    for(j = i - 1; j > 0 ; j--)
        printf("%d ", record[j]);
    printf("%d\n", record[0]);
    return 0;
}