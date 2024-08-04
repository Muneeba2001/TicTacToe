#include<iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row; 
int column; 
int token = 'x';
bool tie = false;
string n1 = "";
string n2 = "";

void functionOne() {
    cout << "\n " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "\n";
    cout << "___|___|___\n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "\n";
    cout << "___|___|___\n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "\n";
    cout << "   |   |   \n";
}

void functionTwo() {
    int digit;
    if(token == 'x') {
        cout << n1 << "\n Please Enter : ";
        cin >> digit;
    } else if(token == '0') {
        cout << n2 << "\n Please Enter : ";
        cin >> digit;
    }
    
    if(digit == 1) {
        row = 0;
        column = 0;
    } else if(digit == 2) {
        row = 0;
        column = 1;
    } else if(digit == 3) {
        row = 0;
        column = 2;
    } else if(digit == 4) {
        row = 1;
        column = 0;
    } else if(digit == 5) {
        row = 1;
        column = 1;
    } else if(digit == 6) {
        row = 1;
        column = 2;
    } else if(digit == 7) {
        row = 2;
        column = 0;
    } else if(digit == 8) {
        row = 2;
        column = 1;
    } else if(digit == 9) {
        row = 2;
        column = 2;
    } else {
        cout << "\n Invalid!!!" << endl;
        return; // Early return to avoid further execution
    }

    if(token == 'x' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = 'x';
        token = '0';
    } else if(token == '0' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = '0';
        token = 'x';
    } else {
        cout << "There is no Empty space." << endl;
    }
    functionOne();
}

bool functionThree() {
    for(int i = 0; i < 3; i++) {
        if((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
           (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }
    if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
       (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Check for draw
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the First Person:\n";
    getline(cin, n1);
    cout << "Enter the name of the Second Person:\n";
    getline(cin, n2);
    cout << n1 << " will play first.\n";
    cout << n2 << " will play second.\n";

    while(!functionThree()) {
        functionOne();
        functionTwo();
    }

    if(!tie && token == '0') {
        cout << n1 << " Wins!!" << endl;
    } else if(!tie && token == 'x') {
        cout << n2 << " Wins!!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
