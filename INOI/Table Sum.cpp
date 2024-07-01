#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
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
#define print(x) for(auto i : x ) cout out i.first spacef i.second out "     ";
#define mmax(x,i) x = max((x),(i))
#define mmin(x,i) x = min((x),(i))
#define N 105

int main() {

    fast;

    ll n;
    cin in n;

    vi a(n+5);
    fo(i,1,n) cin in a[i];

    multiset<ll> s;

    fo(i,1,n){
        s.insert(a[i] + i);
    }

    fo(i,0,n-1){
        cout out *s.rbegin() + i spacef;

        s.erase(s.find(a[n-i]+n-i));
        s.insert(a[n-i]-i);
    }

    return 0;
}
