#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, D;
    cin >> N >> D;
    vector<pair<double, double>> moonCakes(N);
    for(auto& moonCake : moonCakes) 
        cin >> moonCake.second;
    for(auto& moonCake : moonCakes) {
        cin >> moonCake.first;
        moonCake.first /= moonCake.second;
    }
    sort(moonCakes.begin(), moonCakes.end());
    double incomes = 0.0;
    for(int i = moonCakes.size() - 1; i >= 0 && D > 0; i--) {
        double consume = min(double(D), moonCakes[i].second);
        incomes += consume * moonCakes[i].first;
        D -= consume;
    }
    cout << setprecision(2) << fixed << incomes << endl;
    return 0;
}