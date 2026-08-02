#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n,k;
vector<string> data;
set<string> results; // k

void printResult(){
	for (string s: results){ // foreach
		cout << s << endl;
	}
}

void Try(int start_idx, int count, string current_str){
	if (count == k){
		results.insert(current_str);
		return;
	}
	for (int i = start_idx; i < n; i++){
		if (count + (n - i) < k){ // het nguyen lieu de tao nen k phan tu
			break;
		}
		Try(i + 1, count + 1, current_str + data[i]);
	}
}

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		data.push_back(tmp);
	}
	Try(0,0,"");
	printResult();
	return 0;
}