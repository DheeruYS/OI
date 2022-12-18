#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 2e5+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> color(N,-1);
vector<bool> visited(N,false);
bool bipartite = true;
ll black,white;
vector<ll> adj[N];

void dfs(ll s , ll c){

	visited[s] = true;
	color[s] = c;

	if(c) black++;
	else white++;

	for(auto u : adj[s]){

		if(color[u] == c){
			bipartite = false;
			return;
		}
		if(visited[u]) continue;
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

	ll ans = (n*(n-1))/2;

	for(ll i = 1; i <= n; i++){

		if(visited[i]) continue;		

		black = 0 , white = 0;

		dfs(i,0);

		ans -= (black*(black-1))/2;
		ans -= (white*(white-1))/2;
	}

	ans -= m;

	if(bipartite) cout << ans;
	else cout << "0";
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
