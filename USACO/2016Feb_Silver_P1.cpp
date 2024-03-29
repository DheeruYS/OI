#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i];

	ll ans = INF;
	
	for(ll i = 1; i <= n; i++){
		ll cost = 0;
		bool possible = true;

		ll ind = i-1;
		queue<ll> q;

		for(ll j = 1; j <= n; j++){
			ind++;
			if(ind > n) ind = 1;

			if(a[ind] == 0){
				if(q.size() == 0){
					possible = false;
					break;
				}
				ll x = j-q.front();
				cost += (x*x);
				q.pop();
				continue;
			}

			for(ll k = 1; k <= a[ind]; k++) q.push(j);
			ll x = j-q.front();
			cost += (x*x);
			q.pop();
		}

		if(!possible) continue;
		ans = min(ans,cost);
	}

	cout << ans;
}

int main(){

	fast;

	freopen("cbarn.in","r",stdin);
	freopen("cbarn.out","w",stdout);

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
