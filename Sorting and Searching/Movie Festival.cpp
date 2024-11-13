#include <bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define ff first
#define ss second
#define sz size()
#define pb push_back
#define vinput for(auto& x: v) cin >> x;
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define range(i,x,y) for(int i=x;i<y;i++)
#define range_back(i,x,y) for(int i=y-1;i>=x;i--)
#define mem(a,b) memset(a, b, sizeof(a) )
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
 
// Debug..
#ifdef LOCAL
#include "debug2.h"
#else
#define dg(x...)
#endif
 
bool sort_by_second(const pair<int, int>& a, const pair<int, int>& b) {
return a.ss < b.ss;
}
 
void Solve() {
    int n;
    cin >> n;
    vector<pair<int, int>>p;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    
    sort(all(p), sort_by_second);
    dg(p);
    int cnt = 1, last = p[0].ss;
    for(int i=1; i<n; i++){
        if(last <= p[i].ff){
            cnt++;
            last = p[i].ss;
        }
    }
    cout << cnt;
}
 
int main() {
    optimize();
    
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    
    return 0;
}