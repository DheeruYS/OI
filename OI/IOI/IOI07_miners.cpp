#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 1e5+5 , INF = 1e18 , MOD = 1e9+7;
 
ll dp[N][4][4][4][4];
vector<ll> a(N);
ll n;
 
ll chartoll(char x){
	if(x == 'M') return 1ll;
	if(x == 'B') return 2ll;
	return 3ll;
}
 
ll go(ll i , ll pre1 , ll pree1 , ll pre2 , ll pree2){
 
	if(i == n+1) return 0;
	if(dp[i][pre1][pree1][pre2][pree2] != -1) return dp[i][pre1][pree1][pre2][pree2];
	
	set<ll> s1;
	if(pre1 != 0) s1.insert(pre1);
	if(pree1 != 0) s1.insert(pree1);
	s1.insert(a[i]);
	ll uuu = s1.size();
 
	ll ans = uuu+go(i+1,a[i],pre1,pre2,pree2);
	
	set<ll> s2;
	if(pre2 != 0) s2.insert(pre2);
	if(pree2 != 0) s2.insert(pree2);
	s2.insert(a[i]);
	ll uu = s2.size();
 
	ans = max(ans,uu+go(i+1,pre1,pree1,a[i],pre2));
	
	return dp[i][pre1][pree1][pre2][pree2] = ans;
}
 
void solve(){
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		char x;
		cin >> x;
		a[i] = chartoll(x);
	}
 
	memset(dp,-1,sizeof dp);
 
	cout << go(1,0,0,0,0);
}
 
int main(){
 
	fast;
	
  ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
