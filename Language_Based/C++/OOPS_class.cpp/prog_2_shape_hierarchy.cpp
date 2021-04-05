#include <iostream>
#include <cmath>

using namespace std;

class Shape {
    public:
    // Creating virtual functions
        virtual void area() {}
        virtual void perimeter() {}
};

// Derived circle class from base-class shape
class Circle : public Shape
{
    private:
        float x, y, r, ar, peri;
    public:
        Circle(float p1, float p2, float p3) {
            x = p1;
            y = p2;
            r = p3;
            cout << "Circle object => Center : (" << x << "," << y  << ") ; Radius : " << r << "\n" << endl;
        }
        
        void area() {
            ar = 3.14 * r * r;
            cout << "Area of circle : " << ar << " sq units." << endl;
        }
        
        void perimeter() {
            peri = 2 * 3.14 * r;
            cout << "Perimeter of circle : " << peri << " units." << endl;
        }
};


class Triangle : public Shape
{
    private:
        float x1, y1, x2, y2, x3, y3, l1, l2, l3, ar, peri;
    public:
        Triangle(float p1, float p2, float p3, float p4, float p5, float p6) {
            x1 = p1;
            x2 = p3;
            x3 = p5;
            y1 = p2;
            y2 = p4;
            y3 = p6;
            cout << "Triangle Object => Vertices : " << "(" <<x1<<","<<y1<<") ; " << "(" <<x2<<","<<y2<<") ; " << "(" <<x3<<","<<y3<<") " << endl << endl;
        }
        
        void area() {
            ar = 0.5 * ((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2)));
            cout << "Area of triangle : " << ar << " sq units." << endl;
        }
        
        void perimeter() {
            l1 = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
            l2 = sqrt(((x3-x2)*(x3-x2)) + ((y3-y2)*(y3-y2)));
            l3 = sqrt(((x3-x1)*(x3-x1)) + ((y3-y1)*(y3-y1)));
            peri = l1 + l2 + l3;
            cout << "Perimeter of triangle : " << peri << " units." << endl;
        }       
};

class Square : public Shape
{
    private:
        float x1, y1, x2, y2, ld, l, ar, peri;
    public:
        Square(float p1, float p2, float p3, float p4) {
            x1 = p1;
            x2 = p3;
            y1 = p2;
            y2 = p4;
            cout << "Square object => two corner points : " << "(" <<x1<<","<<y1<<") ; " << "(" <<x2<<","<<y2<<") " << endl << endl;
            ld = sqrt (((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
        }
        
        void area() {
            ar = ld * ld /2;
            cout << "Area of square : " << ar << " sq units." << endl;
        }
        
        void perimeter() {
            l = ld / (sqrt(2));
            peri = 4 * l;
            cout << "Perimeter of square : " << peri << " units." << endl;
        }
};


int main()
{	
	Shape* shapes[3]; // Creating array of pointers to shape objects
    // Creating the objects
    shapes[0] = new Circle(0, 1, 1);
    shapes[1] = new Square(2,2,4,4);
    shapes[2] = new Triangle(0,0, 5,0, 0,12);
	
	
    for (int i = 0; i < 3; i++) {
        // Calling both the functions through base-class pointers
        shapes[i]->perimeter();
        shapes[i]->area();
        cout << "\n";
    }
	
	return 0;
}
