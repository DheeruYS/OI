#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	cin >> n >> m;

	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i];

	vector<ll> w(m+5);
	for(ll i = 1; i <= m; i++) cin >> w[i];

	set<ll> space;
	for(ll i = 1; i <= n; i++) space.insert(i);
	vector<ll> occupied(m+5);

	queue<ll> q;
	ll ans = 0;

	for(ll i = 1; i <= 2*m; i++){
		ll x;
		cin >> x;

		if(x > 0){
			if(!space.size()) q.push(x);
			else{
				auto it = space.begin();
				ll y = (*(it));
				ans += a[y]*w[x];
				space.erase(space.begin());
				occupied[x] = y;
			}
		}
		else{
			x *= -1;
			space.insert(occupied[x]);
			if(q.size()){
				ll y = q.front();
				q.pop();
				auto it = space.begin();
				ll z = (*(it));
				ans += a[z]*w[y];
				space.erase(space.begin());
				occupied[y] = z;
			}
		}
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
