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
    vector<int> track_a(n), track_b(n), track_c(n);
    for(int i = 0; i < n; i++) {
    	int a, b, c;
    	cin>>a>>b>>c;
    	if(i == 0) {
    		track_a[0] = a;
    		track_b[0] = b;
    		track_c[0] = c;
    	} else {
    		track_a[i] = a + max(track_b[i - 1], track_c[i - 1]);
    		track_b[i] = b + max(track_a[i - 1], track_c[i - 1]);
    		track_c[i] = c + max(track_a[i - 1], track_b[i - 1]);
    	}
    	cout<<track_a[i]<<" "<<track_b[i]<<" "<<track_c[i]<<endl;
    }

    cout<<max(track_a[n - 1], max(track_b[n - 1], track_c[n - 1]));
    return 0;
}