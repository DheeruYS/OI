#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,m,c;
	cin >> n >> m >> c;

	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i];

	vector<ll> ans;

	multiset<ll> s;
	for(ll i = 1; i <= m; i++) s.insert(a[i]);

	auto low = s.begin();
	auto high = s.end();
	high--;
	if((*(high))-(*(low)) <= c) ans.push_back(1);
	
	for(ll i = m+1; i <= n; i++){

		s.erase(s.find(a[i-m]));
		s.insert(a[i]);

		auto low = s.begin();
		auto high = s.end();
		high--;
		if((*(high))-(*(low)) <= c) ans.push_back(i-m+1);
	}

	if(ans.size() == 0){
		cout << "NONE";
		return;
	}

	for(auto u : ans) cout << u << "\n";
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
