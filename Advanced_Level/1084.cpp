/*
1084 Broken Keyboard (20point(s))

Code Size Limit 16 KB   Time Limit 200 ms  Memory Limit 64 MB

On a broken keyboard, some of the keys are worn out. So when you type some 
sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually 
type out, please list those keys which are for sure worn out.

Input Specification:
Each input file contains one test case. For each case, the 1st line contains the 
original string, and the 2nd line contains the typed-out string. Each string 
contains no more than 80 characters which are either English letters [A-Z] 
(case insensitive), digital numbers [0-9], or _ (representing the space). It is 
guaranteed that both strings are non-empty.

Output Specification:
For each test case, print in one line the keys that are worn out, in the order 
of being detected. The English letters must be capitalized. Each worn out key must 
be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:

7_This_is_a_test
_hs_s_a_es

Sample Output:

7TI

*/

#include<cstdio>
#include<cstring>
int main()
{
    char s[81], record[81];
    bool hashTable[128] =  {false};
    scanf("%s\n", s);
    for(int i = 0, j = 0; i < strlen(s); i++)
    {
        char temp;
        scanf("%c", &temp);
        while(s[i] != temp && i < strlen(s))
            if(s[i] >= 'a' && s[i] <= 'z')
                 record[j++] = s[i++] - 'a' + 'A';
            else record[j++] = s[i++];
    }
    for(int i = 0; i < strlen(record); i++)
        if(hashTable[record[i]] == false)
        {
            printf("%c", record[i]);
            hashTable[record[i]] = true;
        } 
    return 0;
}