#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<bool> x(20), y(20), a(40), b(40);
void f(int i)
{
    if (i == n)
        cnt++;
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (y[j] == false && a[n - i + j] == false && b[i + j] == false)
            {
                y[j] = a[n - i + j] = b[i + j] = true;
                f(i + 1);
                y[j] = a[n - i + j] = b[i + j] = false;
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