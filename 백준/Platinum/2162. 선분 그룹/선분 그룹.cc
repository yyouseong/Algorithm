#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ranking(3001);

int rankF(int x)
{
	if (x == ranking[x])
		return x;
	return ranking[x] = rankF(ranking[x]);
}

void unionFind(int x, int y)
{
	x = rankF(x);
	y = rankF(y);

	if(x==y) return;
	ranking[y] = x;
}

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	long long t = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if (t > 0)
		return 1;
	else if (t < 0)
		return -1;
	else
		return 0;
}

bool intersect(vector<pair<long long, long long>> &ii, vector<pair<long long, long long>> &jj)
{
	int ccw1 = ccw(ii[0].first, ii[0].second, ii[1].first, ii[1].second, jj[0].first, jj[0].second);
	int ccw2 = ccw(ii[0].first, ii[0].second, ii[1].first, ii[1].second, jj[1].first, jj[1].second);
	int ccw3 = ccw(jj[0].first, jj[0].second, jj[1].first, jj[1].second, ii[0].first, ii[0].second);
	int ccw4 = ccw(jj[0].first, jj[0].second, jj[1].first, jj[1].second, ii[1].first, ii[1].second);

	if (ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0)
	{
		if (ii[0] > ii[1])
			swap(ii[0], ii[1]);
		if (jj[0] > jj[1])
			swap(jj[0], jj[1]);
		return ii[0] <= jj[1] && ii[1] >= jj[0];
	}
	return ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<pair<long long, long long>>> line(n, vector<pair<long long, long long>>(2));
	for (int i = 1; i < n; i++)
		ranking[i] = i;

	for (int i = 0; i < n; i++)
	{
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		line[i][0] = {x1, y1};
		line[i][1] = {x2, y2};
		for (int j = 0; j < i; j++)
			if (intersect(line[i], line[j]))
				unionFind(i, j);
	}

	int groupCount = 0, ans = 0;
	vector<int> groupMember(n, 0);
	for (int i = 0; i < n; i++)
		groupMember[rankF(i)]++;
	for (int i = 0; i < n; i++)
	{
		if (groupMember[i])
			groupCount++;
		if (groupMember[i] > ans)
			ans = groupMember[i];
	}

	cout << groupCount << '\n'
		 << ans;

	return 0;
}