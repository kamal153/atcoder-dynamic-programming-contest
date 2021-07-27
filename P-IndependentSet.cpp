//#include<bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/trie_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;
#define lli long long int 
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for(int i = (a); i <(b); i++)
#define loopr(i,a,b) for(int i = (a); i >=(b); i--)
#define bs binary_search
#define mod 1000000007
#define inf 1e18
#define vi vector<int>
#define vlli vector<long long int>
#define si set<int>
#define slli set<lli>
#define spi set<pair<lli,lli>>
#define arr array
#define ump unordered_map
#define prq_max priority_queue<lli>
#define prq_min priority_queue<lli,vlli,greater<lli>>
#define all(v)  v.begin(),v.end()
#define mid(l,r) (l+((r-l)/2)) 
#define bitc(a)  __builtin_popcount(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define itr(a,it) for(__typeof(c.begin()) it = c.begin();it!=begin();it++) 
#define lb(a,b) lower_bound(all(a),b)
#define ub(a,b) upper_bound(all(a),b)

lli dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
lli dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };


// template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
// template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
// template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
// template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}  


//typedef tree<lli, null_type, less < lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<lli, null_type, less < lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void file_i_o(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	#ifndef ONLINE_JUDGE 
	        freopen("input.txt", "r", stdin); 
	        freopen("output.txt", "w", stdout); 
	#endif 

}

vector<vlli> dp(1e5 + 5, vlli(2, -1));
// 0 :- black, // 1 :- white
ump<int,vector<int> > tree;

lli independentSet(int node, int parent, int color) {
	if(dp[node][color] != -1) return dp[node][color];

	lli ans = 0, w1 = 1, w0 = 1;
	for(auto child : tree[node])
		if(parent != child)
			w1 = (w1 * independentSet(child, node, 1)) % mod;
	ans += w1;

	if(color == 1) {
		for(auto child : tree[node])
			if(parent != child)
				w0 = (w0 * independentSet(child, node, 0)) % mod;

		ans = ((ans % mod) + (w0 % mod)) % mod;
	}

	return dp[node][color] = ans % mod;
}



int main() {
    clock_t begin = clock();
    file_i_o();

    int n;
    cin>>n;
    for(int i = 0; i < n - 1; i++) {
    	int a,b;
    	cin>>a>>b;
    	tree[a].push_back(b);
    	tree[b].push_back(a);
    }

    cout<<independentSet(1, 0, 1);

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
