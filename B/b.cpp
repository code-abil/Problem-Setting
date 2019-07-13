#include<bits/stdc++.h>
#define ll long long
using namespace std;
main()
{
    int n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll max_chips=0;
    for(int i=0;i<k;i++)
        max_chips+=a[i];
    ll chips_in_hand=max_chips;
    for(int i=k;i<n;i++){
        chips_in_hand+=(a[i]-a[i-k]);
        max_chips=max(max_chips,chips_in_hand);
    }
    cout<<max_chips<<"\n";
}

