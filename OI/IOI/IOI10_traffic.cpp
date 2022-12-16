#include "traffic.h"
 
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll int
const ll N = 1e6+5 , INF = 3e9 , MOD = 1e9+7;
 
vector<ll> adj[N] , sumdown(N) , maxdown(N);
 
void dfs(ll s , ll par , int p[]){
 
	for(auto u : adj[s]){
		if(u == par) continue;
		dfs(u,s,p);
 
		ll d = sumdown[u]+p[u];
		
		sumdown[s] += d;
		maxdown[s] = max(maxdown[s],d);
	}
}
 
int LocateCentre(int N, int P[], int S[], int D[]){
 
	ll total = 0;
	for(ll i = 0; i < N; i++) total += P[i];
	
	for(ll i = 0; i < N-1; i++){	
		adj[S[i]].push_back(D[i]);
		adj[D[i]].push_back(S[i]);
	}
 
	for(ll i = 0; i < N; i++){
		sumdown[i] = 0;
		maxdown[i] = -INF;
	}
	dfs(0,-1,P);
 
	ll ans = INF , city;
 
	for(ll i = 0; i < N; i++){
		ll d = maxdown[i];
		ll rest = total-sumdown[i]-P[i];
 
		if(max(d,rest) < ans){
			ans = max(d,rest);
			city = i;
		}
	}
 
	return city;
}
