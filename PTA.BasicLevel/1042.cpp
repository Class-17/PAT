#include<cstdio>
int main()
{
    int max = 97, hashTable[128] = {0};
    char temp;
    while(scanf("%c", &temp) != EOF && temp != '\n')
    {
        if(temp >= 'A' && temp <= 'Z')
            temp = temp - 'A' + 'a';
        if(temp >= 'a' && temp <= 'z')
            hashTable[temp]++;
        if(hashTable[temp] > hashTable[max]) 
                max = temp;
        else if(hashTable[temp] == hashTable[max])
                max = max < temp ? max : temp;
    }
    printf("%c %d\n", max, hashTable[max]);
    return 0;
}