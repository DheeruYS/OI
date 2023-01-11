#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m;
	cin >> n >> m;

	map<pair<ll,ll>,bool> impossible;

	for(ll i = 1; i <= m; i++){
		ll a,b;
		cin >> a >> b;

		impossible[make_pair(a,b)] = true;
		impossible[make_pair(b,a)] = true;
	}

	ll ans = 0;

	for(ll i = 1; i <= n; i++){
		for(ll j = i+1; j <= n; j++){
			for(ll k = j+1; k <= n; k++){
				if(impossible[make_pair(i,j)] || impossible[make_pair(i,k)] || impossible[make_pair(j,k)]) continue;
				ans++;
			}
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
