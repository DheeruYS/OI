#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;
 
void solve(){
 
	ll n;
	cin >> n;
 
	unordered_map<ll,ll> x,y;
	vector<pair<ll,ll>> a(n+5);
 
	for(ll i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
 
		x[a[i].first]++;
		y[a[i].second]++;
	}
 
	ll cnt = 0;
	for(ll i = 1; i <= n; i++) cnt += (x[a[i].first]-1)*(y[a[i].second]-1);
 
	cout << cnt;
}
 
int main(){
 
	fast;
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
