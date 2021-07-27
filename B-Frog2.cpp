#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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

    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
	    cin>>v[i];

	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= k; j++) {
			if(i - j >= 0) {
				dp[i] = min(dp[i], abs(v[i] - v[i - j]) + dp[i - j]);
				// cout<<"For i : "<<i<<" j : "<<j<<" \ndp[i] : "<<dp[i]<<" "<<abs(v[i] - v[i - j]) + dp[i - j]<<endl;
			}
		}
	}

	cout<<dp[n - 1];
    return 0;
}