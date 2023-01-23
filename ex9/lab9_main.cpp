#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <random>


using namespace std;

//definition of class Point
class Point {
public:
    //constructor
    Point(double xcoord = 0.0, double ycoord = 0.0);
    // destructor
    virtual ~Point() = default;
    virtual void input(const char* prompt);
    virtual void output() const;
    virtual double area() const;
    void move(double deltax, double deltay);
private:
    double x;
    double y;
};

class Circle: public Point {
public:
    //constructor
    Circle(double xcoord = 0.0, double ycoord = 0.0,double radius = 0.0);
    Circle(Point &pp, double radiuss);

    virtual void input(const char* prompt) override;
    virtual void output() const override;
    virtual double area() const override;
    
private:
   double radius;
};

class Square: public Point {
public:
    //constructor
    Square(double xcoord = 0.0, double ycoord = 0.0,double width = 0.0,double height =0.0);
    Square(Point &pp, double width, double height);

    virtual void input(const char* prompt) override;
    virtual void output() const override;
    virtual double area() const override;
    
private:
   double width;
   double height;
};


Circle::Circle(double xcoord , double ycoord,double radiuss ):Point(xcoord,ycoord),radius(radiuss){}
Circle::Circle(Point& pp, double radiuss) : Point(pp), radius(radiuss){}
Point::Point(double xcoord , double ycoord ):x(xcoord), y(ycoord){}
Square::Square(double xcoord , double ycoord ,double widths , double heights ):Point(xcoord,ycoord),width(widths),height(heights){}
Square::Square(Point& pp, double widths, double heights) : Point(pp),width(widths),height(heights){}




void Point::input(const char* prompt){

    cout << prompt << endl;
    cout << "Enter x:"; 
    cin >> x;
    cout << "Enter y:"; 
    cin >> y;
}

void Point::output() const{

    cout << "Coordinates: (" << x << ',' << y << ")\n";
}

double Point::area() const{

    return 0;
    
}
void Point::move(double deltax, double deltay){

    x = x + deltax;
    y = y + deltay;
}

void Circle::input(const char* prompt){

    Point::input(prompt);
    cout << "Enter Radius:";
    cin >> radius;
   
}

void Circle::output() const{

    double area = Circle::area();

    cout << "Circle's area:" << area << " ";
    Point::output();

}

double Circle::area() const{

    const float pi = 3.14159f;
    return  pi * radius * radius;

}

void Square::input(const char* prompt){

    Point::input(prompt);
    cout << "Enter height:";
    cin >> height;
    cout << "Enter width:";
    cin >> width;
}

void Square::output() const{

    double area = Square::area();

    cout << "Square's area:" << area << " ";
    Point::output();

}

double Square::area() const{

    
    return width * height;

}
//template <typename T>
//inline T const& Compare(T const& i , T const&j) {
//
//    return i.area < j.area ? j : i;
//
//}

bool Compare(Point *p1, Point *p2) {
    
    return (p1->area() < p2->area());
}

int main()
{
    srand(time(NULL));
    vector<Point*> ptarr;

    Point p;
    Circle c;
    Square s;
    ptarr.push_back(new Point(1.0,1.0));
    ptarr.push_back(new Circle(2.0,2.0,2.0));
    ptarr.push_back(new Square(5.0,5.0,2.0,2.0));
    
    s.input("Square:");
    c.input("Circle:");
    p.input("Point:");

    ptarr.push_back(new Square(s));
    ptarr.push_back(new Circle(c));
    ptarr.push_back(new Point(p));


    
    for (int i = 0; i < 6; i++) {
        ptarr[i]->output();
    }
    
    sort(ptarr.begin(), ptarr.end(),Compare);

    cout << "Sorted:\n";

    for (int i = 0; i < 6; i++) {
        ptarr[i]->output();
    }


    //EX 9B

    for (int i = 0; i < 5; ++i) {

        int random = rand() % 3;

        cout << '\n' << random << '\n';
        if (random == 0) {

            p.input("Point:");
            ptarr.push_back(new Point(p));

        }
        else if (random == 1) {

            c.input("Circle:");
            ptarr.push_back(new Circle(c));

        }
        else if (random == 2) {

            s.input("Square:");
            ptarr.push_back(new Square(s));

        }
    }
    
    for (int i = 0; i < 11; i++) {
        ptarr[i]->output();
    }

    sort(ptarr.begin(), ptarr.end(), Compare);

    cout << "Sorted:\n";

    for (int i = 0; i < 11; i++) {
        ptarr[i]->output();
    }


}