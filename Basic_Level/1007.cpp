#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    int n, total = 0;
    cin >> n;
    for(int i = 3; i + 2 <= n; i += 2)
        if(isPrime(i) && isPrime(i + 2))
            total++;
    cout << total << endl;
    return 0;
}