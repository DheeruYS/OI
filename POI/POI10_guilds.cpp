#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 2e5+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> adj[N] , color(N,-1);

void dfs(ll s , ll c){

	if(color[s] != -1) return;
	color[s] = c;

	for(auto u : adj[s]){
		if(color[u] != -1) continue;
		dfs(u,c^1);
	}

}

void solve(){

	ll n,m;
	cin >> n >> m;

	for(ll i = 1; i <= m; i++){
		ll a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(ll i = 1; i <= n; i++){
		if(adj[i].size() == 0){
			cout << "NIE";
			return;
		}
		dfs(i,0);
	}

	cout << "TAK\n";
	for(ll i = 1; i <= n; i++){
		if(color[i]) cout << "S\n";
		else cout << "K\n";
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
