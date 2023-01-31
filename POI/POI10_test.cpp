#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	map<ll,vector<ll>> f;

	for(ll i = 1; i <= n; i++){
		ll x;
		cin >> x;
		f[x].push_back(i);
	}

	ll tc;
	cin >> tc;

	while(tc--){
		ll m;
		cin >> m;

		bool possible = true;
		ll cur = 0;

		for(ll i = 1; i <= m; i++){
			ll x;
			cin >> x;

			if(!possible) continue;

			auto it = upper_bound(f[x].begin(),f[x].end(),cur);
			if(it == f[x].end()){
				possible = false;
				continue;
			}

			cur = (*(it));
		}

		if(!possible) cout << "NIE\n";
		else cout << "TAK\n";
	}
}

int main(){

	fast;

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
