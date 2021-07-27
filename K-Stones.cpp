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
    clock_t begin = clock();
    file_i_o();

    ll n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(ll i = 0; i < n; i++)
    	cin>>a[i];

    vector<bool> dp(k + 1, false);
    for (int i = 1; i <= k; ++i)
        for(auto ai : a) {
            if(i - ai >= 0 && dp[i - ai] == false)
                dp[i - ai] = true;
        }

    cout<<(dp[k] ? "First" : "Second")<<endl;
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}