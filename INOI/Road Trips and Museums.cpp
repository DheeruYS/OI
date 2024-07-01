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

vi adj[1000005];
vector<bool> visited(1000005, false);
ll museum = 0;
vi mu(1000005);

void dfs(ll s) {
	if (visited[s] == true) return;
	visited[s] = true;
	museum += mu[s];
	for (auto u : adj[s]) dfs(u);
}

int main() {
	
	tc{
		ll n, m, k;
		cin in n in m in k;

		fo(i, 0, m - 1) {
			ll x, y;
			cin in x in y;
			x--; y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		fo(i, 0, n - 1) cin in mu[i];

		vi mcount(0);

		fo(i, 0, n - 1) {
			if (visited[i] == true ) continue;
			museum = 0;
			dfs(i);
			mcount.pb(museum);
		}

		if (mcount.size() < k) {
			cout out "-1\n";
		}
		else{
			sort(mcount.rbegin(), mcount.rend());
			ll low = 0 , high = mcount.size() - 1, who = 0;
			ll ans = 0;

			while (low <= high && k > 0) {

				if (who % 2 == 0) {
					ans += mcount[low];
					low++;
				}
				else {
					ans += mcount[high];
					high--;

				}

				k--;
				who++;
			}

			cout out ans nextline;
		}

		fo(i, 0, n - 1) {
			adj[i].clear();
			visited[i] = false;
		}

	}

	return 0;

}
