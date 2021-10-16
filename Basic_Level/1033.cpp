#include<cstdio>
#include<cstring>
int main()
{
    char record[100001], temp;
    bool hashTable[256] = {false};
    scanf("%[^\n]", record);
    getchar();
    for(int i = 0; i < strlen(record); i++)
        if(record[i] >= 'A' && record[i] <= 'Z')
            hashTable[record[i]] = hashTable[record[i] - 'A' + 'a'] = true;
        else hashTable[record[i]] = true;
    while(scanf("%c", &temp) != EOF)
        if(hashTable[temp] == false)
            if(temp >= 'A' && temp <= 'Z')
            {
                if(hashTable['+'] == false)
                    printf("%c", temp);
            } 
            else printf("%c", temp);
    return 0;
}