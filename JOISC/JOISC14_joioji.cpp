#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	string s;

	cin >> n >> s;
	s = ' '+s;

	ll cj = 0 , ci = 0 , co = 0;

	map<pair<ll,ll>,ll> m;
	m[make_pair(0,0)] = 0;

	ll ans = 0;
	
	for(ll i = 1; i <= n; i++){

		if(s[i] == 'J') cj++;
		else if(s[i] == 'O') co++;
		else ci++;

		if(m.find(make_pair(cj-co,cj-ci)) == m.end()) m[make_pair(cj-co,cj-ci)] = i;
		else ans = max(ans,i-m[make_pair(cj-co,cj-ci)]);
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
