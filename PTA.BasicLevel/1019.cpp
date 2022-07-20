#include <cstdio>
#include <algorithm>
using namespace std;

bool cmpI(int a, int b)
{
    return a > b;
}

bool cmpD(int a, int b)
{
    return a < b;
}

int toDigit(int array[])
{
    int ans = 0;
    for(int i = 0; i < 4; i++)
        ans = ans * 10 + array[i];
    return ans;
}

void toArray(int array[], int num)
{
    for(int i = 0; i < 4; i++)
    {
        array[i] = num % 10;
        num /= 10;
    }
}

int main()
{
    int num, record[4];
    scanf("%d", &num);
    do
    {
        toArray(record, num);
        sort(record, record + 4, cmpI);
        int max = toDigit(record);
        sort(record, record + 4, cmpD);
        int min = toDigit(record);
        num = max - min;
        printf("%04d - %04d = %04d\n", max, min, num);
    } while(num != 6174 && num != 0);
    return 0;
}