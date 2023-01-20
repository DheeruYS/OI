#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 2e5+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> adj[N];
vector<vector<ll>> dp(N,vector<ll>(2));

void dfs(ll s , ll p){

	for(auto u : adj[s]){
		if(u == p) continue;
		dfs(u,s);
	}

	ll x = adj[s].size();

	// have taken previous edge

	if(s != 1){
		dp[s][1] = adj[s].size()-1;
		for(auto u : adj[s]){
			if(u == p) continue;
			dp[s][1] = max(dp[s][1],x-2+dp[u][1]);
		}
	}

	// have not yet taken previous edge

	dp[s][0] = 0;
	ll mx1 = -INF , mx2 = -INF;

	for(auto u : adj[s]){
		if(u == p) continue;
		dp[s][0] = max(dp[s][0],dp[u][0]);
		if(dp[u][1] > mx1){
			mx2 = mx1;
			mx1 = dp[u][1];
		}
		else if(dp[u][1] > mx2) mx2 = dp[u][1];
	}

	dp[s][0] = max(dp[s][0],x-1+mx1);
	dp[s][0] = max(dp[s][0],x-2+mx1+mx2);
}

void solve(){

	ll n;
	cin >> n;

	for(ll i = 1; i < n; i++){
		ll a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1,0);
	cout << max(dp[1][0],dp[1][1]);
}

int main(){

	fast;

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
