# include<iostream>
# include<stdlib.h>
# include<time.h>
using namespace std;

const char emp = '_';
const char me = 'o';
const char oponent = 'x';

class Tic_Tac_Tao;
class Game;



class Tic_Tac_Tao {
protected:
	void dis(char a) {
		cout << "|" << a;
		return;
	}
	bool is_empty(int i, int j) {
		if (position[i][j] == emp)
		{
			return true;
		}
		return false;
	}

	void make_empty(int i, int j) {
		if (is_empty(i, j))
		{
			cout << "this shell is already empty \n";
			return;
		}
		position[i][j] = emp;

	}
	char show_position(int i, int j) {
		return position[i][j];
	}

public:
	char position[3][3];
	Tic_Tac_Tao() {
		for (int j = 0; j < 3; ++j)
		{
			for (int i = 0; i < 3; ++i) { position[i][j] = emp;}
		}
	}
	char win() {
		for (int i = 0; i < 3; ++i)
		{
			if (position[i][0] == position[i][1] && position[i][1] == position[i][2])
			{
				if (position[i][0] != emp)
				{
					return position[i][0];
				}
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			if (position[0][i] == position[1][i] && position[1][i] == position[2][i])
			{
				if (position[0][i] != emp)
				{
					return position[0][i];
				}

			}
		}
		if (position[0][0] == position[1][1] && position[1][1] == position[2][2])
		{
			if (position[0][0] != emp)
			{
				return position[0][0];
			}
		}
		if (position[0][2] == position[1][1] && position[1][1] == position[2][0])
		{
			if (position[0][2] != emp)
			{
				return position[0][2];
			}
		}
		return emp;

	}

	virtual void display() {
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j) { dis(position[i][j]); }
			cout << "|" << endl;
		}

		cout << endl;
		return;
	}

	bool input(int i, int j, char a = oponent) {
		if ( i >= 0 && i < 3 && j >= 0 && j < 3)
		{

			if (position[i][j] == emp)
			{
				position[i][j] = a;
				return true;
			}
		}

		cout << "Invalid input" << endl;
		return false;
	}
	bool no_move() {
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (is_empty(i, j))
				{
					return false;
				}
			}
		}
		return true;
	}
	void Win_cheker() {
		if (no_move() || win() != emp)
		{
			if (win() == me)
			{
				cout << "!! Game Over !!" << endl;
			}
			else if (win() == oponent)
			{
				cout << "Congratulation !!" << endl;
			}
			else
			{
				cout << "! match draw !" << endl;
			}
			return;
		}
		return;
	}




};
