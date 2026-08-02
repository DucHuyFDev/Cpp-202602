#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> result(100);

void printResult() {
    for (int i = 1; i <= k; i++)
        cout << result[i] << " ";
    cout << endl;
}

void Try(int i) {
    for (int j = result[i - 1] + 1; j <= n - k + i; j++) {
        result[i] = j;

        if (i == k)
            printResult();
        else
            Try(i + 1);
    }
}

int main() {
    cin >> n >> k;
    result[0] = 0;
    Try(1);
    return 0;
}