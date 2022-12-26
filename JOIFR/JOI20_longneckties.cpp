#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<pair<ll,ll>> a(n+5);
	vector<ll> b(n+5);

	for(ll i = 1; i <= n+1; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	for(ll i = 1; i <= n; i++) cin >> b[i];

	sort(a.begin()+1,a.begin()+n+2);
	sort(b.begin()+1,b.begin()+n+1);

	vector<ll> ans(n+5);

	multiset<ll> s;
	for(ll i = 2; i <= n+1; i++) s.insert(a[i].first-b[i-1]);

	auto it = s.end();
	it--;
	ans[a[1].second] = (*(it));

	for(ll i = 2; i <= n+1; i++){
		s.erase(s.find(a[i].first-b[i-1]));
		s.insert(a[i-1].first-b[i-1]);

		auto it = s.end();
		it--;
		ans[a[i].second] = (*(it));
	}

	for(ll i = 1; i <= n+1; i++) cout << ans[i] << " ";
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
