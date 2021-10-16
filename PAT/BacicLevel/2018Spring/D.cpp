#include <bits/stdc++.h>
using namespace std;

string GetSeq(string nums) {
    nums.push_back('E');
    int frontN = 0, p = 1, cnt = 1;
    while (p < nums.size()) {
        if(nums[p] == nums[frontN]) {
            cnt++;
        }
        else {
            if(cnt == 1)
                nums.insert(frontN + 1, 1, '1');
            else 
                nums.replace(frontN + 1, cnt - 1, to_string(cnt));
            frontN += 2;
            cnt = 1;
            p = frontN;
        }
        p++;
    }
    nums.pop_back();
    return nums;
}

int main()
{
    int d, N;
    cin >> d >> N;
    vector<string> seq(N);
    seq[0] = to_string(d);
    for(int i = 1; i < N; i++)
        seq[i] = GetSeq(seq[i - 1]);
    cout << seq[N - 1] << endl;
    return 0;
}