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
#define rfo(i,a,b) for(ll i = a; i >= b; i--)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105
 
int main() {
    
    fast;
 
	ll l,n;
	cin in l in n;
 
	vector<pll> person(n+5);
 
	fo(i,1,n) cin in person[i].first in person[i].second;
	sort(person.begin()+1,person.begin()+n+1);
 
	vector<double> finish(n+5);
	fo(i,1,n) finish[i] = (double)l/(double)person[i].second + (double) person[i].first;
 
	vi dp(n+5); // dp[i] = max number of nested segments containing i ( inside )
 
	// base case :
 
	fo(i,1,n) dp[i] = 1;
 
	// recursive relation :
 
	rfo(i,n,1){
		fo(j,i+1,n){
			if(finish[j] < finish[i]) mmax(dp[i],dp[j]+1);
		}
	}
 
	// optimal solution :
 
	ll ans = -INF;
	fo(i,1,n) mmax(ans,dp[i]);
 
	cout out ans;
	
    return 0;
}
