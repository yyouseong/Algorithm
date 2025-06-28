#include <iostream>
#include <vector>
using namespace std;

vector<int> tSquare(20,1);

bool g(int r, int c, int idx){
	if(r == 1 || c == 1) return true;
	if(tSquare[idx] >= r && tSquare[idx] < c || tSquare[idx] < r && tSquare[idx] >= c) 
		return g((r-1)%tSquare[idx]+1, (c-1)%tSquare[idx]+1, idx-1);

	if(tSquare[idx] < r && tSquare[idx] < c) return false;
	return g(r,c,idx-1);
}
int main()
{
	ios_base::sync_with_stdio(false);

	for(int i=1;tSquare[i-1]<100000;i++) tSquare[i] = tSquare[i-1] * 2;

	int n,m;
	bool index = 0;
	cin>>n>>m;
	vector<int> rc(n),cc(m);
	for(int &i:rc) cin>>i;
	for(int &i:cc) cin>>i;


	for(int i=0;i<n;i++)
		if(rc[i]) index ^= g(n-i,m,17);
	for(int i=0;i<m;i++)
		if(cc[i]) index ^= g(n,m-i,17);

	cout<<index;
	return 0;
}