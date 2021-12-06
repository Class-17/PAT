#include<cstdio>
int main()
{
    char record[19], judge[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int num, pow[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    scanf("%d\n", &num);
    bool flag = true;
    for(int i = 0; i < num; i++)
    {
        int count = 0;
        scanf("%s", record);
        for(int j = 0; j < 17; j++)
            count += (record[j] - '0') * pow[j];
        if(judge[count % 11] != record[17]) 
            {
                puts(record);
                flag = false;
            }
    }
    if(flag) printf("All passed\n");
}