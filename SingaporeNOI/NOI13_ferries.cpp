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
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105
 
int main() {
    
    fast;
 
    ll n,m;
    cin in n in m;
 
	vi radj[n+5];
	vi weight[n+5];
 
    fo(i,1,m){
        ll a,b,c;
        cin in a in b in c;
 
		radj[b].pb(a);
		weight[a].pb(c);
    }
 
	fo(i,1,n) sort(weight[i].begin(),weight[i].end());
 
	vi dist(n+5,INF);
	priority_queue<pll> q;
	vector<bool> visited(n+5,false);
 
	q.push(mp(0,n));
	dist[n] = 0;
 
	while(!q.empty()){
 
		ll a = q.top().second;
		q.pop();
 
		if(visited[a]) continue;
		visited[a] = true;
 
		for(auto u : radj[a]){
 
			ll maxi = weight[u].back();
 
			if(dist[a]+maxi < dist[u]){
				dist[u] = dist[a]+maxi;
				q.push(mp(-dist[u],u));
			}
			
			weight[u].pop_back();
		}
	}
 
	cout out dist[1];
 
    return 0;
}
