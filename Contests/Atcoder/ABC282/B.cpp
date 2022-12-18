#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	cin >> n >> m;

	vector<ll> a(n+5);

	for(ll i = 1; i <= n; i++){
		ll cur = 0;

		for(ll j = 0; j < m; j++){
			char x;
			cin >> x;

			if(x == 'o') cur |= (1ll<<j);
		}

		a[i] = cur;
	}

	ll ans = 0;

	for(ll i = 1; i <= n; i++){
		for(ll j = i+1; j <= n; j++){
			ll c = a[i]|a[j];
			if(c == ((1ll<<m)-1)) ans++;
		}
	}

	cout << ans;
	
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
