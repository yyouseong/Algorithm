#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct XY
{
    long long x, y;

    bool operator<(const XY &a)
    {
        if (x == a.x)
            return y < a.y;
        return x < a.x;
    }
};

long long ccw(const XY &a, const XY &b, const XY &c)
{
    XY u = {a.x - b.x, a.y - b.y};
    XY v = {c.x - b.x, c.y - b.y};
    return u.x * v.y - u.y * v.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<XY> point(n);
    for (XY &i : point)
        cin >> i.x >> i.y;

    sort(point.begin(), point.end());

    vector<XY> lowerHull, upperHull;
    for (XY &i : point)
    {
        while (lowerHull.size() > 1 && ccw(lowerHull[lowerHull.size() - 2], lowerHull.back(), i) >= 0)
            lowerHull.pop_back();
        lowerHull.push_back(i);
    }
    for (XY &i : point)
    {
        while (upperHull.size() > 1 && ccw(upperHull[upperHull.size() - 2], upperHull.back(), i) <= 0)
            upperHull.pop_back();
        upperHull.push_back(i);
    }

    cout << lowerHull.size() + upperHull.size() - 2 << '\n';
    return 0;
}
