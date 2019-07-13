#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<int>edges[100005];
int ans=0,curr_node,d;
void dfs(int s,int parent=-1,int dist=0,bool child=false)
{

    if(s==curr_node)    child=true;
    if(child && dist==d){
        ans++;
    }
    dist=(child)?dist+1:0;
    for(auto x:edges[s])
    {
        if(x!=parent)
        {
            dfs(x,s,dist,child);
        }
    }
}
main()
{
    // ifstream in;
    // ofstream out;
    // in.open("Test-cases/tc1.txt");
    // out.open("output.txt");
    int n,q;
    cin>>n>>q;
    // in>>n>>q;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // auto start = high_resolution_clock::now();
    while(q--)
    {
        ans=0;
        cin>>curr_node>>d;
        dfs(1);
        cout<<ans<<"\n";
    }
    // auto stop = high_resolution_clock::now(); 
    // auto duration = duration_cast<microseconds>(stop - start); 
    // cout << "Time taken by program: "
    //      << duration.count() << " microseconds" << endl; 
  
}
/*
7 10
1 2
1 3
2 4
2 5
3 6
3 7
*/