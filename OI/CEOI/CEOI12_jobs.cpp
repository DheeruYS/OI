#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
const ll N = 100+5 , INF = 1e18 , MOD = 1e9+7;
 
void solve(){
 
	ll n,d,m;
	cin >> n >> d >> m;
 
	vector<pair<ll,ll>> a(m+5);
	for(ll i = 1; i <= m; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
 
	sort(a.begin()+1,a.begin()+m+1);
 
	ll low = 1 , high = m;
	ll ans;
 
	while(low <= high){
 
		ll mid = (low+high)/2;
		bool possible = true;
 
		ll machine = mid , day = 1;
 
		for(ll i = 1; i <= m;){
			if(a[i].first <= day && machine){

				if(day > n){
					possible = false;
					break;
				}
				if(day > a[i].first+d){
					possible = false;
					break;
				}
 
				machine--;
				i++;
			}
			else if(a[i].first > day){
				day = a[i].first;
				machine = mid;
			}
			else if(!machine){
				day++;
				machine = mid;
			}
		}
 
		if(possible){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
 
	cout << ans << "\n";
 
	ll p = 1;
 
	for(ll i = 1; i <= n; i++){
		ll left = ans;
		while(left > 0 && p <= m && a[p].first <= i){
			cout << a[p].second << " ";
			p++;
			left--;
		}
		cout << "0\n";
	}
}
 
int main(){
 
	fast;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 
	ll tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	return 0;
}
