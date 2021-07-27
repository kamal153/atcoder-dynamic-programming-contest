// #include <bits/stdc++.h>
#include <cmath>
#include <map>
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

std::map<int, vector<int> > mp;
vector<int> dp(1e5 + 10, -1);
int n, m;

int dfs(int i) {
	if(dp[i] != -1)
		return dp[i];

	if(mp[i].size() == 0)
		return dp[i] = 0;

	int result = INT_MIN;
	for(int a : mp[i])
		result = max(result, 1 + dfs(a));
	return dp[i] = result;
}

int main() {
    clock_t begin = clock();
    file_i_o();

    cin>>n>>m;
    for(int i = 0; i < m; i++) {
    	int a, b;
    	cin>>a>>b;
    	mp[a].push_back(b);
    }

    int result = INT_MIN;
    for(int i = 1; i <= n; i++) {
    	result = max(result, dfs(i));
    }

    cout<<result;
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}