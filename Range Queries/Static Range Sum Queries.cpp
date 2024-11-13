#include<bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
 
const int mx = 2e5+123;
ll a[mx], sum[mx];
 
int main()
{
    optimize();
 
    int n, q;
    cin >> n >> q;
 
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i-1];
 
    while(q--){
        int l, r;
        cin >> l >> r;
 
        cout << sum[r] - sum[l-1] << endl;
    }
    
 
}