#include <iostream>
#include <cmath>
#include <vector>
#include <String>
using namespace std;

vector<string> ToH4_arr;
int flag = 0;
int current_disk_no = 0;
vector<int> found;

void ToH3(int m, char p, char q, char r) {
    if (m == 1) {
        cout << "Move disk " << current_disk_no << " from rod " << p << " to rod " << q << endl;
        return;
    }

    ToH3(m - 1, p, r, q);

    cout << "Move disk " << m + current_disk_no - 1 << " from rod " << p << " to rod " << q << endl;

    ToH3(m - 1, r, q, p);
}

string ToH4(int n, char a, char b, char c, char d) {
    if (flag == 1) {
        if (n == 0) {
            return ToH4_arr[0];
        }
        else if (n == 1) {
            ToH4_arr[1] = "Move disk 1 from rod " + string(1, a) + " to rod " + string(1, b) + "\n";
            return ToH4_arr[1];
        }
        else if (!ToH4_arr[n].empty() && found[n] == 1) {
            return ToH4_arr[n];
        }
        else {
            string subproblem1 = ToH4(n - 2, a, c, d, b);
            string subproblem2 = ToH4(n - 2, c, b, a, d);
            ToH4_arr[n] = subproblem1 + "Move disk " + to_string(n - 1) + " from rod " + string(1, a) + " to rod " + string(1, d) +
                "\nMove disk " + to_string(n) + " from rod " + string(1, a) + " to rod " + string(1, b) +
                "\nMove disk " + to_string(n - 1) + " from rod " + string(1, d) + " to rod " + string(1, b) + "\n" + subproblem2;
            flag = 1;
            return ToH4_arr[n];
        }
    }

    if (n == 0) {
        return ToH4_arr[0];
    }
    else if (n == 1) {
        ToH4_arr[1] = "Move disk 1 from rod " + string(1, a) + " to rod " + string(1, b) + "\n";
        return ToH4_arr[1];
    }
    else if (!ToH4_arr[n].empty()) {
        return ToH4_arr[n];
    }
    else {
        string subproblem1 = ToH4(n - 2, a, c, d, b);
        string subproblem2 = ToH4(n - 2, c, b, a, d);
        ToH4_arr[n] = subproblem1 + "Move disk " + to_string(n - 1) + " from rod " + string(1, a) + " to rod " + string(1, d) +
            "\nMove disk " + to_string(n) + " from rod " + string(1, a) + " to rod " + string(1, b) +
            "\nMove disk " + to_string(n - 1) + " from rod " + string(1, d) + " to rod " + string(1, b) + "\n" + subproblem2;
        flag = 1;
        return ToH4_arr[n];
    }
}

void ToH43(int i, int j, char a, char b, char c, char d) {
    int m = j - i + 1;
    int k = static_cast<int>(floor(sqrt(2 * m)));
    cout << ToH4(m - k, a, d, b, c);
    cout << endl;
    current_disk_no = m - k + 1;
    ToH3(k, a, b, c);
    cout << endl;
    cout << ToH4(m - k, d, b, a, c);
}

void main() {
    int n = 8;
    for (int i = 0; i < 101; i++) {
        found.push_back(0);
        ToH4_arr.push_back("");
    }

    cout << "---------------Solution using Dynamic Programming--------------" << endl;
    cout << ToH4(n, 'A', 'B', 'C', 'D') << endl;
    cout << "-----------------Optimal Solution------------------------------" << endl;
    ToH43(1, n, 'A', 'B', 'C', 'D');
}