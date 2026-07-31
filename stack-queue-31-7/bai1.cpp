#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isOperator(string s){ // hàm có giá trị trả về (check xem có phải là toán tử hay không)
	return (s == "+" || s == "-" || s == "*" || s == "/");
}

void solve(){ // hàm thực thi
	int n;
	cin >> n;
	vector<string> words(n);  // Mảng động
	for (int i = 0; i < n; i++){
		cin >> words[i]; // nhập phần tử
	}
	stack<long long> st; // tạp stack lưu trữ các toán hạng
	for (int i = n - 1; i >= 0; i--){ 
	/* duyệt từ cuối lên đầu
	Nguyên lý:
	- Duyệt được toán hạng -> ép kiểu và đẩy vào stack
	- Duyệt được toán tử -> lấy 2 phần tử đỉnh stack theo đúng thứ tự và thực hiện phép tính (trước - sau)
	- Khi đã duyệt hết danh sách phần tử của phép tính, phần tử nằm trên đỉnh stack chính là kết quả
	*/
		if (!isOperator(words[i])){
		st.push(stoll(words[i]));
		}
		else{
			long long op1 = st.top(); 
			st.pop();
			long long op2 = st.top();
			st.pop();
			if (words[i] == "+"){
				st.push(op1 + op2);
			}
			else if (words[i] == "-"){
				st.push(op1 - op2);
			}
			else if (words[i] == "*"){
				st.push(op1 * op2);
			}
			else{
				st.push(op1 / op2);
			}
		}
	}
	cout << st.top() << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}