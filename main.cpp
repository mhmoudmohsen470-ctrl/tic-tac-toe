#include <iostream>
using namespace std;

bool checkWin(char board[3][3], char currentletter) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentletter && board[i][1] == currentletter && board[i][2] == currentletter) {
            return true;
        }
        if(board[0][i] == currentletter && board[1][i] == currentletter && board[2][i] == currentletter) {
            return true;
        }
    }
    if(board[0][0] == currentletter && board[1][1] == currentletter && board[2][2] == currentletter) {
        return true;
    }
    if(board[0][2] == currentletter && board[1][1] == currentletter && board[2][0] == currentletter) {
        return true;
    }
    return false;
}
int main() {
    string name1, name2;
    char currentletter;
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    cout << "Welcome to the tic-tac-toe game!" << endl;
    cout << "Enter the name of player 1: ";
    getline(cin, name1);
    cout << "Enter the name of player 2: ";
    getline(cin, name2);
    cout << name1 << ", choose X or O: ";
    cin >> currentletter;
    if(currentletter == 'X' || currentletter == 'x') {
        cout << name1 << " will be X and " << name2 << " will be O." << endl;
    } else if(currentletter == 'O' || currentletter == 'o') {
        cout << name1 << " will be O and " << name2 << " will be X." << endl;
    } else {
        cout << "Invalid choice. Defaulting to X for " << name1 << " and O for " << name2 << "." << endl;
        currentletter = 'X';
    }
    if (currentletter == 'x')
    { currentletter = 'X'; }
    if (currentletter == 'o')
    { currentletter = 'O';
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << endl;
        if(i < 2) cout << "---------" << endl;
    }
    bool won = false;
    string currentname;
    for(int turn = 0; turn < 9; turn++) {
        if(turn % 2 == 0) {
            currentname = name1;
            cout << name1 << ", enter the position for " << currentletter << " (row and column): ";
        } else {
            currentname = name2;
            cout << name2 << ", enter the position for " << currentletter << " (row and column): ";
        }
        int row, col;
        cin >> row >> col;
        row--;
        col--;
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid position. Try again." << endl;
            turn--;
            continue;
        }
        board[row][col] = currentletter;
        if(checkWin(board, currentletter)) {
            cout << currentname << " wins!" << endl;
            won = true;
            break;
            }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << board[i][j];
                if(j < 2) cout << " | ";
            }
            cout << endl;
            if(i < 2) cout << "---------" << endl;
        }
            if(currentletter == 'X') {
                currentletter = 'O';
            } else {
                currentletter = 'X';
            }
        }
        if(!won) {
            cout << "It's a draw!" << endl;
        }
    return 0;
}