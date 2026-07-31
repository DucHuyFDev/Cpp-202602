#include <iostream>
#include <stack>

using namespace std;

void solve(){
	string s;
	getline(cin, s);
	stack<int> st;
	int id_counter = 1;
	
	for(int i = 0; i < s.length(); i++){
		if (s[i] == '('){
			cout << id_counter << " ";
			st.push(id_counter);
			id_counter++;
		}
		else if (s[i] == ')'){
			cout << st.top() << " ";
			st.pop();
		}
		else{
			continue;
		}
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		solve();
	}
	return 0;
}