#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 50000+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> adj[N] , level(N);
vector<vector<ll>> up(N,vector<ll>(log2(N)+5));

void dfs1(ll s , ll p){

	for(auto u : adj[s]){
		if(u == p) continue;

		level[u] = level[s]+1;
		up[u][0] = s;
		for(ll i = 1; i <= log2(N); i++) up[u][i] = up[up[u][i-1]][i-1];

		dfs1(u,s);
	}

}

ll jump(ll a , ll d){
	for(ll i = 0; i <= log2(N); i++){
		if(d&(1ll<<i)){
			a = up[a][i];
		}
	}
	return a;
}

ll lca(ll a  , ll b){
	if(level[a] > level[b]) swap(a,b);
	b = jump(b,level[b]-level[a]);

	if(a == b) return a;

	for(ll i = log2(N); i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}

	return up[a][0];
}

vector<ll> cnt(N) , sub(N);

void dfs2(ll s , ll p){

	sub[s] = cnt[s];

	for(auto u : adj[s]){
		if(u == p) continue;
		dfs2(u,s);
		sub[s] += sub[u];
	}
}

void solve(){

	ll n,k;
	cin >> n >> k;

	for(ll i = 1; i < n; i++){
		ll a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs1(1,0);

	while(k--){
		ll a,b;
		cin >> a >> b;

		cnt[a]++;
		cnt[b]++;
		cnt[lca(a,b)]--;
		cnt[up[lca(a,b)][0]]--;
	}

	dfs2(1,0);

	ll ans = -INF;
	for(ll i = 1; i <= n; i++) ans = max(ans,sub[i]);

	cout << ans;
}

int main(){

	fast;

	freopen("maxflow.in","r",stdin);
	freopen("maxflow.out","w",stdout);

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
