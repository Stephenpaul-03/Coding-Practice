#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

void print_board() {
    cout << board[0] + " | " + board[1] + " | " + board[2] << endl;
    cout << board[3] + " | " + board[4] + " | " + board[5] << endl;
    cout << board[6] + " | " + board[7] + " | " + board[8] << endl;
}

void take_turn(string player) {
    cout << player + "'s turn." << endl;
    string position;
    cin >> position;
    while (position != "1" && position != "2" && position != "3" && position != "4" && position != "5" && position != "6" && position != "7" && position != "8" && position != "9") {
        cin >> position;
    }
    int pos = stoi(position) - 1;
    while (board[pos] != "-") {
        cin >> position;
        pos = stoi(position) - 1;
    }
    board[pos] = player;
    print_board();
}

string check_game_over() {
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != "-") || 
        (board[3] == board[4] && board[4] == board[5] && board[3] != "-") || 
        (board[6] == board[7] && board[7] == board[8] && board[6] != "-") || 
        (board[0] == board[3] && board[3] == board[6] && board[0] != "-") || 
        (board[1] == board[4] && board[4] == board[7] && board[1] != "-") || 
        (board[2] == board[5] && board[5] == board[8] && board[2] != "-") || 
        (board[0] == board[4] && board[4] == board[8] && board[0] != "-") || 
        (board[2] == board[4] && board[4] == board[6] && board[2] != "-")) {
        return "win";
    } 
    else if (find(board.begin(), board.end(), "-") == board.end()) {
        return "tie";
    } 
    else {
        return "play";
    }
}

void play_game() {
    print_board();
    string current_player = "X";
    bool game_over = false;
    while (!game_over) {
        take_turn(current_player);
        string game_result = check_game_over();
        if (game_result == "win") {
            cout << current_player + " wins!" << endl;
            game_over = true;
        } 
        else if (game_result == "tie") {
            cout << "It's a tie!" << endl;
            game_over = true;
        } 
        else {
            current_player = (current_player == "X") ? "O" : "X";
        }
    }
}

int main() {
    play_game();
    return 0;
}
