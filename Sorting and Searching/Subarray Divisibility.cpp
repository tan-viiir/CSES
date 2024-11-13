#include <bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define vinput for(auto& x: v) cin >> x;
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define range(i,x,y) for(int i=x;i<=y;i++)
#define range_back(i,x,y) for(int i=y;i>=x;i--)
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
 
#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#define dg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dg(x)
#endif
 
void Solve() {
    int n;
    cin >> n;
    vl v(n);
    vinput;
    
    ll sum = 0;
    vl cnt(n, 0);
    for(auto u: v){
        sum += (u % n + n) % n;
        cnt[sum % n]++;
    }
    ll result = cnt[0];
    for(auto u: cnt){
        result += (u * (u-1)) / 2;
    }
    
    cout << result << endl;
}
 
int main() {
    optimize();
    
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    
    return 0;
}