#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;

int prime[MAXN];
bool isPrime[MAXN];

void Find_Prime(int n)
{
    for(int i = 2, count = 0; i < MAXN && count < n; i++)
        if(isPrime[i] == false)
        {
            prime[count++] = i;
            for(int j = i + i; j < MAXN; j += i)
                isPrime[j] = true;
        }            
}

int main()
{
    int m, n;
    cin >> m >> n;
    Find_Prime(n);
    for(int i = m - 1; i < n; i++)
    {
        cout << prime[i];
        if((i - m + 2) % 10 != 0 && i < n - 1) 
            cout << " ";
        else                        
            cout << endl;
    }
    return 0;
}