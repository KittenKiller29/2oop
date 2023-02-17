#include<iostream>
#include<conio.h>
class Rectangle {
public:
	Rectangle() {//конструктор по умолчанию
		length = 10;
		width = 20;
		square = length * width;
		
		std::cout << "Rectangle()" << std::endl;
	};
	Rectangle(int length, int width) {//конструктор c параметрами
		this->length = length;
		this->width = width;
		square = length * width;
		
		std::cout << "Rectangle(int length,int width)" << std::endl;
	};
	Rectangle(const Rectangle& copyrectangle) {//конструктор копирования
		length = copyrectangle.length;
		width = copyrectangle.width;
		square = length * width;
		
		std::cout << "Rectangle(const Rectangle& copyrectangle)" << std::endl;
	};
	~Rectangle() {
		std::cout << length << std::endl << width << std::endl << square << std::endl;
		
		std::cout << "~Rectangle()" << std::endl;
	};
	void lwChange(int dlength, int dwidth) {//метод изменения значений свойств
		length += dlength;
		width += dwidth;
		square = length * width;
	}
	
	void lwSwap();//метод замены значения свойств друг на друга
protected:
	int square;
	int length;
	int width;

};

void Rectangle::lwSwap() {//реализация метода вне описания класса
	int temp = length;
	length = width;
	width = temp;
}

class ColoredRectangle : public Rectangle{
public:
	ColoredRectangle() : Rectangle() {//конструктор по умолчанию
		
		std::cout << "ColoredRectangle()" << std::endl;
	};
	ColoredRectangle(int length, int width,int color) : Rectangle(length,width) {//конструктор c параметрами
		this->length = length;
		this->width = width;
		square = length * width;
		this->color = color;
		
		std::cout << "ColoredRectangle(int length,int width,int color)" << std::endl;
	};
	ColoredRectangle(const ColoredRectangle& copyrectangle) {//конструктор копирования
		length = copyrectangle.length;
		width = copyrectangle.width;
		color = copyrectangle.color;
		
		std::cout << "ColoredRectangle(const Rectangle& copyrectangle)" << std::endl;
	};
	~ColoredRectangle() {
		std::cout << length << std::endl << width << std::endl ;
		std::cout << square << std::endl << color << std::endl;
		std::cout << "~ColoredRectangle()" << std::endl;
	};
	void colorSet(int color) {//метод установки цвета
		this->color = color;
	}
	
protected:
	int color;
};

class Parallelepiped {
protected:
	Rectangle* r1;
	Rectangle* r2;
	Rectangle* r3;
	Rectangle* r4;
	Rectangle* r5;
	Rectangle* r6;
public:
	Parallelepiped()  {//конструктор по умолчанию
		std::cout << "Parallelepiped()" << std::endl;
		r1 = new Rectangle;
		r2 = new Rectangle;
		r3 = new Rectangle;
		r4 = new Rectangle;
		r5 = new Rectangle;
		r6 = new Rectangle;
	};
	Parallelepiped(int length, int width, int high)  {//конструктор c параметрами
		std::cout << "Parallelepiped(int length,int width,int high)" << std::endl;
		r1 = new Rectangle(length, width);
		r2 = new Rectangle(length, width);
		r3 = new Rectangle(high, width);
		r4 = new Rectangle(high, width);
		r5 = new Rectangle(length, high);
		r6 = new Rectangle(length, high);
	};
	Parallelepiped(const Parallelepiped& parallelepiped) {//конструктор копирования
		std::cout << "Parallelepiped(const Parallelepiped& parallelepiped)" << std::endl;
		r1 = new Rectangle(*(parallelepiped.r1));
		r2 = new Rectangle(*(parallelepiped.r2));
		r3 = new Rectangle(*(parallelepiped.r3));
		r4 = new Rectangle(*(parallelepiped.r4));
		r5 = new Rectangle(*(parallelepiped.r5));
		r6 = new Rectangle(*(parallelepiped.r6));
	};
	~Parallelepiped() {
		delete r1;
		delete r2;
		delete r3;
		delete r4;
		delete r5;
		delete r6;
		std::cout << "~Parallelepiped()" << std::endl;
	};
};

int main()
{
	Parallelepiped* a = new Parallelepiped;
	Parallelepiped* b = new Parallelepiped(*a);
	delete a;
	delete b;
	_getch();
	return 0;
}