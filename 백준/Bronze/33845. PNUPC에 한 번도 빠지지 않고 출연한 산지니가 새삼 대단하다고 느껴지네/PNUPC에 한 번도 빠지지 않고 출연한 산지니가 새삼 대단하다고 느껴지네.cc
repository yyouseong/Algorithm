#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string name,str;
    cin>>name>>str;

    vector<bool> CHK(30,0);
    for(char c:name) CHK[c-'a'] = 1;
    for(char c:str) if(CHK[c-'a'] == 0) cout<<c;

    return 0;
}