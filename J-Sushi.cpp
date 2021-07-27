// #include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
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

double dp[305][305][305];

double expectation(ll x, ll y, ll z, ll n) {
	if(x < 0 || y < 0 || z < 0)
		return 0;
	if(x == 0 && y == 0 && z == 0)
		return 0;
	if(dp[x][y][z] > -0.9)
		return dp[x][y][z];
	double result = n;
	result += x * expectation(x - 1, y, z, n);
	result += y * expectation(x + 1, y - 1, z, n);
	result += z * expectation(x, y + 1, z - 1, n);

	return dp[x][y][z] = result / (x + y + z);
}

int main() {
    clock_t begin = clock();
    file_i_o();

    ll n, one = 0, two = 0, three = 0;
    cin>>n;
    memset(dp, -1, sizeof(dp));

    for (ll i = 0; i < n; ++i) {
    	int a;
    	cin>>a;
    	a == 1 ? one++ : a == 2 ? two++ : three++;
    }

    cout<<fixed<<setprecision(10)<<expectation(one, two, three, n);
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}