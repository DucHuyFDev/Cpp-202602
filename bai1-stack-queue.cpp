#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Ham kiem tra xem chuoi co phai la toan tu hay khong
bool isOperator(const string& s) {
	// Toan tu chi co do dai la 1.
	// Dieu kien nay giup phan biet dau tru toan hoc "-" va so am (vd: "-10")
	if (s.length() == 1) {
		return s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/';
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector<string> tokens(n);
	for (int i = 0; i < n; ++i) {
		cin >> tokens[i];
	}
	
	// Su dung stack kieu long long vi ket qua co the len toi 10^18
	stack<long long> st;
	
	// Duyet bieu thuc tu phai sang trai (tu cuoi len dau)
	for (int i = n - 1; i >= 0; --i) {
		if (isOperator(tokens[i])) {
			// Neu la toan tu, lay 2 toan hang tren cung ra de tinh toan
			long long val1 = st.top(); st.pop();
			long long val2 = st.top(); st.pop();
			
			long long res = 0;
			if (tokens[i] == "+") res = val1 + val2;
			else if (tokens[i] == "-") res = val1 - val2;
			else if (tokens[i] == "*") res = val1 * val2;
			else if (tokens[i] == "/") res = val1 / val2;
			
			// Day ket qua sau khi tinh vao lai stack
			st.push(res);
		} else {
			// Neu la toan hang (so), chuyen tu string sang long long roi dua vao stack
			st.push(stoll(tokens[i]));
		}
	}
	
	// Ket qua cuoi cung la phan tu duy nhat con lai trong stack
	cout << st.top() << "\n";
}

int main() {
	// Toi uu I/O trong C++
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	if (cin >> t) {
		while (t--) {
			solve();
		}
	}
	return 0;
}
