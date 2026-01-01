#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> learn(26);
int idx, cur, k;
int chk(vector<int> &beta)
{
    for (int j = 4; j < beta.size() - 4; j++)
        if (learn[beta[j]] == false)
            return 0;
    return 1;
}

int canread(vector<vector<int>> &alpha)
{
    int cnt = 0;
    for (vector<int> &beta : alpha)
        cnt += chk(beta);
    return cnt;
}

int f(vector<vector<int>> &alpha)
{
    if (idx == k)
        return canread(alpha);

    int cnt = 0;
    for (int i = cur; i < 26 - k + idx + 1; i++)
    {
        if (i + 'a' == 'a' || i + 'a' == 'n' || i + 'a' == 't' || i + 'a' == 'i' || i + 'a' == 'c')
            continue;
        learn[i] = true;
        idx++;
        cur = i + 1;
        int tmp = f(alpha);
        idx--;
        learn[i] = false;
        if (cnt < tmp)
            cnt = tmp;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n >> k;
    vector<vector<int>> alpha(n, vector<int>(0, false));
    learn['a' - 'a'] = learn['n' - 'a'] = learn['t' - 'a'] = learn['i' - 'a'] = learn['c' - 'a'] = true;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++)
            alpha[i].push_back(input[j] - 'a');
    }
    if (k < 5)
    {
        cout << 0;
        return 0;
    }
    k -= 5;
    idx = cur = 0;
    cout << f(alpha);

    return 0;
}