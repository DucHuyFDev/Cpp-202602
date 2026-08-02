#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	priority_queue<long long, vector<long long>, greater<long long>> pq; // min heap
	for (int i = 0; i < n; i++){
		long long x;
		cin >> x;
		pq.push(x);
	}
	long long total_cost = 0;
	while(pq.size() > 1){
		int take = min((int)pq.size(), k);
		long long current_sum = 0, min_val = 0, max_val = 0;
		for (int i = 0; i < take; i++){
			long long val = pq.top();
			pq.pop();
			current_sum += val;
			if (i == 0) min_val = val;
			if (i == take - 1) max_val = val;
		}
		total_cost += (max_val - min_val);
		pq.push(current_sum);
	} 
	cout << pq.top() << " " << total_cost << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}