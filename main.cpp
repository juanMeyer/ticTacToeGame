#include<iostream>
using namespace std;

void printArray(string arr[3][3]);
void placeObject(int x, int y, string arr[3][3], string xo);
bool checkForWin(string arr[3][3], string xo);

int main() {
    string arr[3][3]; // Declare a 2D array of strings
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            arr[i][j] = "[ * ]"; // Initialize the grid with empty spaces
        }
    }

    printArray(arr); // Print the array
    int x, y;
    
    while(true) { // Infinite loop until a player wins or exits
        // Player O's turn
        cout << "Enter x coordinate for Player O's choice or enter 9 to exit: ";
        cin >> x;
        if(x == 9) {
            break;
        }
        cout << "Enter y coordinate for Player O's choice: ";
        cin >> y;

        // Check if the position is already occupied
        while (arr[x][y] == "[ O ]" || arr[x][y] == "[ X ]") {
            cout << "Sorry, this location has already been played. Please choose a different position." << endl;
            cout << "Enter x coordinate for Player O's choice: ";
            cin >> x;
            cout << "Enter y coordinate for Player O's choice: ";
            cin >> y;
        }

        // Place Player O's move and print the updated grid
        placeObject(x, y, arr, "[ O ]");
        printArray(arr);

        // Check for Player O's win
        if(checkForWin(arr, "[ O ]")) {
            cout << "Player O wins!" << endl;
            break;
        }

        // Player X's turn
        cout << "Enter x coordinate for Player X's choice or enter 9 to exit: ";
        cin >> x;
        if(x == 9) {
            break;
        }
        cout << "Enter y coordinate for Player X's choice: ";
        cin >> y;

        // Check if the position is already occupied
        while (arr[x][y] == "[ O ]" || arr[x][y] == "[ X ]") {
            cout << "Sorry, this location has already been played. Please choose a different position." << endl;
            cout << "Enter x coordinate for Player X's choice: ";
            cin >> x;
            cout << "Enter y coordinate for Player X's choice: ";
            cin >> y;
        }

        // Place Player X's move and print the updated grid
        placeObject(x, y, arr, "[ X ]");
        printArray(arr);

        // Check for Player X's win
        if(checkForWin(arr, "[ X ]")) {
            cout << "Player X wins!" << endl;
            break;
        }
    }

    return 0;
}

void printArray(string arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " "; // Printing each string element
        }
        cout << endl;
    }
}

void placeObject(int x, int y, string arr[3][3], string xo) {
    arr[x][y] = xo; // Place the player’s symbol in the chosen location
}

bool checkForWin(string arr[3][3], string xo) {
    // Horizontal checks
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == xo && arr[i][1] == xo && arr[i][2] == xo) {
            return true; // Found a horizontal win
        }
    }

    // Vertical checks
    for (int j = 0; j < 3; j++) {
        if (arr[0][j] == xo && arr[1][j] == xo && arr[2][j] == xo) {
            return true; // Found a vertical win
        }
    }

    // Diagonal checks
    if (arr[0][0] == xo && arr[1][1] == xo && arr[2][2] == xo) {
        return true; // Found a diagonal win (top-left to bottom-right)
    }
    if (arr[0][2] == xo && arr[1][1] == xo && arr[2][0] == xo) {
        return true; // Found a diagonal win (top-right to bottom-left)
    }

    return false; // No win found
}
