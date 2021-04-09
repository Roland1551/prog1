#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities

double one(double x)
	{return 1;}

double slope(double x)
	{return x/2;}

double square(double x)
	{return x*x;}

double sloping_cos(double x)
{return cos(x)+slope(x);}

struct Person
{
public:
string name;
int age;
};

int main()
{
using namespace Graph_lib; // our graphics facilities are in Graph_lib

Point kezdo{100,100};
Simple_window win {kezdo, 600, 600, "Function graphs."};

Axis xt {Axis::x, Point{100, 300}, 400, 20, "1 = = 20 pixels"};
Axis yt {Axis::y, Point{300, 500}, 400, 20, "1 = = 20 pixels"};
	yt.set_color(Color::red);


Function one_const{one, -10, 11, Point{300,300}, 400, 20, 20};
Function slopee{slope, -10, 11, Point{300,300}, 400, 20, 20};
	Text label {Point(110,360), "x/2"};

Function squaree{square, -10, 11, Point{300,300}, 400, 20, 20};

Function cosine{[] (double x) {return cos(x);},-10, 11, Point{300,300}, 400, 20, 20};
cosine.set_color(Color::blue);

Function sc{sloping_cos, -10, 11, Point{300,300}, 400, 20, 20};

Person p1;
p1.name = "Goofy";
p1.age = 63;

cout << p1.name << ' ' << p1.age << endl;

win.attach(sc);
win.attach(cosine);
win.attach(squaree);
win.attach(label);
win.attach(one_const);
win.attach(slopee);
win.attach(xt);
win.attach(yt);
win.wait_for_button();
}