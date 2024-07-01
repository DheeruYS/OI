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
#define N 1005
 
ll f(ll x){
 
	ll y = (((x*x)%5)*((x*x)%5))%5;
	y += (2*x*x)%5;
	y %= 5;
 
	y++;
 
	return y;
}
 
vi val(N);
ll sum = 0;
vector<pll> a(N);
ll n;
 
void go(ll i){
 
	if(i == n+1){
		ll s = 0;
		fo(k,1,n) s += val[k];
 
		sum += f(s);
		return;
	}
 
	fo(j,0,a[i].second-a[i].first){
		val[i] += j;
		go(i+1);
		val[i] -= j;
	}
}
 
int main() {
    
    fast;
 
	cin in n;
 
	fo(i,1,n){
		cin in a[i].first in a[i].second;
		val[i] = a[i].first;
	}
	
	go(1);
 
	cout out sum;
 
    return 0;
}
