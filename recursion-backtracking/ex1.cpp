#include <iostream>
#include <vector>

using namespace std;

int n; // số lượng phần tử
int m;
vector<int> result(1000); // kết quả
vector<bool> used(1000); // mảng trạng thái (khởi tạo ban đầu cho n phần tử là false)

void printResult(){
	for (int i = 1; i <= n; i++){
		cout << result[i] << " ";
	}
	cout << endl;
}

void Try(int i){ // i là vị trí đang tiến hành thử, và j là giá trị được đem vào để thử
	for (int j = 1; j <= n; j++){
		if (!used[j]){ // nếu số j đã được thử
			result[i] = j; // thử j vào vị trí i
			used[j] = true; // đánh dấu j đã dùng rồi
			if (i == n){ // nếu đã thử hết vị trí
				printResult(); // in kết quả
			}
			else{
				Try(i + 1); //tiếp tục thử với vị trí tiếp theo (i + 1)
			}
			used[j] = false; 
			// đến vị tri này thì Try(i + 1) đã thử hết trường hợp -> xóa trạng thái đã sử dụng để đến lần thử tiếp theo
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		used[i] = false;
	}
	result[1] = m;
	used[m] = true;
	Try(2);
	return 0;
}
