#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
# include"next_move.h"
#include <time.h>
using namespace std;

const int Window_H = 800;
const int Window_W = 800;
const int color_box = 0;
const int color_font = 5;
const int color_end = 17;
const int box_length = Window_H / 3;
bool  end_game = false;
Game game;

void draw_line() {
	fl_color(2);
	fl_line(0, Window_H / 3, Window_W, Window_H / 3);
	fl_color(2);
	fl_line(Window_W / 3, 0, Window_W / 3, Window_H);
	fl_color(2);
	fl_line(0, 2 * Window_H / 3, Window_W, 2 * Window_H / 3);
	fl_color(2);
	fl_line(2 * Window_W / 3, 0, 2 * Window_W / 3, Window_H);

}


void box_creater(int a, int b, char c = empty) {
	int box_l = Window_H / 3;
	fl_color(color_box);
	fl_polygon(box_l * a, box_l * b, box_l * (a + 1), box_l * b, box_l * (a + 1), box_l * (b + 1), box_l * a, box_l * (b + 1));
	if (c != empty) {
		if (c == oponent)
		{
			fl_color(color_font);
			fl_font(FL_BOLD, 80);
			fl_draw("x", box_length * a + box_length / 3, box_length * b + box_length / 3);
		}
		if (c == me)
		{
			fl_color(color_font);
			fl_font(FL_BOLD, 80);
			fl_draw("o", box_length * a + box_length / 3, box_length * b + box_length / 3);
		}
	}
}

void Win_chek() {

	if (game.no_move() || game.win() != empty)
	{
		if (game.win() == me)
		{
			fl_color(color_end);
			fl_font(FL_COURIER, 50);
			fl_draw("!! game over !!", Window_W / 4, Window_H / 3);
		}
		else if (game.win() == oponent)
		{
			fl_color(color_end);
			fl_font(FL_COURIER, 50);
			fl_draw("!! CONGRATULATION !!", Window_W / 4, Window_H / 3);
		}
		else
		{
			fl_color(color_end);
			fl_font(FL_COURIER, 50);
			fl_draw("!! Match Draw !!", Window_W / 4, Window_H / 3);
		}
		end_game = true;
		return;
	}
	return;
}
void displ() {

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			box_creater(i, j, game.position[i][j]);
		}
	}
	draw_line();
}


bool toss() {
	if (rand() % 2 == 1)
	{
		return true;
	}

	return false;
};


class My_Program : public Fl_Widget {
	int counter;
public:
	My_Program(): Fl_Widget(0, 0, Window_H, Window_W, 0) {
		counter = 0;
	}
	void draw() {
		if (toss())
		{
			game.first_move();
			displ();
		}
		draw_line();

	}
	int handle(int e) {
		if (e == FL_PUSH && !end_game)
		{	counter++;
			int x, y;
			x = Fl::event_x() / ( box_length);
			y = Fl::event_y() / ( box_length);

			if(!game.input(x, y)){
				return 1;
			}
			displ();
			Win_chek();
			game.my_move();
			displ();
			Win_chek();
		}
		return 1;
	}
};


int main() {
	srand(time(0));
	Fl_Window w(Window_W, Window_H);
	w.color(0);
	My_Program p;
	w.show();
	return Fl::run();
}
