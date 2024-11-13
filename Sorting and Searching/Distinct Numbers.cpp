#include <bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
 
// Debug..
#ifdef LOCAL
#include "debug.h"
#endif
 
void Tanvir() {
    int n;
    cin >> n;
    set<int>st;
    for(int i=0; i<n; i++){
        int a;  cin >> a;
        st.insert(a);
    }
    
    cout << st.size();
    
}
 
int main() {
    optimize();
    
    int t = 1;
    // cin >> t;
    while (t--) Tanvir();
    // for (int i = 1; i <= t; ++i) { // Kickstart
    //     cout << "Case #" << i << ": "; Tanvir();
    // }
    return 0;
}
