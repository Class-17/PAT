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