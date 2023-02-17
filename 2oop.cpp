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

int main()
{


	Rectangle* b = new ColoredRectangle(20, 10,42);
	ColoredRectangle* a = new ColoredRectangle(1, 1, 1);
	delete b;
	delete a;
	_getch();
	return 0;
}