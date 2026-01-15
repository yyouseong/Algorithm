#include <iostream>
#include <vector>
#define MOD 1000000009
using namespace std;

int main()
{
    int t;
    vector<int> DP(1000001, 0);
    DP[0] = DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= 1000000; i++)
        DP[i] = ((DP[i - 1] + DP[i - 2]) % MOD + DP[i - 3]) % MOD;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << DP[n] << '\n';
    }
}