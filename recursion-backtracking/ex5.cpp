#include <iostream>
#include <vector>

using namespace std;

int n, S;
vector<int> a; // bat dau tu 0
long long ans = 0;

void Try(int i, int current_sum){
	if (current_sum > S){
		return;
	}
	if (i == n){
		if (current_sum == S)
			ans++;
		return;
	}
	Try(i + 1, current_sum + a[i]); // chon
	Try(i + 1, current_sum);// khong chon
}

int main(){
	cin >> n >> S;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	Try(0,0);
	if (S == 0){
		cout << ans - 1;
	}
	else cout << ans;
	return 0;
}