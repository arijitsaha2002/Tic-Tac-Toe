# include<iostream>
# include<stdlib.h>
# include<time.h>
# include"game.h"
using namespace std;



class Game : public Tic_Tac_Tao {

public:
	void move() {
		int a;
		do {
			cout << " Enter your position " << endl;
			cin >> a;
		} while (!input(a / 10, a % 10));
	}
	void first_move() {
		int i = rand() % 3 + 1;
		if (i == 2)
		{
			input(i-1, i-1,me);
		}
		else {
			int j = rand() % 2 + 1;
			input(i - 1, 2 * j - 2, me);
		}
	}
	int min_max(bool is_me) {
		if (win() == oponent)
		{
			return -20;
		}
		if (win() == me)
		{
			return 20;
		}
		if (no_move())
		{
			return 0;
		}

		if (is_me)
		{
			int best = -500;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (is_empty(i, j))
					{
						input(i, j, me);
						int min_ma = min_max(false);
						best = max(best, min_ma);
						make_empty(i, j);
					}
				}
			}
			return best;
		}

		else
		{
			int best = 500;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (is_empty(i, j))
					{
						input(i, j);
						int min_ma = min_max(true);
						best = min(best, min_ma);
						make_empty(i, j);
					}
				}
			}
			return best;
		}
		return 0;

	}
	bool my_move() {
		if (win()!=emp)
		{
			return false;
		}
		int x = -1, y = -1, best_move = -500;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (is_empty(i, j))
				{
					input(i, j, me);
					int score = min_max(false);
					if (score > best_move)
					{
						x = i; y = j;
						best_move = score;
					}
					make_empty(i, j);
				}
			}
		}
		input(x, y, me);
		if(win()==me){
			return false;
		}
		return true;
	}


};
