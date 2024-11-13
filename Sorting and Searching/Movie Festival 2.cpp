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
#define mem(a,b) memset(a, b, sizeof(a))
 
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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].ff >> movies[i].ss;
    }
 
    // Sort movies by end time to maximize the usage of each person
    sort(all(movies), sort_by_second);
    dg(movies);
 
    int cnt = 0;
    multiset<int> st; // Tracks the end times of movies currently being watched by people
 
    for (int i = 0; i < n; i++) {
        // Check for any person who has finished watching before this movie starts
        auto it = st.upper_bound(movies[i].ff);
 
        if (it != st.begin()) {
            // Move to the largest end time that is <= current start time
            --it;
            st.erase(it); // Remove the previous movie end time, freeing a slot
        } else if (st.size() >= k) {
            // If no free person and maximum people are already watching, skip
            continue;
        }
        
        // Assign the current movie to a person and add the new end time
        st.insert(movies[i].ss);
        cnt++;
    }
 
    cout << cnt << "\n";
}
 
int main() {
    optimize();
    
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    
    return 0;
}