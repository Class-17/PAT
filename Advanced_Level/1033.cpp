#include <bits/stdc++.h>
using namespace std;

vector<pair<double, double>> stations;

double getGas(int p, double tank, double Cmax, double Davg) {
    double ableD = stations[p].first + Cmax * Davg;
    int objSta = stations.size() - 1;
    for(int i = p + 1; i < stations.size() && stations[i].first < ableD; i++)
         if(stations[i].second < stations[p].second) {
            objSta = i;
            break;
         }
    double needingGas = (stations[objSta].first - stations[p].first) / Davg;
    if(needingGas <= tank) return 0;
    return (needingGas > Cmax ? Cmax - tank : needingGas - tank);
}

int main()
{
    double Cmax, D, Davg, N;
    cin >> Cmax >> D >> Davg >> N;
    stations.resize(N);
    for(auto& station : stations) 
        cin >> station.second >> station.first;
    sort(stations.begin(), stations.end());
    stations.emplace_back(make_pair(D, DBL_MAX));
    double fee = 0.0, tank = 0.0, loc = 0.0;
    for(int i = 0; i < stations.size(); i++) {
        tank -= (stations[i].first - loc) / Davg;
        if(tank < 0) {
            loc = stations[i].first + tank * Davg;
            break;
        }
        loc = stations[i].first;
        double gas = getGas(i, tank, Cmax, Davg);
        tank += gas;
        fee += gas * stations[i].second;
    }
    if(loc < D) 
        cout << "The maximum travel distance = " 
             << setprecision(2) << fixed << loc << endl;
    else   
        cout << setprecision(2) << fixed << fee << endl;
    return 0;
}