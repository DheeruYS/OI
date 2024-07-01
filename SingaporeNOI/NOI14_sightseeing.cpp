#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define rfo(i,a,b) for(ll i = a; i >= b; i--)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 500005
 
vi parent(N);
 
void make_set(ll n){
	fo(i,1,n) parent[i] = i;
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
 
vector<pll> new_adj[N];
vi dist(N);
 
void dfs(ll s , ll p){
 
	for(auto u : new_adj[s]){
		if(u.first == p) continue;
 
		dist[u.first] = min(dist[s],u.second);
		dfs(u.first,s);
	}
}
 
int main() {
    
    fast;
 
	ll n,m,q;
	cin in n in m in q;
 
	vector<tuple<ll,ll,ll>> edges;
 
	fo(i,1,m){
		ll a,b,c;
		cin in a in b in c;
 
		edges.pb(make_tuple(c,a,b));
	}
 
	make_set(n);
	sort(edges.rbegin(),edges.rend());
 
	for(auto u : edges){
 
		ll a = get<1>(u);
		ll b = get<2>(u);
		ll c = get<0>(u);
 
		if(add_edge(a,b)){
			new_adj[a].pb(mp(b,c));
			new_adj[b].pb(mp(a,c));
		}
	}
 
	dist[1] = INF;
	dfs(1,-1);
 
	while(q--){
		ll x;
		cin in x;
 
		cout out dist[x] nextline;
	}
 
    return 0;
}
