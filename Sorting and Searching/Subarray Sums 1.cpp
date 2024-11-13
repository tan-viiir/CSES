#include<bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
 
const long long mx = 2e5+123;
long long a[mx], sum[mx];
 
int main()
{
    optimize();
 
    int n, x;
    cin >> n >> x;
    for(int i=1; i <= n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) sum[i] = a[i] + sum[i-1];
 
    map<long long, int>cnt;
    for(int i=0; i<=n; i++) cnt[sum[i]]++;
 
    long long ans = 0;
    for(int i=n; i >= 1; i--){
        cnt[sum[i]]--;
        long long sub = sum[i] - x;
        ans += cnt[sub];
    }
 
    cout << ans << endl;   
 
}