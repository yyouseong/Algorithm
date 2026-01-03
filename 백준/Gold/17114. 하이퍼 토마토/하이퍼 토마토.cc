#include <stdio.h>
#include <vector>
#include <queue>
#define N 11
#define v vector
#define Unripe Box[x[10]][x[9]][x[8]][x[7]][x[6]][x[5]][x[4]][x[3]][x[2]][x[1]][x[0]]
#define vv v<v<v<v<v<v<v<v<v<v<v<int> > > > > > > > > > >
using namespace std;
int p[N], inx[N], out[N], x[N];
int cnt, c, ans;
queue<int> X[N], Val;
void Push(int val, int x[]);
int assign();
int main()
{
	for (int i = 0; i < N; i++) scanf("%d", &p[i]); vv Box;
	for (inx[10] = 0; inx[10] < p[10]; inx[10]++) {
		Box.resize(p[10]);
		for (inx[9] = 0; inx[9] < p[9]; inx[9]++) {
			Box[inx[10]].resize(p[9]);
			for (inx[8] = 0; inx[8] < p[8]; inx[8]++) {
				Box[inx[10]][inx[9]].resize(p[8]);
				for (inx[7] = 0; inx[7] < p[7]; inx[7]++) {
					Box[inx[10]][inx[9]][inx[8]].resize(p[7]);
					for (inx[6] = 0; inx[6] < p[6]; inx[6]++) {
						Box[inx[10]][inx[9]][inx[8]][inx[7]].resize(p[6]);
						for (inx[5] = 0; inx[5] < p[5]; inx[5]++) {
							Box[inx[10]][inx[9]][inx[8]][inx[7]][inx[6]].resize(p[5]);
							for (inx[4] = 0; inx[4] < p[4]; inx[4]++) {
								Box[inx[10]][inx[9]][inx[8]][inx[7]][inx[6]][inx[5]].resize(p[4]);
								for (inx[3] = 0; inx[3] < p[3]; inx[3]++) {
									Box[inx[10]][inx[9]][inx[8]][inx[7]][inx[6]][inx[5]][inx[4]].resize(p[3]);
									for (inx[2] = 0; inx[2] < p[2]; inx[2]++) {
										Box[inx[10]][inx[9]][inx[8]][inx[7]][inx[6]][inx[5]][inx[4]][inx[3]].resize(p[2]);
										for (inx[1] = 0; inx[1] < p[1]; inx[1]++) {
											Box[inx[10]][inx[9]][inx[8]][inx[7]][inx[6]][inx[5]][inx[4]][inx[3]][inx[2]].resize(p[1]);
											for (inx[0] = 0; inx[0] < p[0]; inx[0]++) {
												int a;
												Box[inx[10]][inx[9]][inx[8]][inx[7]][inx[6]][inx[5]][inx[4]][inx[3]][inx[2]][inx[1]].resize(p[0]);
												scanf("%d", &a);
												if (!a) cnt++;
												else if (a == 1) Push(0, inx);
												Box[inx[10]][inx[9]][inx[8]][inx[7]][inx[6]][inx[5]][inx[4]][inx[3]][inx[2]][inx[1]][inx[0]] = a;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	while (!X[0].empty() && cnt != c)
	{
		x[0] = X[0].front();
		X[0].pop();
		x[1] = X[1].front();
		X[1].pop();
		x[2] = X[2].front();
		X[2].pop();
		x[3] = X[3].front();
		X[3].pop();
		x[4] = X[4].front();
		X[4].pop();
		x[5] = X[5].front();
		X[5].pop();
		x[6] = X[6].front();
		X[6].pop();
		x[7] = X[7].front();
		X[7].pop();
		x[8] = X[8].front();
		X[8].pop();
		x[9] = X[9].front();
		X[9].pop();
		x[10] = X[10].front();
		X[10].pop();
		int val = Val.front() + 1;
		Val.pop();
		for (int i = 0; i < N; i++)
		{
			x[i]++;
			if (x[0] != -1 && x[0] != p[0] && x[1] != -1 && x[1] != p[1] && x[2] != -1 && x[2] != p[2] && x[3] != -1 && x[3] != p[3] && x[4] != -1 && x[4] != p[4] && x[5] != -1 && x[5] != p[5] && x[6] != -1 && x[6] != p[6] && x[7] != -1 && x[7] != p[7] && x[8] != -1 && x[8] != p[8] && x[9] != -1 && x[9] != p[9] && x[10] != -1 && x[10] != p[10])
			{
				if (!Unripe)
				{
					Push(val, x);
					c++;
					Unripe = val;
				}
			}
			x[i]--;
			ans = val;
		}
		for (int i = 0; i < N; i++)
		{
			x[i]--;
			if (x[0] != -1 && x[0] != p[0] && x[1] != -1 && x[1] != p[1] && x[2] != -1 && x[2] != p[2] && x[3] != -1 && x[3] != p[3] && x[4] != -1 && x[4] != p[4] && x[5] != -1 && x[5] != p[5] && x[6] != -1 && x[6] != p[6] && x[7] != -1 && x[7] != p[7] && x[8] != -1 && x[8] != p[8] && x[9] != -1 && x[9] != p[9] && x[10] != -1 && x[10] != p[10])
			{
				if (!Unripe)
				{
					Push(val, x);
					c++;
					Unripe = val;
				}
			}
			x[i]++;
			ans = val;
		}
	}
	if (cnt == c) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}
void Push(int val, int x[])
{
	Val.push(val);
	for (int i = 0; i < N; i++) X[i].push(x[i]);
	return;
}
int assign()
{
	for (int i = 0; i < N; i++)
	{
		x[i] = X[i].front();
		X[i].pop();
	}
	return Val.front() + 1;
}