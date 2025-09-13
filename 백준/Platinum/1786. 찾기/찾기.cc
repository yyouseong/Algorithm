#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> makeLps(const string &B)
{
    vector<int> lps(B.size(), 0);
    int j = 0;

    for (int i = 1; i < lps.size(); i++)
    {
        while (j > 0 && B[i] != B[j])
            j = lps[j - 1];
        if (B[i] == B[j])
        {
            j++;
            lps[i] = j;
        }
    }
    return lps;
}

vector<int> kmp(const string &A, const string &B)
{
    vector<int> lps = makeLps(B);

    int start, j = 0;
    vector<int> list;
    for (int i = 0; i < A.size(); i++)
    {
        while (j > 0 && A[i] != B[j])
            j = lps[j - 1];

        if (A[i] == B[j])
        {
            if (j == B.size() - 1)
            {
                list.push_back(i - j + 1);
                j = lps[j];
            }
            else
                j++;
        }
    }
    return list;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    getline(cin, A, '\n');
    getline(cin, B, '\n');

    vector<int> list = kmp(A, B);
    cout << list.size() << '\n';
    for (int &i : list)
        cout << i << ' ';

    return 0;
}