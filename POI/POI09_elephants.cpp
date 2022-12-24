#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<ll> w(n+5),a(n+5),b(n+5),pos(n+5);
	ll minw = INF;

	for(ll i = 1; i <= n; i++){
		cin >> w[i];
		minw = min(minw,w[i]);
	}
	for(ll i = 1; i <= n; i++) cin >> a[i];
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
		pos[b[i]] = i;
	}

	vector<bool> visited(n+5,false);
	ll ans = 0;

	for(ll i = 1; i <= n; i++){
		if(visited[a[i]] || a[i] == b[i]) continue;

		ll x = a[i];
		ll y = b[i];
		ll cnt = 0;
		ll minc = INF;
		ll sum = 0;

		while(x != y){
			cnt++;
			minc = min(minc,w[x]);
			sum += w[x];
			visited[x] = true;
			x = a[pos[x]];
		}
		cnt++;
		minc = min(minc,w[x]);
		sum += w[x];
		visited[x] = true;

		ans += min(sum+(cnt-2)*minc,sum+minc+(cnt+1)*minw);
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
