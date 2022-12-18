#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 500+5 , INF = 1e18 , MOD = 1e9+7;

ll m;

ll expo(ll a , ll b ){
	if(b == 0) return 1;
	if(b == 1) return a;

	ll p = expo(a,b/2);

	if(b%2 == 0) return (p*p)%m;
	return (((p*p)%m)*a)%m;
}

ll cost(ll x , ll y){

	ll score = expo(x,y);
	score = (score+expo(y,x))%m;

	return score;
}

vector<ll> parent(N);

void make_set(ll n){
	for(ll i = 1; i <= n; i++) parent[i] = i;
}

ll find(ll x){
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool add_edge(ll a , ll b){
	a = find(a);
	b = find(b);

	if(a == b) return false;

	parent[b] = a;
	return true;
}

void solve(){

	ll n;
	cin >> n >> m;

	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i];

	vector<tuple<ll,ll,ll>> edge;

	for(ll i = 1; i <= n; i++){
		for(ll j = i+1; j <= n; j++){
			edge.push_back(make_tuple(cost(a[i],a[j]),i,j));
		}
	}

	sort(edge.rbegin(),edge.rend());

	make_set(n);

	ll ans = 0;

	for(auto u : edge){
		ll w,a,b;
		tie(w,a,b) = u;

		if(add_edge(a,b)){
			ans += w;
		}
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
