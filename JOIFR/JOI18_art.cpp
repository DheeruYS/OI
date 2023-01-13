#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<pair<ll,ll>> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin()+1,a.begin()+n+1);

	ll mini = INF , ans = -INF , sum = 0;

	for(ll i = 1; i <= n; i++){
		mini = min(mini,sum-a[i].first);
		sum += a[i].second;
		ans = max(ans,sum-a[i].first-mini);
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
