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
#define debug(x...)
#endif
 
void Solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    
    sort(all(a));
    sort(all(b));
    int i=0, j=0, ans=0;
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
            i++;
            j++;
            ans++;
        }
        else if(a[i] - b[j] > k)
            j++;
        else
            i++;
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