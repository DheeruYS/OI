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
#define rfo(i,a,b) for(ll i = a; i >= b; i--)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105
 
int main() {
    
    fast;
 
	ll n;
	cin in n;
 
	vector<pll> h(n+5);
	fo(i,1,n){
		cin in h[i].first;
		h[i].second = i;
	}
	sort(h.begin()+1,h.begin()+n+1);
 
	ll ans = 1;
	ll island = 1;
	
	vector<bool> added(n+5,false);
	fo(i,1,n) added[i] = true;
 
	for(ll i = 1; i <= n;){
 
		ll x = h[i].first;
 
		while(h[i].first == x && i <= n){
		
			added[h[i].second] = false;
 
			if(added[h[i].second-1] == added[h[i].second+1]){
				if(added[h[i].second-1] == false) island--;
				else island++;
			}
 
			i++;
		}
 
		mmax(ans,island);
	}
 
	cout out ans;
 
    return 0;
}
