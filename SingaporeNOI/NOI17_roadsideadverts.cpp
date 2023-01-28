#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 50000+5 , INF = 1e18 , MOD = 1e9+7;

vector<pair<ll,ll>> adj[N];
vector<vector<ll>> up(N,vector<ll>(log2(N)+5));
vector<ll> level(N) , tin(N) , dist(N);
ll timer = 0;

void dfs(ll s , ll p){

	timer++;
	tin[s] = timer;

	for(auto u : adj[s]){

		if(u.first == p) continue;

		level[u.first] = level[s]+1;
		dist[u.first] = dist[s]+u.second;

		up[u.first][0] = s;
		for(ll i = 1; i <= log2(N); i++) up[u.first][i] = up[up[u.first][i-1]][i-1];

		dfs(u.first,s);
	}
}

ll jump(ll a , ll k){
	for(ll i = 0; i <= log2(N); i++){
		if(k&(1ll<<i)){
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

ll distanc(ll a , ll b){
	return dist[a]+dist[b]-2*dist[lca(a,b)];
}

bool comp(ll a , ll b){
	return tin[a] < tin[b];
}

void solve(){

	ll n;
	cin >> n;


	for(ll i = 1; i < n; i++){
		ll a,b,c;
		cin >> a >> b >> c;

		a++;b++;

		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}

	dist[1] = 0;
	level[1] = 0;
	for(ll i = 0; i <= log2(N); i++) up[1][i] = 0;

	dfs(1,0);

	ll q;
	cin >> q;

	while(q--){
		vector<ll> nodes;
		for(ll i = 1; i <= 5; i++){
			ll x;
			cin >> x;

			nodes.push_back(x+1);
		}

		sort(nodes.begin(),nodes.end(),comp);

		ll ans = 0;
		for(ll i = 1; i < 5; i++) ans += distanc(nodes[i],nodes[i-1]);
		ans += distanc(nodes[0],nodes[4]);

		ans /= 2;
		cout << ans << "\n"; 
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
