/*

1078 Hashing (25point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB


The task of this problem is simple: insert a sequence of distinct 
positive integers into a hash table, and output the positions of 
the input numbers. The hash function is defined to be H(key)=key%TSize 
where TSize is the maximum size of the hash table. Quadratic probing 
(with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given 
by the user is not prime, you must re-define the table size to be the 
smallest prime number which is larger than the size given by the user.
Input Specification:

Each input file contains one test case. For each case, the first line 
contains two positive numbers: MSize (≤10​4​​) and N (≤MSize) which are the 
user-defined table size and the number of input numbers, respectively. 
Then N distinct positive integers are given in the next line. All the 
numbers in a line are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) 
of the input numbers in one line. All the numbers in a line are separated by 
a space, and there must be no extra space at the end of the line. In case it 
is impossible to insert the number, print "-" instead.

Sample Input:

4 4
10 6 4 15

Sample Output:

0 1 4 -

*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

bool hashTable[MAXN] = {false};

bool isPrime(int n)
{
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return false;
    return true;
}

void insert(int key, int m)
{
    for(int step = 0; step < m; step++)
        if(hashTable[(key + step * step) % m] == false) 
        {
            cout << (key + step * step) % m;  
            hashTable[(key + step * step) % m] = true;
            return ;
        }
    cout << "-"; 
}

int main()
{
    int m, n;
    cin >> m >> n;
    while (isPrime(m) == false) m++;
    while(n--)
    {
        int temp;
        cin >> temp;
        insert(temp, m);
        cout << (n != 0 ? ' ' : '\n');
    }
    return 0;
}