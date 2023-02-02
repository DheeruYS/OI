#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 2000+5 , INF = 1e9+5 , MOD = 1e9+7;

vector<ll> a(N);
ll n,p,q;

bool check(ll dist){

	vector<vector<ll>> dp(n+5,vector<ll>(p+5,INF));
	// dp[i][j] = min large cameras needed for 1 to i and having j small cameras

	for(ll i = 0; i <= p; i++) dp[0][i] = 0;
	dp[1][0] = 1;
	for(ll i = 1; i <= p; i++) dp[1][i] = 0;

	vector<ll> w(n+5),twow(n+5);

	for(ll i = 1; i <= n; i++){

		ll low1 = 1 , high1 = i;
		ll ind1 = i;
		while(low1 <= high1){
			ll mid = (low1+high1)/2;
			if(a[i]-a[mid] < dist){
				ind1 = mid;
				high1 = mid-1;
			}
			else low1 = mid+1;
		}

		w[i] = ind1;

		ll low2 = 1 , high2 = i;
		ll ind2 = i; 
		while(low2 <= high2){
			ll mid = (low2+high2)/2;
			if(a[i]-a[mid] < 2*dist){
				ind2 = mid;
				high2 = mid-1;
			}
			else low2 = mid+1;
		}

		twow[i] = ind2;
	}

	for(ll i = 2; i <= n; i++){
		for(ll j = 0; j <= p; j++){
			if(j) dp[i][j] = min(dp[i][j],dp[w[i]-1][j-1]);
			dp[i][j] = min(dp[i][j],dp[twow[i]-1][j]+1);
		}	
	}

	ll ans = INF;
	for(ll i = 0; i <= p; i++) ans = min(ans,dp[n][i]);

	return (ans <= q);
}

void solve(){

	cin >> n >> p >> q;
	for(ll i = 1; i <= n; i++) cin >> a[i];

	if(p >= n || q >= n){
		cout << "1";
		return;
	}

	sort(a.begin()+1,a.begin()+n+1);

	ll low = 1 , high = a[n];
	ll ans;

	while(low <= high){
		ll mid = (low+high)/2;
		if(check(mid)){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
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
