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
 
#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#define dg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dg(x)
#endif
 
const int mx = 2e5+123;
vi pre(mx);
bool vis[mx];
 
 
ll step(ll n){
    ll step = 0;
    while(n > 0){
        n /= 3; 
        step++;
    }
    return step;
}
 
//Solution Starts from here...
ll st[4*mx];
void build(ll node, ll l, ll r, vector<ll>&v){
    if(l == r){
        st[node] = v[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(node*2, l, mid, v);
    build(node*2+1, mid+1, r, v);
    
    st[node] = min(st[node*2], st[node*2+1]);
}
 
void update(ll node, ll l, ll r, ll pos, ll val){
    if(l == r){
        st[node] = val;
        return;
    }
    ll mid = (l+r)/2;
    if(pos <= mid){
        update(node*2, l, mid, pos, val);
    }
    else{
        update(node*2+1, mid+1, r, pos, val);
    }
    st[node] = min(st[node*2], st[node*2+1]);
}
 
ll query(ll node, ll l, ll r, ll i, ll j){
    if(i > r || j < l)
        return LLONG_MAX;
    if(i <= l && j >= r)
        return st[node];
    ll mid = (l+r)/2;
    
    ll a = query(node*2, l, mid, i, j);
    ll b = query(node*2+1, mid+1, r, i, j);
    return min(a, b);
}
 
void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n+1);
    for(ll i=1; i<=n; i++) cin >> v[i];
    build(1, 1, n, v);
    while(m--){
        ll tp;
        cin >> tp;
        if(tp == 1){
            ll k, u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        }
        else{
            ll a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
            
        }
    }
}
 
int main() {
    optimize();
    
    int t = 1;
    while (t--) Solve();
    
    return 0;
}