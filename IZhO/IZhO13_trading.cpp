#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 3e5+5 , INF = 1e18 , MOD = 1e9+7;

vector<ll> seg(4*N);
vector<pair<ll,ll>> lazy(4*N);

void build(ll node , ll left ,  ll right){

	if(left == right){
		seg[node] = 0;
		lazy[node].first = 0;
		lazy[node].second = 0;
		return;
	}

	ll mid = (left+right)/2;

	build(2*node,left,mid);
	build(2*node+1,mid+1,right);

	seg[node] = max(seg[2*node],seg[2*node+1]);
}

bool shouldIUpdate(ll beforeval , ll beforepos , ll newval , ll newpos , ll pos){
	if(beforepos == 0) return true;
	if(pos-newpos+newval >= pos-beforepos+beforeval) return true;
	return false;
}

void propogate(ll node , ll left , ll right){

	ll mid = (left+right)/2;

	seg[node] = max(seg[node],right-lazy[node].second+lazy[node].first);

	if(left != right){
		if(shouldIUpdate(lazy[2*node].first,lazy[2*node].second,lazy[node].first,lazy[node].second,mid)) lazy[2*node] = lazy[node];
		if(shouldIUpdate(lazy[2*node+1].first,lazy[2*node+1].second,lazy[node].first,lazy[node].second,right)) lazy[2*node+1] = lazy[node];
	}

	lazy[node].first = 0;
	lazy[node].second = 0;
}

void update(ll node , ll left , ll right , ll ql , ll qr , ll val){

	if(lazy[node].first) propogate(node,left,right);

	ll mid = (left+right)/2;

	if(left >= ql && right <= qr){

		seg[node] = max(seg[node],right-ql+val);
		if(left != right){
			if(shouldIUpdate(lazy[2*node].first,lazy[2*node].second,val,ql,mid)) lazy[2*node] = make_pair(val,ql);
			if(shouldIUpdate(lazy[2*node+1].first,lazy[2*node+1].second,val,ql,right)) lazy[2*node+1] = make_pair(val,ql);
		}
		return;
	}

	if(left > qr || right < ql) return;

	update(2*node,left,mid,ql,qr,val);
	update(2*node+1,mid+1,right,ql,qr,val);

	seg[node] = max(seg[2*node],seg[2*node+1]);
}

ll query(ll node , ll left , ll right , ll ql , ll qr){

	if(lazy[node].first) propogate(node,left,right);

	if(left >= ql && right <= qr) return seg[node];
	if(left > qr || right < ql) return 0;

	ll mid = (left+right)/2;

	ll l = query(2*node,left,mid,ql,qr);
	ll r = query(2*node+1,mid+1,right,ql,qr);

	return max(l,r);
}

void solve(){

	ll n,m;
	cin >> n >> m;

	build(1,1,n);

	while(m--){
		ll l,r,x;
		cin >> l >> r >> x;

		update(1,1,n,l,r,x);
	}

	for(ll i = 1; i <= n; i++) cout << query(1,1,n,i,i) << " ";
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
