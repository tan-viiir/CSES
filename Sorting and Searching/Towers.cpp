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
 
void Solve() {
    int n;
    cin >> n;
    vi v(n);
    vinput;
    
    vector<int>st;
    st.pb(v[0]);
    for(int i=1; i<n; i++){
        auto up = upper_bound(all(st), v[i]);
        if(up == st.end()){
            st.pb(v[i]);
        }
        else{
            int idx = up - st.begin();
            st[idx] = v[i];
        }
    }
    
    cout << st.size();
}
 
int main() {
    optimize();
    
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    
    return 0;
}