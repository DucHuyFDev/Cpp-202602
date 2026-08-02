#include <iostream>
#include <vector>

using namespace std;

int n; 
vector<int> result(5); 
vector<bool> used(5);

void printResult(){
	if (result[1] -  result[4] > 0){
	    for (int i = 1; i <= n; i++){
		    cout << result[i] << "   ";
	    }
		cout << endl;
    }
}

void Try(int i){ 
	for (int j = 1; j <= n; j++){
		if (!used[j]){ 
			result[i] = j; 
			used[j] = true; 
			if (i == n){
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++){
		used[i] = false;
	}
	Try(1);
	return 0;
}