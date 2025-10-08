#include <iostream>
#include<string>
#include<windows.h>
#include <limits>

using namespace std;
void name(string& name1, string& name2)
{
	cout << "Enter name of 1st Player: ";
	cin >> name1;
	cout << endl;
	cout << "Enter name of 2nd Player: ";
	cin >> name2;
	cout << endl;
}
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void board(char arr[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 5; j++)
			{
				if (j == 1 || j == 3)
				{
					arr[i][j] = '|';
				}
				else
				{
					arr[i][j] = ' ';
				}
			}
		}
		else
		{
			for (int j = 0; j < 5; j++)
			{
				arr[i][j] = '-';
			}
		}
	}
}
void row_input(int& row)
{
	cout << endl;
	while (true)
	{
		cout << "Enter row (1-3): ";
		if (!(cin >> row)) {
			cin.clear(); // clear error flag
			cin.ignore(10000, '\n');
			cout << "Invalid input. Please enter a number between 1 and 3." << endl;
			continue;
		}

		if (row < 1 || row > 3) {
			cout << "Invalid range. Try again." << endl;
			continue;
		}

		break;
	}

	// Convert to 2D array index
	if (row == 1) row = 0;
	else if (row == 2) row = 2;
	else if (row == 3) row = 4;
}
void col_input(int& col)
{
	while (true)
	{
		cout << "Enter column (1-3): ";
		if (!(cin >> col)) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Please enter a number between 1 and 3." << endl;
			continue;
		}

		if (col < 1 || col > 3) {
			cout << "Invalid range. Try again." << endl;
			continue;
		}

		break;
	}

	// Convert to 2D array index
	if (col == 1) col = 0;
	else if (col == 2) col = 2;
	else if (col == 3) col = 4;
}
void print(char arr[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == 'X') {
				setColor(12);  // Red for X
				cout << 'X';
				setColor(9);   // Back to light blue for grid
			}
			else if (arr[i][j] == 'O') {
				setColor(14);  // Yellow for O
				cout << 'O';
				setColor(9);
			}
			else {
				setColor(9);   // Light blue grid and spaces
				cout << arr[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
	setColor(7); // Reset color to white/default
}
void player1(char arr[5][5])
{
	int row = 0;
	int col = 0;
	cout << endl;
	row_input(row);
	col_input(col);
	cout << endl;
	if (arr[row][col] == ' ')
	{
		arr[row][col] = 'X';
	}
	else
	{
		while (arr[row][col] != ' ')
		{
			if (arr[row][col] == 'X')
			{
				cout << "You already occupied that space, try again." << endl;
				row_input(row);
				col_input(col);
			}
			else if (arr[row][col] == 'O')
			{
				cout << "Space is occupied by opponent, try again." << endl;
				row_input(row);
				col_input(col);
			}
		}
		arr[row][col] = 'X';
	}
}
void player2(char arr[5][5])
{
	int row = 0;
	int col = 0;
	cout << endl;
	row_input(row);
	col_input(col);
	cout << endl;
	if (arr[row][col] == ' ')
	{
		arr[row][col] = 'O';
	}
	else
	{
		while (arr[row][col] != ' ')
		{
			if (arr[row][col] == 'O')
			{
				cout << "You already occupied that space, try again." << endl;
				row_input(row);
				col_input(col);
			}
			else if (arr[row][col] == 'X')
			{
				cout << "Space is occupied by opponent, try again." << endl;
				row_input(row);
				col_input(col);
			}
		}
		arr[row][col] = 'O';
	}
}
bool end(char arr[5][5], bool check, string name1, string name2)
{
	if (arr[0][0] == 'X' && arr[0][2] == 'X' && arr[0][4] == 'X')
	{
		setColor(10); // Green for win
		cout << name1 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[2][0] == 'X' && arr[2][2] == 'X' && arr[2][4] == 'X')
	{
		setColor(10); // Green for win
		cout << name1 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[4][0] == 'X' && arr[4][2] == 'X' && arr[4][4] == 'X')
	{
		setColor(10); // Green for win
		cout << name1 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][0] == 'X' && arr[2][2] == 'X' && arr[4][4] == 'X')
	{
		setColor(10); // Green for win
		cout << name1 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][4] == 'X' && arr[2][2] == 'X' && arr[4][0] == 'X')
	{
		setColor(10); // Green for win
		cout << name1 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][0] == 'X' && arr[2][0] == 'X' && arr[4][0] == 'X')
	{
		setColor(10); // Green for win
		cout << name1 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][2] == 'X' && arr[2][2] == 'X' && arr[4][2] == 'X')
	{
		setColor(10); // Green for win
		cout << name1 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][4] == 'X' && arr[2][4] == 'X' && arr[4][4] == 'X')
	{
		cout << name1 << " won the match." << endl;
		check = true;
	}
	else if (arr[0][0] == 'O' && arr[0][2] == 'O' && arr[0][4] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[2][0] == 'O' && arr[2][2] == 'O' && arr[2][4] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[4][0] == 'O' && arr[4][2] == 'O' && arr[4][4] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][0] == 'O' && arr[2][2] == 'O' && arr[4][4] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][4] == 'O' && arr[2][2] == 'O' && arr[4][0] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][0] == 'O' && arr[2][0] == 'O' && arr[4][0] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][2] == 'O' && arr[2][2] == 'O' && arr[4][2] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else if (arr[0][4] == 'O' && arr[2][4] == 'O' && arr[4][4] == 'O')
	{
		setColor(10); // Green for win
		cout << name2 << " won the match!" << endl;
		setColor(7);
		check = true;
	}
	else
	{
		check = false;
	}

	return check;
}
bool draw(char arr[5][5])
{
	int count = 0;
	for (int i = 0; i < 5; i += 2)
	{
		for (int j = 0; j < 5; j += 2)
		{
			if (arr[i][j] == 'X' || arr[i][j] == 'O')
			{
				count++;
			}
		}
	}
	if (count == 9)
	{
		setColor(13); 
		cout << "Neither player won the match, It's a draw." << endl;
		setColor(7);
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	setColor(11);  
	cout << "======TIC-TAC-TOE GAME====== " << endl;
	setColor(7);
	cout << endl;

	string name1, name2;
	name(name1, name2);
	cout << "Symbol for " << name1 << ": X" << endl;
	cout << "Symbol for " << name2 << ": O" << endl;
	cout << endl;
	char game[5][5];

	board(game);
	setColor(9); // Light blue grid
	print(game);

	cout << endl;

	bool win = false;
	while (true)
	{
		if (end(game, win, name1, name2))
		{
			break;
		}
		else if (draw(game))
		{
			break;
		}
		else
		{
			cout << name1 << "'s turn: " << endl;
			player1(game);
			cout << endl;
			setColor(9); // Light blue grid
			print(game);
		}
		if (end(game, win, name1, name2))
		{
			break;
		}
		else if (draw(game))
		{
			break;
		}
		else
		{
			cout << name2 << "'s turn: " << endl;
			player2(game);
			cout << endl;
			setColor(9); // Light blue grid
			print(game);
		}
	}
}