// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define lli long long int

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
    clock_t begin = clock();
    file_i_o();

	int n, m, mod = 1e9+7;
	cin>>n>>m;

	vector<vector<char> > ch(n, vector<char>(m));
	vector<vector<lli> > dp(n, vector<lli>(m));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>ch[i][j];

	for(int i = n - 1; i >= 0; i--) {
		for(int j = m - 1; j >= 0; j--) {
			if(i == n - 1 && j == m - 1) 
				dp[i][j] = 1;
			else if(dp[i][j] == '#')
				dp[i][j] = 0;
			else 
				dp[i][j] = ((i == n - 1 ? 0 : dp[i + 1][j]) % mod + (j == m - 1 ? 0 : dp[i][j + 1]) % mod) % mod;
		}
	}

	cout<<dp[0][0] % mod;
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}