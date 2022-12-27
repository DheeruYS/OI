#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n,k;
	string s;

	cin >> n >> k >> s;
	s = ' '+s;

	vector<ll> prej(n+5),preo(n+5),prei(n+5);
	vector<ll> nearj(n+5),nearo(n+5),neari(n+5);
	ll lastj = 0 , lasto = 0 , lasti = 0;

	for(ll i = 1; i <= n; i++){
		prej[i] = prej[i-1]+(s[i] == 'J');
		preo[i] = preo[i-1]+(s[i] == 'O');
		prei[i] = prei[i-1]+(s[i] == 'I');

		nearj[i] = lastj;
		neari[i] = lasti;
		nearo[i] = lasto;

		if(s[i] == 'J') lastj = i;
		else if(s[i] == 'O') lasto = i; 
		else lasti = i;
	}

	ll ans = INF;

	for(ll i = 1; i <= n; i++){
		if(s[i] == 'I'){

			ll x = i;

			ll low = 1, high = x;
			ll ind1 = 0;

			while(low <= high){
				ll mid = (low+high)/2;
				if(prei[x]-prei[mid-1] >= k){
					ind1 = mid;
					low = mid+1;
				}
				else high = mid-1;
			}

			x = ind1;
			x = nearo[x];

			low = 1, high = x;
			ll ind2 = 0;

			while(low <= high){

				ll mid = (low+high)/2;
				if(preo[x]-preo[mid-1] >= k){
					ind2 = mid;
					low = mid+1;
				}
				else high = mid-1;
			}

			x = ind2;
			x = nearj[x];

			low = 1, high = x;
			ll ind3 = 0;

			while(low <= high){
				ll mid = (low+high)/2;
				if(prej[x]-prej[mid-1] >= k){
					ind3 = mid;
					low = mid+1;
				}
				else high = mid-1;
			}

			x = ind3;

			if(x > 0) ans = min(ans,(i-x+1)-(3*k));
		}
	}

	if(ans == INF) ans = -1;
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
