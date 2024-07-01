#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

ll n;
vector<pair<ll,ll>> adj[240];

ll dijkstra(ll s){

	vi dist(n+5,INF);
	priority_queue<pair<ll,ll>> q;
	vector<bool> visited(n+5,false);

	dist[s] = 0;
	q.push({0,s});

	while(!q.empty()){

		ll a = q.top().second;
		q.pop();

		if(visited[a] == true) continue;
		visited[a] = true;

		for(auto u : adj[a ]){
			
			ll b = u.first;
			ll w = u.second;

			if(dist[a]+w < dist[b]){
				dist[b] = dist[a]+w;
				q.push({-dist[b],b});
			}
		}
	}

	ll ans = -INF;

	fo(i,0,n-1){
		if(dist[i] != INF ) mmax(ans,dist[i]);
	}

	return ans;

}

int main() {

	ll m;
	cin in n in m;
	
	fo(i,0,m-1){
		ll x,y,p;
		cin in x in y in p;

		adj[x-1].pb(mp(y-1,p));
		adj[y-1].pb(mp(x-1,p));
	}

	ll ans = -INF;

	fo(i,0,n-1){
		mmax(ans,dijkstra(i));
	}

	cout out ans;

	return 0;

}
