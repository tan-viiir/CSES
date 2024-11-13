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
 
ll n, k;
bool check(ll mid, vl& v){
    ll left = 0;
    ll spawned = 0;
    
    range(i, 0, n-1){
        if(left >= v[i])
            left -= v[i];
        else{
            spawned++;
            if(spawned > k)
                return 0;
            left = mid;
            if(left >= v[i])
                left -= v[i];
            else return 0;
        }
    }
    return 1;
    
}
 
void Solve() {
    cin >> n >> k;
    vl v(n);
    vinput;
    
    ll l = 0, r = 1e18, ans = -1;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        
        if(check(mid, v)){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}
 
int main() {
    optimize();
    
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    
    return 0;
}