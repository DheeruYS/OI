#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 100+5 , INF = 1e9 , MOD = 1e9+7;

void solve(){

	ll m,n;
	cin >> m >> n;

	vector<ll> a(n+5);
	for(ll i = 1; i <= n; i++) cin >> a[i];

	unordered_map<ll,ll> f1,f2;

	for(ll i = 1; i <= (n/2); i++) f1[a[i]]++;
	for(ll i = (n/2)+1; i <= 2*(n/2); i++) f2[a[i]]++;


	for(ll k = (n/2); k >= 1; k--){

		vector<ll> presum1(m+5),presum2(m+5);

		for(ll i = m; i >= 1; i--){
			presum1[i] = presum1[i+1]+f1[i];
			presum2[i] = presum2[i+1]+f2[i];
		}

		bool possible =  true;

		for(ll i = 1; i <= m; i++){
			if(presum1[i] > presum2[i+1]){
				possible = false;
				break;
			}
		}

		if(possible){
			cout << k;
			return;
		}

		f1[a[k]]--;
		f2[a[k]]++;
		f2[a[2*k]]--;
		f2[a[(2*k)-1]]--;
	}
	
	cout << "0";
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
