#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 250000+5 , INF = 2e9 , MOD = 1e9+7;

vector<ll> seg(4*N);
vector<ll> a(N);

void build(ll node , ll left , ll right){

	if(left == right){
		seg[node] = a[left];
		return;
	}

	ll mid = (left+right)/2;

	build(2*node,left,mid);
	build(2*node+1,mid+1,right);

	seg[node] = min(seg[2*node],seg[2*node+1]);
}

ll query(ll node , ll left , ll right , ll ql , ll qr){

	if(right < ql || left > qr) return INF;
	if(left >= ql && right <= qr) return seg[node];

	ll mid = (left+right)/2;

	ll l = query(2*node,left,mid,ql,qr);
	ll r = query(2*node+1,mid+1,right,ql,qr);

	return min(l,r);
}

void solve(){

	ll n;
	cin >> n;

	for(ll i = 1; i <= n; i++){
		ll x;
		cin >> x >> a[i];
	}
	
	ll ans = n;
	map<ll,ll> prev;

	build(1,1,n);

	for(ll i = 1; i <= n; i++){

		if(prev.find(a[i]) == prev.end()){
			prev[a[i]] = i;
			continue;
		}

		ll ind = prev[a[i]];

		if(query(1,1,n,ind,i) >= a[i]) ans--;
		prev[a[i]] = i;
	}

	cout << ans;
}

int main(){

	fast;

	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();

	return 0;
}
