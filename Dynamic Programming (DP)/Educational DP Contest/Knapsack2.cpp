#include<bits/stdc++.h>
#include<string>
using namespace std;

#define ll  				long long
#define ld 					long double
#define mod 				1000000007
#define inf 				1e9
#define endl 				"\n"
#define pb 					push_back
#define vi 					vector<ll>
#define vs 					vector<string>
#define pii 				pair<ll,ll>
#define ump 				unordered_map
#define mp 					make_pair
#define pq_max 				priority_queue<ll>
#define pq_min 				priority_queue<ll,vi,greater<ll> >
#define all(n) 				n.begin(),n.end()
#define ff 					first
#define ss 					second
#define mid(l,r) 			(l+(r-l)/2)
#define loop(i,a,b) 		for(int i=(a);i<=(b);i++)
#define lloprev(i,a,b) 		for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b) 	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;

void file_i_o() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("F:/codechef_&_code-forces/IO_Files/input.txt", "r", stdin);
		freopen("F:/codechef_&_code-forces/IO_Files/output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here...
	ll t;
	cin >> t;
	string str = "1000000000";
	cout << "Hello : " << t << endl;
	ll n = stoi(str);
	cout << n << endl;
		
	#ifndef ONLINE_JUDGE 
		clock_t end = clock();
		cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<"ms"<<endl;
	#endif
	return 0;
}