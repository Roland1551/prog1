/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/


#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
using namespace Graph_lib;


int main()
{
Point kezdo(100, 300);
int x_size = 800;
int y_size = 1000;

Simple_window win {Point(kezdo),x_size,y_size,"Meine Window"};

int x_grid = 100;
int y_grid= 100;

Lines grid;
for(int x=x_grid; x<=x_size; x+=x_grid)
	grid.add(Point{x,0},Point{x,y_size-200});
for(int y=y_grid; y<=y_size-200; y+=y_grid)
	grid.add(Point{0, y},Point{x_size,y});

Vector_ref<Rectangle> kocka;
	for(int i=0;i<8;i++)
	{
		kocka.push_back(new Rectangle {Point{i*100,i*100}, 100, 100});
		kocka[i].set_fill_color(Color::red);
		win.attach(kocka[i]);
	}

Image one {Point{0,400},"200.jpeg"};
Image two {Point{300,600},"200.jpeg"};
Image three {Point{400,0},"200.jpeg"};
Image szaz {Point{0,0},"100.jpeg"};

win.attach(grid);
win.attach(one);
win.attach(two);
win.attach(three);
win.attach(szaz);
win.wait_for_button();

int column=0;
while(true)
{
	for(int i=0;i<7;i++)
	{
		szaz.move(0,100);
		win.wait_for_button();
	}
	if(column==7)
	{
		column=0;
		szaz.move(-700,-700);
	}
	else
	{
		szaz.move(100,-700);
		column++;
	}
	win.wait_for_button();

}

}