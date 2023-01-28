#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 1e5+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> adj[N] , level(N) , tin(N);
ll timer = 0;
vector<vector<ll>> up(N,vector<ll>(log2(N)+5));

void dfs1(ll s , ll p){

	timer++;
	tin[s] = timer;

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

ll lca(ll a , ll b){

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

bool comp(ll a , ll b){
	return tin[a] < tin[b];
}

vector<ll> cnt(N),sum(N);

void dfs2(ll s , ll p){

	sum[s] = cnt[s];
	for(auto u : adj[s]){
		if(u == p) continue;
		dfs2(u,s);
		sum[s] += sum[u];
	}
}

void solve(){

	ll n,m,k;
	cin >> n >> m >> k;

	vector<tuple<ll,ll,ll>> edge;

	for(ll i = 1; i < n; i++){
		ll a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);

		edge.push_back(make_tuple(a,b,i));
	}

	level[1] = 0;
	for(ll i = 0; i <= log2(N); i++) up[1][i] = 0;
	dfs1(1,0);

	for(ll i = 1; i <= m; i++){
		ll s;
		cin >> s;

		vector<ll> node;
		for(ll j = 1; j <= s; j++){
			ll x;
			cin >> x;

			node.push_back(x);
		}

		sort(node.begin(),node.end(),comp);

		node.push_back(node[0]);

		for(ll i = 1; i <= s; i++){
			ll a = node[i-1];
			ll b = node[i];
			ll l = lca(a,b);

			cnt[a]++;
			cnt[b]++;
			cnt[l] -= 2;
		}
	}

	dfs2(1,0);

	vector<ll> ans;

	for(auto u : edge){
		ll a,b,ind;
		tie(a,b,ind) = u;

		if(level[a] > level[b]) swap(a,b);
		ll cur = sum[b];
		cur /= 2;

		if(cur >= k){
			ans.push_back(ind);
		}
	}

	cout << ans.size() << "\n";
	for(auto u : ans) cout << u << " ";
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
