#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 1e5+5 , INF = 1e18 , MOD = 1e9+7;
 
vector<ll> par(N),len(N);
 
void make_set(ll n){
	for(ll i = 1; i <= n; i++){
		par[i] = i;
		len[i] = 0;
	}
}
 
pair<ll,ll> get(ll x){
	if(x == par[x]) return make_pair(x,0);
 
	pair<ll,ll> u = get(par[x]);
	par[x] = u.first;
	len[x] = (len[x]+u.second)%2;
 
	return make_pair(par[x],len[x]);
}
 
void add_edge(ll a , ll b , ll c){
 
	pair<ll,ll> x = get(a);
	pair<ll,ll> y = get(b);
 
	if(x.first == y.first) return;
 
	par[x.first] = y.first;
	len[x.first] = (x.second+c+y.second)%2;
}
 
void solve(){
 
	ll n,q;
	cin >> n >> q;
 
	make_set(n);
 
	while(q--){
		char x;
		ll a,b;
		cin >> x >> a >> b;
 
		if(x == 'R'){
			add_edge(a,b,0);
		}
		else if(x == 'A'){
			add_edge(a,b,1);
		}
		else{
			pair<ll,ll> x = get(a);
			pair<ll,ll> y = get(b);
 
			if(x.first != y.first) cout << "?\n";
			else{
				if((x.second+y.second)%2 == 0) cout << "R\n";
				else cout << "A\n";
			}
		}
	}
 
}
 
int main(){
 
	fast;
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
