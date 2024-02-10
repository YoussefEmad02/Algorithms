#include <iostream>
#include <vector>
using namespace std;

int Min_Num_To_TurnOff_Switches(int n) {
    if (n <= 1)  return n;


    vector<int> dp(n + 1, 0);

    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2] + 1;
    }

    return dp[n];
}

int main() {
    cout << "Enter The Number of Switches: " << endl;
    int number;
    cin >> number;
    int MinMoves = Min_Num_To_TurnOff_Switches(number);
    cout << "Minimum number of moves is: " << MinMoves << endl;

    return 0;
}

