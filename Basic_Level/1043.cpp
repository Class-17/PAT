#include<cstdio>
int main()
{
    int hashTable[128] = {0}, count = 0;
    char temp, record[6] = {'P', 'A', 'T', 'e', 's', 't'};
    while(scanf("%c", &temp) != EOF && temp != '\n')
        hashTable[temp]++;
    while (count < 6)
    {
        count = 6;
        for(int i = 0; i < 6; i++)
            if(hashTable[record[i]] > 0)
            {
                printf("%c", record[i]);
                hashTable[record[i]]--;
                count--;
            }
    }
    return 0;
}