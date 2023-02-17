#include<iostream>
#include<conio.h>
class Rectangle {
public:
	Rectangle() {//конструктор по умолчанию
		length = 10;
		width = 20;
		square = length * width;
		index = 0;
		name = "qwerty";
		std::cout << "Rectangle()" << std::endl;
	};
	Rectangle(int length, int width) {//конструктор c параметрами
		this->length = length;
		this->width = width;
		square = length * width;
		index = 0;
		name = "qwerty";
		std::cout << "Rectangle(int length,int width)" << std::endl;
	};
	Rectangle(const Rectangle& copyrectangle) {//конструктор копирования
		length = copyrectangle.length;
		width = copyrectangle.width;
		square = length * width;
		index = 0;
		name = "qwerty";
		std::cout << "Rectangle(const Rectangle& copyrectangle)" << std::endl;
	};
	~Rectangle() {
		std::cout << length << std::endl << width << std::endl << square << std::endl;
		std::cout << index << std::endl << name << std::endl;
		std::cout << "~Rectangle()" << std::endl;
	};
	void lwChange(int dlength, int dwidth) {//метод изменения значений свойств
		length += dlength;
		width += dwidth;
		square = length * width;
	}
	std::string name;
	void lwSwap();//метод замены значения свойств друг на друга
protected:
	int square;
	int length;
	int width;
private:
	int index;
};
void Rectangle::lwSwap() {//реализация метода вне описания класса
	int temp = length;
	length = width;
	width = temp;
}
int main()
{


	Rectangle* b = new Rectangle(20, 10);
	b->lwChange(5, 10);
	b->lwSwap();
	delete b;
	_getch();
	return 0;
}