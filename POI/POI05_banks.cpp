#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 1e6+2 , INF = 1e9 , MOD = 1e9+7;

bool cycle;
ll cc = 0;
ll visited[N] , par[N];

void dfs(ll s){

	if(visited[s] != -1) return;
	visited[s] = cc;

	ll u = par[s];

	if(visited[u] == cc){
		cycle = true;
		return;
	}
	if(cycle) return;

	dfs(u);
}

void solve(){

	ll n;
	cin >> n;

	memset(visited,-1,sizeof visited);
	for(ll i = 1; i <= n; i++) cin >> par[i];

	ll ans = 0;

	for(ll i = 1; i <= n; i++){
		if(visited[i] != -1) continue;

		cycle = false;
		cc++;
		dfs(i);
		if(cycle) ans++;
	}

	cout << ans;
}

int main(){

	fast;

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
