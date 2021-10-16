#include <bits/stdc++.h>
using namespace std;

int getSum(vector<int>& coupons, vector<int>& products, int direc) {
    int pC = direc < 0 ? coupons.size() - 1 : 0;
    int pP = direc < 0 ? products.size() - 1 : 0;
    int sum = 0;
    while (pC >= 0 && pC < coupons.size() &&
           pP >= 0 && pP < products.size() &&
           coupons[pC] * direc < 0 &&
           coupons[pC] * products[pP] > 0) 
    {
        sum += coupons[pC] * products[pP];
        pC += direc;
        pP += direc;
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    vector<int> coupons(N);
    for(auto& coupon : coupons)
        cin >> coupon;
    cin >> N;
    vector<int> products(N);
    for(auto& product : products)
        cin >> product;
    sort(coupons.begin(), coupons.end());
    sort(products.begin(), products.end());
    cout << getSum(coupons, products, 1) + getSum(coupons, products, -1) << endl;
    return 0;
}