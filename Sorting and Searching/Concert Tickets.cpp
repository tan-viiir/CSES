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
 
const int mx = 1e6+123;
vi pre(mx);
bool vis[mx];
 
void Solve() {
    int n, m;
    cin >> n >> m;
    multiset<int>tickets;
    range(i, 0, n){
        int x;
        cin >> x;
        tickets.insert(x);
    }
    range(i, 0, m){
        int t;
        cin >> t;
        
        auto it = tickets.upper_bound(t);
        if(it == tickets.begin()){
            cout << -1 << endl;
        }
        else{
            cout << *(--it) << endl;
            tickets.erase(it);
        }
    }
}
 
int main() {
    optimize();
    
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    
    return 0;
}