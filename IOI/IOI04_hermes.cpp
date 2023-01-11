#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;

void solve(){

	ll n;
	cin >> n;

	vector<pair<ll,ll>> a(n+5);

	for(ll i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
		a[i].first += 1000;
		a[i].second += 1000;
	}

	ll dp[2][2][2005];
	memset(dp,0ll,sizeof dp);

	for(ll i = n; i >= 1; i--){
		for(ll prex = 0; prex <= 1; prex++){
			for(ll coord = 0; coord <= 2000; coord++){

				if(i == n){
					dp[(i%2)][prex][coord] = 0;
					continue;
				}

				ll cx,cy;

				if(prex){
					cx = a[i].first;
					cy = coord;
				}
				else{
					cx = coord;
					cy = a[i].second;
				}

				dp[(i%2)][prex][coord] = min(dp[(i+1)%2][0][cx]+abs(a[i+1].second-cy),dp[(i+1)%2][1][cy]+abs(a[i+1].first-cx));
			}
		}
	}

	cout << min(dp[1][1][1000]+abs(a[1].first-1000),dp[1][0][1000]+abs(a[1].second-1000));
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
