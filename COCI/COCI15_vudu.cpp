#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
const int N = 1e6+5 , INF = 1e9 , MOD = 1e9+7;

vector<ll> fenwick(N),a(N);

void update(ll node , ll val){
	for(ll i = node; i < N; i += (i & -i)){
		fenwick[i] += val;
	}
}

ll query(ll node){
	ll ans = 0;
	for(ll i = node; i >= 1; i -= (i & -i)){
		ans += fenwick[i];
	}
	return ans;
}
 
void solve(){
 
	ll n;
	cin >> n;
 
	for(ll i = 1; i <= n; i++) cin >> a[i];
 
	ll p;
	cin >> p;
 
	ll sum = 0;

	vector<pair<ll,ll>> val;

	val.push_back(make_pair(0,0));
	for(int i = 1; i <= n; i++){
		sum += a[i];
		val.push_back(make_pair(sum-p*i,i));
	}
	sort(val.begin(),val.end());

	vector<ll> cc(n+5);

	ll cnt = 0;

	for(ll i = 0; i < n+1; i++){
		if(i != 0 && val[i].first == val[i-1].first){
			cc[val[i].second] = cnt;
		}
		else{
			cnt++;
			cc[val[i].second] = cnt;
		}
	}

	update(cc[0],1);
 
	ll ans = 0;
 
	for(int i = 1; i <= n; i++){ 
		ans += query(cc[i]);
		update(cc[i],1);
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
