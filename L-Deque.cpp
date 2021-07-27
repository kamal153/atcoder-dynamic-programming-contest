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

vector<vector<ll> > dp(3008, vector<ll>(3008, -1));
vector<ll> a(3008);
ll deque(int i, int j) {
	if(dp[i][j] != -1)	return dp[i][j];
	if(i == j)	return dp[i][i] = a[i];
	if(i > j)	return 0;

	return dp[i][j] = max(a[i] - deque(i + 1, j), a[j] - deque(i, j - 1));
}

int main() {
    clock_t begin = clock();
    file_i_o();

    ll n;
    cin>>n;

    for (int i = 0; i < n; ++i)
    	cin>>a[i];

    cout<<deque(0, n - 1);
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}