#include <iostream>
#include <vector>

using namespace std;


bool isValid(vector<int> a, int n)
{
    if(a[1] == 0 || a[n-1] == 0)
        return true;
    else if(a[4] == 0 || a[n-4] == 0)
        return true;
    else
        return false;
}

void move(vector<int> &a, int hole, int tomove, int &count)
{
    if(tomove > hole)
    {
        a[hole] = 1;
        a[hole + 1] = 0;
        a[tomove] = 0;
    }
    else
    {
        a[hole] = 1;
        a[hole - 1] = 0;
        a[tomove] = 0;
    }

    count++;
}

void printarray(vector<int> &a, int n)
{
    cout << "[" << a[0];

    for(int i = 1; i < n ; i++)
    {
        cout << ", " << a[i];
    }

    cout << "]" << endl;
}

void solve(int S, int E, vector<int> &a, int n, int count) // S = 0 , E = numofcells-1   in the begining
{
    // we stop when all cells are zeros except only one
    if(count == n-1)  
    {
        return;
    }
    else
    {    
        if(a[S+1] == 0 )
        {
            move(a, S+1, S+3, count);
            printarray(a, n);
            move(a, S+2, S, count);
            printarray(a, n);
            solve(S+2, E, a, n, count);
        }

        else if(a[E-1] == 0)
        {
            move(a, E-1, E-3, count);
            printarray(a, n);
            move(a, E-2, E, count);
            printarray(a, n);
            solve(S, E-2, a, n, count);
        }

        else if(a[S+4] == 0 )
        {
            move(a, S+4, S+2, count);
            printarray(a, n);
            move(a, S+2, S, count);
            printarray(a, n);
            solve(S+2, E, a, n, count);
        }

        else if(a[E-4] == 0)
        {
            move(a, E-4, E-2, count);
            printarray(a, n);
            move(a, E-2, E, count);
            printarray(a, n);
            solve(S, E-2, a, n, count);
        }
    }

}

int main()
{
    int numofcells;
    cout << "\nThe number of cells in this round = ";
    cin >> numofcells;

    if(numofcells <= 2 || numofcells % 2 != 0)
    {
        cout << "Impossible to solve" << endl;
    }
    else
    {
        int count = 1;
        vector<int> a;
        cout << "Enter the array: " << endl;
        for(int i = 0; i < numofcells ; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }

        cout << endl << "Steps of Solution:" << endl;
        printarray(a, numofcells);

        if(isValid(a , numofcells - 1))
            solve(0, numofcells-1, a, numofcells, count);
        else
            cout << "Impossible to solve" << endl;
    }

}