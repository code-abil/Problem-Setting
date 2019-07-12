#include<bits/stdc++.h>
using namespace std;
vector<int>edges[100005];
vector<int>level_nodes[100005];
vector<int>start(100005),finish(100005),level(100005);
int counter=0;
void dfs(int s,int parent=-1,int _level=0)
{
    counter++;
    start[s]=counter;
    level_nodes[_level].push_back(counter);
    level[s]=_level;
    for(auto x:edges[s])
    {
        if(x!=parent)
            dfs(x,s,_level+1);
    }
    finish[s]=counter;
}
main()
{   
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    for(int i=0;i<=n;i++)
        sort(level_nodes[i].begin(),level_nodes[i].end());
    while(q--)
    {
        int node,depth;
        cin>>node>>depth;   
        int _level=level[node]+depth;
        if(_level>n)
        {
           cout<<0<<"\n";
            continue;
        }
        auto r=upper_bound(level_nodes[_level].begin(),level_nodes[_level].end(),finish[node]);
        auto l=lower_bound(level_nodes[_level].begin(),level_nodes[_level].end(),start[node]);
        cout<<r-l<<"\n";
    }
}