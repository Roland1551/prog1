

#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities

int main()
{
using namespace Graph_lib; // our graphics facilities are in Graph_lib

Point kezdo {150, 150};

Simple_window win {kezdo, 600, 400, "My Window"};

Axis xt {Axis::x, Point{50, 270}, 230, 10, "x Tengely"};
Axis yt {Axis::y, Point{50, 270}, 200, 10, "y Tengely"};
	yt.set_color(Color::dark_red);
	yt.label.set_color(Color::dark_red);


	Function szinusz {sin, 0, 5, Point{50,220}, 1000, 50, 50};
		szinusz.set_color(Color::dark_blue);

	Polygon poligon;
		poligon.add(Point{80, 100});
		poligon.add(Point{150, 200});
		poligon.add(Point{300, 250});
			poligon.set_color(Color::dark_green);
			poligon.set_fill_color(Color::blue);
			poligon.set_style(Line_style(Line_style::dash,3));


	Rectangle teglalap{Point{50,273}, 150, 27};

	Closed_polyline Poli_teglalap;
		Poli_teglalap.add(Point{50, 300});
		Poli_teglalap.add(Point{200, 300});
		Poli_teglalap.add(Point{200, 350});
		Poli_teglalap.add(Point{50, 350});
		Poli_teglalap.add(Point{20, 320});
			Poli_teglalap.set_fill_color(Color::yellow);

	Text szoveg {Point{50,20}, "Ime a gyonyoru muvem:"}; 
		szoveg.set_font(Font::times_bold);
		szoveg.set_font_size(15);

		Image cj {Point{250,20}, "cj.jpeg"};


	Circle kor{Point{120, 160}, 40};
	Mark jel {Point{10, 30},'X'};

	Image arn {Point{200,200},"arnold.gif"};
	arn.set_mask(Point{40,40},200,200);

	Ellipse elipszis {Point{200,300}, 100,50};


win.attach(arn);
win.attach(jel);
win.attach(kor);
win.attach(cj);
win.attach(szoveg);
win.attach(Poli_teglalap);
win.attach(teglalap);
win.attach(poligon);
win.attach(szinusz);
win.attach(xt);
win.attach(yt);
win.attach(elipszis);
win.set_label("My second window");
win.wait_for_button();

}