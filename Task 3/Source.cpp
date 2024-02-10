#include <iostream>
#include <vector>

using namespace std;

// Define the chessboard dimensions
const int ROWS = 4;
const int COLS = 3;

// Initialize knights position on the board
int chess[ROWS][COLS] = { {2, 2, 2}, {0, 0, 0}, {0, 0, 0}, {1, 1, 1} };

// Function to print the chessboard
void visualize(int chess[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (chess[i][j] == 0) {
                cout << "| | ";
            }
            else if (chess[i][j] == 1) {
                cout << "|W| ";
            }
            else if (chess[i][j] == 2) {
                cout << "|B| ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to perform knight movement
void moveKnight(int chess[ROWS][COLS], pair<int, int> x, pair<int, int> y) {
    int knight = chess[x.first][x.second];
    chess[x.first][x.second] = 0;
    chess[y.first][y.second] = knight;

    visualize(chess);
    cout << endl;
}

// Function to calculate row and column from a single index
//gets the floor division by 3 of the sent variable
pair<int, int> cal(int x) {
    x = x - 1;
    return make_pair(x / 3, x % 3);
}

// checks the position of the knight whether its in the inner or outer graph of length 6 or 10
bool find(int chess[ROWS][COLS], const vector<int>& subgraph) {
   
    //if it's the innerGraph which consists of 6 vertices then check the knight positions and return true 
    if (subgraph.size() == 6) {
        if (chess[0][1] == 1 && chess[3][1] == 2) {
            return true;
        }
    }
    //if it's the outerGraph which consists of 6 vertices then check the knight positions and return true
    else if (subgraph.size() == 10) {
        if (chess[0][0] == 1 && chess[0][2] == 1 && chess[3][0] == 2 && chess[3][2] == 2) {
            return true;
        }
    }
    return false;
}

// Recursive function to solve the chess game
//solves the inner graph that consists of 1 white against 1 black
void chessGame(int chess[ROWS][COLS], const vector<int>& innerGraph, const vector<int>& outerGraph) {
    
    //innerGraph consists of 2 knights against one another 1 black 1 white
    // outerGraph consists of 2 black knights against 2 white knights
       int n = 0;
    if (!innerGraph.empty() && !outerGraph.empty()) {
        chessGame(chess, innerGraph, {}); //sends divided partitions to solve either the inner graph and outer graph
        chessGame(chess, {}, outerGraph);
        return;
    }

    //check which graph im using (inner or outer)
    const vector<int>& board = (innerGraph.empty()) ? outerGraph : innerGraph;
    //create empty graph to add knights positions in it
    vector<int> knights;


    //loop in the given board to save knights position
    for (int node : board) {
        pair<int, int> cal_node = cal(node);
        if (chess[cal_node.first][cal_node.second] == 1 || chess[cal_node.first][cal_node.second] == 2) {
            knights.push_back(node);
        }
    }

    for (int i = 0; i < knights.size(); ++i) {
       
        /*Enumerate() method adds a counter to an iterable and returns it in a form of enumerating object.
        and Enumerates the knights*/
        int node1 = find(board.begin(), board.end(), knights[i]) - board.begin();
        int node2 = (i < knights.size() - 1) ? find(board.begin(), board.end(), knights[i + 1]) - board.begin() : find(board.begin(), board.end(), knights[0]) - board.begin();
        vector<int> subgraph;
        if (node2 > node1) {
            subgraph.assign(board.begin() + node1, board.begin() + node2);
        }
        else {
            subgraph.assign(board.begin() + node1, board.end());
            subgraph.insert(subgraph.end(), board.begin(), board.begin() + node2);
        }


        //keeps moving the knights on the board vertices until the knights are in their target positions
        for (int j = 0; j < subgraph.size() - 1; ++j) {
            moveKnight(chess, cal(subgraph[j]), cal(subgraph[j + 1]));
        }
    }

    // moves the knights to their correct positions
    for (int i = 0; i < knights.size(); ++i) {
        int nodex = find(board.begin(), board.end(), knights[i]) - board.begin();
        int nodey = (nodex != 0) ? nodex - 1 : board.size() - 1;
        n++;
        moveKnight(chess, cal(board[nodey]), cal(board[nodex]));
    }


    //checks if the sent boards are the innerGraph or outerGraph
    if (find(chess, innerGraph) && outerGraph.empty()) {
        return;
    }
    else if (!outerGraph.empty()) {
        chessGame(chess, innerGraph, {});
    }
    else if (find(chess, outerGraph) && innerGraph.empty()) {
        return;
    }
    else if (!innerGraph.empty()) {
        chessGame(chess, {}, outerGraph);
    }
}

int main() {
    cout << "Game starts NOW" << endl;
    vector<int> innerGraph = { 6, 11, 4, 9, 2, 7 };
    vector<int> outerGraph = { 1, 8, 3, 4, 9, 10, 5, 12, 7, 6 };
    chessGame(chess, innerGraph, outerGraph);

    return 0;
}
