#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<ll> adj[n+5];

	for(ll i = 1; i <= n; i++){
		ll x;
		cin >> x;

		for(ll j = 1; j <= x; j++){
			ll a;
			cin >> a;

			adj[a].push_back(i);
		}
	}

	ll ans = INF;

	for(ll root = 1; root <= n; root++){

		vector<ll> depth(n+5,-1);
		queue<ll> q;
		ll cost = 1 , cnt = 1;

		depth[root] = 1;
		q.push(root);

		while(q.size()){
			ll a = q.front();
			q.pop();

			for(auto u : adj[a]){
				if(depth[u] == -1){
					depth[u] = depth[a]+1;
					cost += depth[u];
					cnt++;
					q.push(u);
				}
			}
		}

		if(cnt == n) ans = min(ans,cost);
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
