#include <iostream>
using namespace std;

class Figure{
    int side1;
public:
    Figure(){
        side1 = 0;
    }
    Figure(int s){
        side1 = s;
    }
    int getS(){
        return side1;
    }
};

class Triangle : public Figure{
    int height;
public:
    Triangle() : Figure(){
        height = 0;
    }
    Triangle(int s, int h) : Figure(s){
        height = h;
    }
    int GetSquare(){
        return this->getS() * height;
    };
    int GetPerimeter(){
        return this->getS() * 3;
    }
    void Show(){
        cout << "Side: " << this->getS() << endl;
        cout << "Height: " << height << endl;
    }
};

class Square : public Figure{
public:
    Square() : Figure(){
    }
    Square(int s) : Figure(s){
    }
    int GetSquare(){
        return this->getS() * this->getS();
    };
    int GetPerimeter(){
        return this->getS() * 4;
    }
    void Show(){
        cout << "Side: " << this->getS() << endl;
    }
    int getSquareS(){
        return this->getS();
    }
};

class Rectangle : public Figure{
    int side2;
public:
    Rectangle() : Figure(){
    }
    Rectangle(int s1, int s2) : Figure(s1){
        side2 = s2;
    }
    int GetSquare(){
        return this->getS() * side2;
    };
    int GetPerimeter(){
        return this->getS() * 2 + side2 * 2;
    }
    void Show(){
        cout << "Side1: " << this->getS() << endl;
        cout << "Side2: " << side2 << endl;
    }
};

class Circle : public Figure{
public:
    Circle() : Figure(){
    }
    Circle(int s) : Figure(s){
    }
    int GetSquare(){
        return (this->getS()/2) * (this->getS()/2) * 3.14;
    };
    int GetPerimeter(){
        return this->getS() * 3.14;
    }
    void Show(){
        cout << "Diameter: " << this->getS() << endl;
    }
    int getCircleS(){
        return this->getS();
    }
};

class Circle_in_Square : Circle, Square{
public:
    Circle_in_Square() : Square(), Circle(){
    }
    Circle_in_Square(int s) : Square(s), Circle(s){
    }
    int GetCircleSquare(){
        return (this->getCircleS()/2) * (this->getCircleS()/2) * 3.14;
    };
    int GetSquareSquare(){
        return this->getSquareS() * this->getSquareS();
    };
    int GetCirclePerimeter(){
        return this->getCircleS() * 3.14;
    }
    int GetSquarePerimeter(){
        return this->getSquareS() * 4;
    }
    void Show(){
        cout << "Square side: " << this->getSquareS() << endl;
        cout << "Diameter: " << this->getCircleS() << endl;
    }
};

int main() {
    Triangle t(10, 25);
    cout << t.GetSquare() << endl;
    Square s(15);
    cout << s.GetPerimeter() << endl;
    Rectangle r(5, 15);
    r.Show();
    Circle c(65);
    cout << c.GetPerimeter() << endl;
    Circle_in_Square cis(12);
    cis.Show();
}
