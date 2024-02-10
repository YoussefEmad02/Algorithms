#include <iostream>
#include <vector>


using namespace std;
bool flag = true;

void printarray(vector<int> &a, int n)
{
    cout << "[" << a[0];

    for(int i = 1; i < n ; i++)
    {
        cout << ", " << a[i];
    }

    cout << "]" << endl;
}

void checksol(vector<int> arr, int n, int size)  // n => no of ones in the array
{
    while (flag == true) {
        int counter = 0;


        if (n == 1) {

            return;
        }

        while (arr[counter] == 0)
            counter++;

        for (int i = counter; i < size - 2; i++) {
            if (arr[i] == 0 && arr[i + 1] == 1 && arr[i + 2] == 1) {
                arr[i] = 1;
                arr[i + 1] = 0;
                arr[i + 2] = 0;
                n--;
                printarray(arr, size);
                flag = true;
                break;

            }
            else if (arr[i] == 1 && arr[i + 1] == 1 && arr[i + 2] == 0) {
                arr[i] = 0;
                arr[i + 1] = 0;
                arr[i + 2] = 1;
                n--;
                printarray(arr, size);
                flag = true;
                break;

            }
            else {
                flag = false;
            }
        }
    }

    if (flag == false)
    {
        cout << "unsolvable" << endl;
    }

}