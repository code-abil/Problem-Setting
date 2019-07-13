#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,q;
    cin>>n;
    for(int k=1;k<=10;k++)
    {
        ofstream out;
        string file="skewed_tree_tcs/tc"+to_string(k)+".txt";
        out.open(file);
        out<<n<<" "<<n<<"\n";
        for(int i=1;i<=n-1;i++){
            out<<i<<" "<<i+1<<"\n";
        }
        for(int j=1;j<=n;j++)
            out<<k<<" "<<j<<"\n";
    }
}
