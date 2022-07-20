#include<cstdio>
#include<cstring>
int main()
{
    char A[101], B[101];
    scanf("%s %s", A, B);
    char cast[3] = {'J', 'Q', 'K'};
    int encrypt[101] = {0}, record[101] = {0};
    for(int i = strlen(A) - 1, j = 0; i >= 0; i--)
        encrypt[j++] = A[i] - '0';
    for(int i = strlen(B) - 1, j = 0; i >= 0; i--)
        record[j++] = B[i] - '0';
    int length = strlen(A) > strlen(B) ? strlen(A) : strlen(B);
    for(int i = 0; i < length; i++)
    {
        if((i + 1) % 2 == 0) record[i] = record[i]  - encrypt[i];
        else                 record[i] = (record[i] + encrypt[i]) % 13;
        if(record[i] < 0)  record[i] += 10; 
    }
    for(int i = length - 1; i >= 0; i--)
        if(record[i] < 10) printf("%d", record[i]);
        else               printf("%c", cast[record[i] - 10]);
    return 0;          
}