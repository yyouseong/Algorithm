#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> memo(500, vector<int>(500));

int f(vector<vector<int>> &Matrix, int left, int right)
{
    if (left == right)
        return 0;

    int minValue = INT_MAX;
    for (int i = left; i < right; i++)
    {
        if (memo[left][i] == 0)
            memo[left][i] = f(Matrix, left, i);
        if (memo[i + 1][right] == 0)
            memo[i + 1][right] = f(Matrix, i + 1, right);

        int t = memo[left][i] + memo[i + 1][right] + Matrix[left][0] * Matrix[i][1] * Matrix[right][1];
        minValue = min(minValue, t);
    }
    return minValue;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> Matrix(n, vector<int>(2));

    for (vector<int> &i : Matrix)
        cin >> i[0] >> i[1];

    cout << f(Matrix, 0, n - 1);

    return 0;
}