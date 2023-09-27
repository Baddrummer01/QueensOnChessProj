#include <iostream>
#include <vector>

using namespace std;

//this method checks whether or not the queen's position is valid or not. Put in a separate method because it was getting way too convoluted to put it in one function
bool checkIfValid(int row, int col, int n, vector<vector<char>> &GameBoard) {
  //traverses up from the character that was placed to check for more
  for (int i = row; i >= 0; i--) {
    //if location found contains a queen, the location is false
    if (GameBoard[i][col] == 'X') {
      return false;
    }
  }

  //traverses up and to the right from the character that was placed
  for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
    //if location found contains a queen, the location is false
    if (GameBoard[i][j] == 'X') {
      return false;
    }
  }

  //traverses up and to the left from the character that was placed
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    //if location found contains a queen, the location is false
    if (GameBoard[i][j] == 'X') {
      return false;
    }
  }
  //indicates that no queens are in the attack range of this queen
  return true;
}

//nqueens doesn't have enough variables to recurse effectively enough for me
bool numSolutions(int currRow, int n, int &numSol, vector<vector<char>> &GameBoard) {
  bool validBoard = false;
  //if the recursive function gets here it means a valid board has been created
  if (currRow == n) {
    numSol++;
    validBoard = true;
    return validBoard;
  }

  for (int i = 0; i < n; i++) {
    //checks the columns of a row one by one for a valid positioning
    if (checkIfValid(currRow, i, n, GameBoard)) {
      GameBoard[currRow][i] = 'X';
      //recurses by going to the next row
      validBoard = numSolutions(currRow + 1, n, numSol, GameBoard);
      //replaced with space since after recursion the board needs to check a different location
      GameBoard[currRow][i] = ' '; 
    }
  }
  return validBoard;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
  //creating a 2d vector filled with empty spaces
  vector<vector<char>> GameBoard(n, (vector<char> (n, ' ')));
  int numSol = 0;
  numSolutions(0, n, numSol, GameBoard);
  return numSol;
}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
