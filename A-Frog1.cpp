// #include <bits/stdc++.h>
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

    int n;
    cin>>n;
    vector<int> v(n + 1, 0);
    for(int i = 1; i <= n; i++)
    	cin>>v[i];

    vector<int> dp(n + 1);
    dp[2] = abs(v[2] - v[1]);

    for(int i = 3; i <= n; i++)
    	dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));
    
    cout<<dp[n];
    return 0;
}