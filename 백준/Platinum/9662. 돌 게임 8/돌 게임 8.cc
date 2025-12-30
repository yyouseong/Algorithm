#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m, k, i;
    cin >> m >> k;
    vector<int> canget(k), chk(5000000, 0);
    for (int &j : canget)
        cin >> j;
    vector<bool> game(1000000, true);
    int mask = 0, modular = 1 << canget.back();
    for (i = 1; i <= m; i++)
    {
        for (int j = 0; j < k; j++)
            if (i - canget[j] >= 0)
                if (game[i - canget[j]] == true)
                    game[i] = false;
        mask = ((mask << 1) + game[i]) % modular;
        if (i > canget.back())
        {
            if (chk[mask])
                break;
            else
                chk[mask] = i;
        }
    }
    int cycle = 0, mod = 0;
    int n = chk[mask] ? chk[mask] : m + 1;
    for (int j = 1; j < n; j++)
        if (game[j])
            mod++;
    for (int j = n; j < i; j++)
    {
        if (game[j])
        {
            if (j - n < (m - chk[mask] + 1) % (i - chk[mask]))
                mod++;
            cycle++;
        }
    }
    if (chk[mask])
        cout << cycle * ((m - chk[mask] + 1) / (i - chk[mask])) + mod;
    else
        cout << mod;
    return 0;
}