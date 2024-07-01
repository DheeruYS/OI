#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105
 
int main() {
    
    fast;
 
    ll n;
    cin in n;
 
    vi x,y;
 
    fo(i,1,n){
        ll a,b;
        cin in a in b;
 
        x.pb(a);
        y.pb(b);
    }
 
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
 
    ll ind = n/2;
 
    cout out x[ind] space y[ind];
 
    return 0;
}
