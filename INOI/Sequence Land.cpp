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

vector<bool> visited(305);
ll cnt = 0;
vector<ll> adj[305];


void dfs(ll s) {
	if (visited[s] == true) return;
	visited[s] = true;
	cnt++;
	for (auto u : adj[s]) dfs(u);
}

int main() {

	ll n, k;
	cin in n in k;

	vector<ll> id[n+5];

	fo(i, 0, n - 1) {
		ll x;
		cin in x;
		while (x--) {
			ll y;
			cin in y;
			id[i].pb(y);
		}
		sort(id[i].begin(),id[i].end());
	}

	fo(i, 0, n - 1) {
		fo(j, i + 1, n - 1) {
			ll same = 0;
			for (auto ii : id[i]) {
				if (binary_search(id[j].begin(), id[j].end(), ii) == true) {
					same++;
					if (same >= k) break;
				}
			}

			if (same >= k) {
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}

	dfs(0);
	cout out cnt;

	return 0;

}
