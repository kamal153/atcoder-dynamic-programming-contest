// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

void file_i_o(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
}

int main() {
    file_i_o();

    ll n, weight;
    cin>>n>>weight;
    vector<ll> v(n), w(n);
    for (ll i = 0; i < n; ++i)
    	cin>>w[i]>>v[i];

    vector<ll> prev(weight + 1, 0);
    vector<ll> cur(weight + 1, 0);

    for(ll i = 1; i <= n; i++) {
    	for(ll j = 0; j <= weight; j++) {
    		if(j >= w[i - 1])
    			cur[j] = max(prev[j], v[i - 1] + prev[j - w[i - 1]]);
    		else
    			cur[j] = prev[j];
    	}
    	prev = cur;
    }

    cout<<prev[weight];
    return 0;
}