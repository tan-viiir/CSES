#include <bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) x.begin(),x.end()
 
typedef vector<int> vi;
 
void Solve() {
    int n;
    cin >> n;
    vi v(n);
    
    // Input array
    for (auto& x : v) cin >> x;
    
    // Sliding window and map to count occurrences
    map<int, int> mp;
    int maxLength = 0;  // Maximum length of distinct subsequence
    int left = 0;       // Left pointer of the window
    
    // Traverse through the array
    for (int right = 0; right < n; right++) {
        mp[v[right]]++;  // Include the current element
        
        // If a duplicate is found, move the left pointer to make the window valid
        while (mp[v[right]] > 1) {
            mp[v[left]]--;
            if (mp[v[left]] == 0) {
                mp.erase(v[left]);  // Remove the element if its count becomes 0
            }
            left++;  // Shrink the window
        }
        
        // Update the maximum length
        maxLength = max(maxLength, right - left + 1);
    }
    
    // Output the maximum length of the subsequence
    cout << maxLength ;
}
 
int main() {
    optimize();
    
    int t = 1;
    // Uncomment if multiple test cases
    // cin >> t;
    while (t--) Solve();
    
    return 0;
}