#include <cstdio>
#define Max(a,b) ((a)>(b)?(a):(b))
#define N 100002
bool P[N];
int Dp[N], Size[N];
int max;
int main()
{
	int n, m, l;
	scanf("%d%d%d", &m, &l, &n);
	for (int i = 0, a; i < n; i++)
	{
		scanf("%d", &a);
		P[a] = true;
	}
	for (int i = 1; i <= m - l + 1; i++)
	{
		int dp = 0;
		for (int j = i - l; j > i - l - l && j > 0; j--)
		{
			if (dp < Dp[j])
			{
				dp = Dp[j];
				Size[i] = Size[j];
			}
		}
		Dp[i] = dp + P[i] + 1;
		Size[i]++;
		if (Size[i] > n) max = Max(max, Dp[i] + n - Size[i]);
		else max = Max(max, Dp[i]);
	}
	printf("%d\n", max);
	return 0;
}