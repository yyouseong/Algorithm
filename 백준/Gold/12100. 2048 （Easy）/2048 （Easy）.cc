#include <cstdio>
#include <vector>
#include <queue>
#define Max(a,b) (a>b?a:b)
using namespace std;

int MAX;

void cal(int n,vector<vector<int> > _2048);
void left(vector<vector<int> > _2048, int n);
void right(vector<vector<int> > _2048, int n);
void up(vector<vector<int> > _2048, int n);
void down(vector<vector<int> > _2048, int n);

int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<int> > _2048(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &_2048[i][j]);
		}
	}

	cal(5, _2048);

	printf("%d\n", MAX);

	return 0;
}

void cal(int n,vector<vector<int> > _2048)
{
	if (n == 0) return;

	n--;
	left(_2048, n);
	right(_2048, n);
	up(_2048, n);
	down(_2048, n);

	return;
}

void left(vector<vector<int> > _2048, int n)
{
	for (int i = 0; i < _2048.size(); i++)
	{
		queue<int>q;

		for (int j = 0; j < _2048.size(); j++)
		{
			if (_2048[i][j])
			{
				q.push(_2048[i][j]);
				_2048[i][j] = 0;
			}
		}

		int index = 0;
		while (!q.empty())
		{
			_2048[i][index] = q.front();
			q.pop();

			if (!q.empty())
				if (q.front() == _2048[i][index])
					_2048[i][index] *= 2, q.pop();

			MAX = Max(MAX, _2048[i][index]);

			index++;
		}
	}
	cal(n, _2048);
}
void right(vector<vector<int> > _2048, int n)
{
	for (int i = 0; i < _2048.size(); i++)
	{
		queue<int>q;

		for (int j = _2048.size() - 1; j >= 0; j--)
		{
			if (_2048[i][j])
			{
				//printf("%d\n", _2048[i][j]);
				q.push(_2048[i][j]);
				_2048[i][j] = 0;
			}
		}

		int index = _2048.size() - 1;
		while (!q.empty())
		{
			_2048[i][index] = q.front();
			q.pop();

			if (!q.empty())
				if (q.front() == _2048[i][index])
					_2048[i][index] *= 2, q.pop();

			MAX = Max(MAX, _2048[i][index]);

			index--;
		}
	}
	cal(n, _2048);
}
void up(vector<vector<int> > _2048, int n)
{
	for (int j = 0; j < _2048.size(); j++)
	{
		queue<int>q;

		for (int i = 0; i < _2048.size(); i++)
		{
			if (_2048[i][j])
			{
				q.push(_2048[i][j]);
				_2048[i][j] = 0;
			}
		}

		int index = 0;
		while (!q.empty())
		{
			_2048[index][j] = q.front();
			q.pop();

			if (!q.empty())
				if (q.front() == _2048[index][j])
					_2048[index][j] *= 2, q.pop();

			MAX = Max(MAX, _2048[index][j]);

			index++;
		}
	}
	cal(n, _2048);
}
void down(vector<vector<int> > _2048, int n)
{
	for (int j = 0; j < _2048.size(); j++)
	{
		queue<int>q;

		for (int i = _2048.size() - 1; i >= 0; i--)
		{
			if (_2048[i][j])
			{
				q.push(_2048[i][j]);
				_2048[i][j] = 0;
			}
		}

		int index = _2048.size() - 1;
		while (!q.empty())
		{
			_2048[index][j] = q.front();
			q.pop();

			if (!q.empty())
				if (q.front() == _2048[index][j])
					_2048[index][j] *= 2, q.pop();

			MAX = Max(MAX, _2048[index][j]);

			index--;
		}
	}
	cal(n, _2048);
}