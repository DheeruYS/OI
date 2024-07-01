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

vi adj[100005];
ll cnt, minn, maxx;
vector<bool> visited(100005, false);

void dfs(ll s) {
	if (visited[s] == true) return;
	visited[s] = true;
	cnt++;
	mmin(minn, s);
	mmax(maxx, s);
	for (auto u : adj[s]) dfs(u);
}


ll sumodd = 0;
ll sumeven = 0;

vector<bool> visited1(100005,false);

void dfseven(ll s , ll parentlevel){

	if(visited1[s] == true) return;
	visited1[s] = true;
	ll thislevel = parentlevel+1;
	sumeven += thislevel;
	for(auto u : adj[s]) dfseven(u,thislevel);
}

void dfsodd(ll s , ll parentlevel){

	if(visited1[s] == true) return;
	visited1[s] = true;
	ll thislevel = parentlevel+1;
	sumodd += thislevel;
	for(auto u : adj[s]) dfsodd(u,thislevel);
}

int main() {

	tc{

		ll n, m;
		cin in n in m;

		fo(i, 0, m - 1) {
			ll x, y;
			cin in x in y;
			adj[x - 1].pb(y - 1);
			adj[y - 1].pb(x - 1);
		}

		vi odd(0);
		vi even(0);

		fo(i, 0, n - 1) {
			if (visited[i] == true) continue;

			cnt = 0;
			minn = INF;
			maxx = -INF;
			dfs(i);
			if (cnt % 2 == 0) {
				even.pb(minn);
			}
			else odd.pb(maxx);
		}

		for (auto i : even) {
			dfseven(i,0);
		}

		for (auto i : odd) {
			dfsodd(i,0);
		}

		cout out sumeven space sumodd nextline;

		fo(i,0,n-1){
			adj[i].clear();
			visited1[i] = false;
			visited[i] = false;
			sumodd = 0;
			sumeven = 0;
		}

	}

	return 0;

}
