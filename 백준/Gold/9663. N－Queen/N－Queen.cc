#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<char> y(20), a(40), b(40);
void f(int i)
{
    if (i == n)
        cnt++;
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (y[j] == 0 && a[n - i + j] == 0 && b[i + j] == 0)
            {
                y[j] = a[n - i + j] = b[i + j] = 1;
                f(i + 1);
                y[j] = a[n - i + j] = b[i + j] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    f(0);
    cout << cnt;
    return 0;
}