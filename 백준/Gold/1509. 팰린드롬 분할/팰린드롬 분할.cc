#include <stdio.h>
#include <string.h>
int arr[2502][2502], ans[2502];
char p[2502];
int main()
{
	int n, m;
	scanf("%s", p);
	n = strlen(p);
	for (int i = 1; i <= n; i++) {
		arr[i][i] = true;
		for (int j = i - 1; j > 0; j--) {
			if (p[i - 1] == p[j - 1]) {
				if (j == i - 1 || arr[i - 1][j + 1]) arr[i][j] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = ans[i - 1] + 1;
		for (int j = i-1; j > 0; j--) {
			if (arr[i][j]) {
				if (ans[j - 1] < ans[i]) ans[i] = ans[j - 1] + 1;
			}
		}
	}
	printf("%d\n", ans[n]);
	return 0;
}