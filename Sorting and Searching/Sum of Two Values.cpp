#include <bits/stdc++.h>
using namespace std;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
 
 
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++)  cin >> v[i];
 
    vector<pair<int,int>>p(n);
    for(int i=0; i<n; i++){
            p[i].first = v[i];
            p[i].second = i;
    }
    sort(p.begin(), p.end());
    
    int i = 0, j = n - 1;
    while( i <= j){
 
        if(p[i].first + p[j].first == x && i != j){
            cout << p[i].second + 1 << " " << p[j].second + 1 << endl;
            return;
        }
        if(p[i].first + p[j].first < x) i++;
        else j--;
    }
 
    cout << "IMPOSSIBLE" << endl;
 
 
}
 
int main()
{
    optimize();
 
    solve();
}
