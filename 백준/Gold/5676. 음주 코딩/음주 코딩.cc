#include <iostream>
#include <vector>
using namespace std;

int pmz(int n)
{
    if (n > 0)
        return 1;
    else if (n < 0)
        return -1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, N;
    while (cin >> n >> k)
    {
        N = 1;
        while (N < n)
            N *= 2;
        vector<int> tree(2 * N, 1);
        for (int i = 0, j; i < n; i++)
        {
            cin >> j;
            tree[N + i] = pmz(j);
        }
        for (int i = N - 1; i >= 0; i--)
            tree[i] = tree[i * 2] * tree[i * 2 + 1];

        for (int i = 0; i < k; i++)
        {
            char O;
            int a, b;
            cin >> O >> a >> b;
            a += N - 1;
            if (O == 'C')
            {
                tree[a] = pmz(b);
                a /= 2;
                while (a)
                {
                    tree[a] = tree[a * 2] * tree[a * 2 + 1];
                    a /= 2;
                }
            }
            if (O == 'P')
            {
                int minus = 0;
                bool zero = false;
                b += N - 1;
                while (a <= b)
                {
                    if (!tree[a] || !tree[b])
                    {
                        zero = true;
                        break;
                    }
                    if (a % 2)
                        tree[a++] < 0 ? minus++ : 0;
                    else if (b % 2 == 0)
                        tree[b--] < 0 ? minus++ : 0;
                    else
                    {
                        a /= 2;
                        b /= 2;
                    }
                }
                zero ? cout << 0 : (minus % 2) ? cout << '-'
                                               : cout << '+';
            }
        }
        cout << '\n';
    }
    return 0;
}