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

string s, t, ans;
int n, m;

void LCS(int i, int j, string str) {
	if(i >= n || j >=m) {
		if(ans.length() < str.length())
			ans = str;
		return;
	}

	if(s[i] == t[j])
		LCS(i + 1, j + 1, str + string(1, s[i]));
	else {
		LCS(i + 1, j, str);
		LCS(i, j + 1, str);
	}
}

int main() {
	clock_t begin = clock();
    file_i_o();

  
    cin>>s>>t;
    n = s.length();
    m = t.length();

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j<= m; j++) {
    		if(s[i - 1] == t[j - 1])
    			dp[i][j] = 1 + dp[i - 1][j - 1];
    		else
    			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    	}
    }

    int i = n, j = m;

    while(dp[i][j] != 0) {
    	if(s[i - 1] == t[j - 1]) {
    		ans += s[i - 1];
    		j--;
    		i--;
    	} else {
    		if(dp[i - 1][j] > dp[i][j - 1])
    			i--;
    		else
    			j--;
    	}
    }

    reverse(ans.begin(), ans.end());
    cout<<ans;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
    return 0;
}