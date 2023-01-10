#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll l,n,rf,rb;
	cin >> l >> n >> rf >> rb;

	vector<pair<ll,ll>> stop(n+5);
	for(ll i = 1; i <= n; i++) cin >> stop[i].first >> stop[i].second;

	vector<pair<ll,ll>> rest;
	ll maxi = -INF;

	for(ll i = n; i >= 1; i--){
		if(stop[i].second > maxi){
			rest.push_back(stop[i]);
			maxi = max(maxi,stop[i].second);
		}
	}

	reverse(rest.begin(),rest.end());

	ll ans = 0 , last = 0;

	for(auto u : rest){
		ll x = u.first;
		ll c = u.second;

		ll oldtime = last*rf;
		ll newjohntime = oldtime+(last-x)*rf;
		ll newbessietime = oldtime+(last-x)*rb;

		ans += c*(newbessietime-newjohntime);
		last = x; 
	}

	cout << ans;
}

int main(){

	fast;

	
	freopen("reststops.in","r",stdin);
	freopen("reststops.out","w",stdout);
	

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
