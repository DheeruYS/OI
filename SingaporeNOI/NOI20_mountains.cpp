#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 300005
 
vi a(N);
vi seg[4*N];
 
void build(ll node , ll l , ll r){
 
    if(l == r){
        seg[node].pb(a[l]);
        return;
    }
 
    ll mid = (l+r)/2;
 
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
 
    merge(seg[2*node].begin(),seg[2*node].end(),seg[2*node+1].begin(),seg[2*node+1].end(),back_inserter(seg[node]));
}
 
ll query(ll node , ll left , ll right , ll ql , ll qr , ll val){
 
    if(left > qr || right < ql) return 0;
    if(left >= ql && right <= qr){
        auto it = lower_bound(seg[node].begin(),seg[node].end(),val);
        return (seg[node].begin()-it);
    }
 
    ll mid = (left+right)/2;
    return query(2*node,left,mid,ql,qr,val) + query(2*node+1,mid+1,right,ql,qr,val);
}
 
int main() {
    
    fast;
 
    ll n;
    cin in n;
 
    fo(i,1,n) cin in a[i];
 
    build(1,1,n);
 
    ll ans = 0;
    fo(i,2,n-1) ans += query(1,1,n,1,i-1,a[i])*query(1,1,n,i+1,n,a[i]);
 
    cout out ans;
 
    return 0;
}
