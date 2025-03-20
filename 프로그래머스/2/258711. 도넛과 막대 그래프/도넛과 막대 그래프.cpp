#include <iostream>
#include <vector>
#define MaxN 1000001
using namespace std;

int Find(vector<vector<int> > &Graph, int cur)
{
    if(Graph[cur].empty()) return 2;
    if(Graph[cur].size() == 2) return 3;
    if(Graph[cur][0] == 0) return 1;
    
    for(int j=0;j<Graph[cur].size();j++)
    {
        if(Graph[cur][j]){
            int t = Graph[cur][j];
            Graph[cur][j] = 0;

            return Find(Graph, t);
        }
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4,0);
    vector<bool> ChkY(MaxN,0);
    vector<vector<int> > Graph(MaxN,vector<int>());
    int node_one = 0;
    
    for(int i=0;i<edges.size();i++){
        int x = edges[i][0];
        int y = edges[i][1];
        
        ChkY[y] = true;
        Graph[x].push_back(y);
    }
    
    for(int i=0;i<MaxN;i++) 
        if(Graph[i].size()>Graph[node_one].size() && ChkY[i] == 0) node_one = i;
    answer[0] = node_one;
    
    for(int j=0;j<Graph[node_one].size();j++)
        answer[Find(Graph, Graph[node_one][j])]++;

    return answer;
}