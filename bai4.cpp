#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 2000000;
vector<int> step(MAX);

void solve(){
	int n,m; cin >> n >> m;
	if (n == m){
		cout << 0;
	}
	else if (n > m){
		cout << n - m;
	}
	else{
		queue<int> q;
		for (int i = 0; i < MAX; i++){
			step[i] = -1;
		}
		q.push(n);
		step[n] = 0;
		while (!q.empty()){
			int num = q.front();
			q.pop();
			if (num == m){
				cout << step[num] << endl;
				return; // return không trả về giá trị (phù họp với hàm void)
			}
			int next1 = num * 2;
			if (next1 < MAX && step[next1] == -1){
				step[next1] = step[num] + 1;
				q.push(next1);
			}
			int next2 = num - 1;
			if (next2 > 0 && step[next2] == -1){
				step[next2] = step[num] + 1;
				q.push(next2);
			}
		}
	}
}

int main(){
	solve();
	return 0;
}