#include <cstdio>
#include <vector>
using namespace std;
const int MaxP = 270000;
int main()
{
	vector<int> chk(MaxP,1);
	chk[0] = chk[1] = 0;
    for(int i=2;i*i<=MaxP;i++){
        if(chk[i] == 0) continue;
        for(int j=i*i;j<=MaxP;j += i)
            chk[j] = false;
    }
	for (int i = 1; i < 270000; i++)
	{
		chk[i] += chk[i - 1];
	}
	int n;
	do {
		scanf("%d", &n);
		if (!n) break;
		printf("%d\n", chk[2 * n] - chk[n]);
	} while (1);
	return 0;
}