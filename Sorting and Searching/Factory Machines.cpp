#include <bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define range(i,x,y) for(int i=x;i<=y;i++)
 
typedef vector<ll> vl;
 
ll n, p;
 Factory Machines
// Check function to determine if 'mid' time can produce at least 'p' products
bool check(ll t, vl &v) {
    ll products = 0;
    for (auto u : v) {
        products += t / u;
        if (products >= p) return true; // Early exit if we have enough products
    }
    return products >= p; // Check if total products meet the requirement
}
 
void Solve() {
    cin >> n >> p;
    vl v(n);
    for (auto &x : v) cin >> x;
 
    // Determine the maximum time 'r' needed for the search range
    ll l = 0, r = 1e18, ans = -1; // Increase the upper bound to 1e18
    while (l <= r) {
        ll mid = l + (r - l) / 2; // Avoid potential overflow
 
        if (check(mid, v)) {
            ans = mid; // Record valid mid value
            r = mid - 1; // Search in the left half
        } else {
            l = mid + 1; // Search in the right half
        }
    }
    cout << ans << endl; // Print the minimum time required
}
 
int main() {
    optimize();
 
    int t = 1;
    // cin >> t;
    while (t--) Solve();
 
    return 0;
}