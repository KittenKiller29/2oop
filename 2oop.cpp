#include<iostream>
#include<conio.h>
class Rectangle {
public:
	Rectangle() {
		length = 10;
		width = 20;
		square = length * width;
		index = 0;
		name = "qwerty";
		std::cout << "Rectangle()" << std::endl;
	};
	Rectangle(int length, int width) {
		this->length = length;
		this->width = width;
		square = length * width;
		index = 0;
		name = "qwerty";
		std::cout << "Rectangle(int length,int width)" << std::endl;
	};
	Rectangle(const Rectangle& copyrectangle) {
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
	std::string name;
protected:
	int square;
	int length;
	int width;
private:
	int index;
};
int main()
{

	Rectangle* a = new Rectangle;
	Rectangle* b = new Rectangle(20, 10);
	Rectangle* c = new Rectangle(*a);
	delete a;
	delete b;
	delete c;

	_getch();
	return 0;
}