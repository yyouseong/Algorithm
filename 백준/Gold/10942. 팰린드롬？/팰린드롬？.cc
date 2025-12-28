#include <stdio.h>
bool arr[2001][2001], p[2001];
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		arr[i][i] = true;
		for (int j = i - 1; j > 0; j--) {
			if (p[i] == p[j]) {
				if (j == i - 1 || arr[i - 1][j + 1]) arr[i][j] = true;
			}
		}
	}
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (arr[b][a]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}