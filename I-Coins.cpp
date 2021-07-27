// #include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
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

int n;
vector<double> h;
vector<vector<double> > dp(3005, vector<double>(3005, -1));

//x is minimum head required for n(h) > n(v)
//dp[i][j] :- probanility to get atleast j heads in i coins.
double probability_of_head(int i, int x) {
    if(x == 0) return 1;
    if(i >= n) return 0; 
    if(dp[i][x] > -0.9) return dp[i][x];
    return dp[i][x] = (h[i] * probability_of_head(i + 1, x - 1)) + ((1 - h[i]) * probability_of_head(i + 1, x));
}

int main() {
    clock_t begin = clock();
    file_i_o();

    cin>>n;
    h.resize(n);
    for (int i = 0; i < n; ++i)
	    cin>>h[i];

    cout<<fixed<<setprecision(10)<<probability_of_head(0, (n + 1) / 2);

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}