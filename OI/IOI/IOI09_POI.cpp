#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;
 
bool comp(tuple<ll,ll,ll> a , tuple<ll,ll,ll> b){
 
	ll x1,y1,z1,x2,y2,z2;
	tie(x1,y1,z1) = a;
	tie(x2,y2,z2) = b;
 
	if(x1 != x2) return x1 > x2;
	if(y1 != y2) return y1 > y2;
	return z1 < z2;
}
 
void solve(){
 
	ll n,t,p;
	cin >> n >> t >> p;
 
	vector<vector<ll>> task(n+5,vector<ll>(t+5));
	vector<ll> solved(n+5,0),score(n+5),point(t+5,n);
 
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= t; j++){
			cin >> task[i][j];
			if(task[i][j]){
				solved[i]++;
				point[j]--;
			}
		}
	}
 
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= t; j++){
			if(task[i][j]) score[i] += point[j];
		}
	}
 
	vector<tuple<ll,ll,ll>> rank;
	for(ll i = 1; i <= n; i++) rank.push_back(make_tuple(score[i],solved[i],i));
 
	sort(rank.begin(),rank.end(),comp);
 
	for(ll i = 0; i < n; i++){
		if(get<2>(rank[i]) == p){
			cout << get<0>(rank[i]) << " " << i+1;
			return;
		}
	}
}
 
int main(){
 
	fast;
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
