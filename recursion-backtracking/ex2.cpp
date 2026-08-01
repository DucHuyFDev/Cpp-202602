#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; // so luong phan tu
string end_person;
vector<string> name; // tất cả mọi người
vector<string> others; // mảng chứa tên của những người còn lại (ngoài người đứng cuối)
vector<string> result;  // mảng kết quả sắp xếp
vector<bool> used;

void printResult(){
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << "  ";
	}
	cout << end_person << endl;
}

void Try(int i){
	for (int j = 0; j < n - 1; j++){
		if (!used[j]){
			result[i] = others[j];
			used[j] = true;
			
			if (i == n - 2){
				printResult();
			}
			else{
				Try(i + 1);
			}
			used[j] = false;
		}
	}
	
}

int main(){
	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		name.push_back(tmp); // chèn vào phần tử cuối trong mảng
	}
	cin >> end_person;
	for (int i = 0; i < n; i++){
		if (name[i] != end_person){
			others.push_back(name[i]);
		}
	}
	sort(others.begin(), others.end());
	result.resize(n - 1);
	used.resize(n - 1);
	Try(0);
	return 0;
 }