#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 1e6+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> par(N) , ssize(N);

void make_set(ll n){
	for(ll i = 1; i <= n; i++){
		par[i] = i;
		ssize[i] = 1;
	}
}

ll find(ll x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

ll cnt = 0;

ll cost(ll z){
	return ((z*(z+1))/2);
}

void add_edge(ll a, ll b){

	a = find(a);
	b = find(b);

	if(a == b) return;

	cnt -= cost(ssize[a]);
	cnt -= cost(ssize[b]);
	cnt += cost(ssize[a]+ssize[b]);

	par[a] = b;
	ssize[b] += ssize[a];
}

void solve(){

	ll n,q;
	cin >> n >> q;

	vector<ll> a(n+5);
	vector<pair<ll,ll>> v;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		v.push_back(make_pair(a[i],i));
	}

	a[0] = INF;
	a[n+1] = INF;

	sort(v.begin(),v.end());
	make_set(n);

	vector<ll> ans(N);

	for(auto u : v){	
		cnt++;
		if(a[u.second-1] <= u.first) add_edge(u.second-1,u.second);
		if(a[u.second+1] <= u.first) add_edge(u.second,u.second+1);

		ans[u.first] = cnt;
	}

	for(ll i = 1; i <= N; i++) if(!ans[i]) ans[i] = ans[i-1];

	while(q--){
		ll x;
		cin >> x;

		cout << ans[x] << "\n";
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
