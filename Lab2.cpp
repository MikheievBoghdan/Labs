#include <iostream>

using namespace std;

class Triangle {
private:
	int a, b, c;
public:
	Triangle() {
		this->a = 0;
		this->b = 0;
		this->c = 0;
	}

	Triangle(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void setA(int a) { this->a = a; }
	int getA() { return this->a; }

	void setB(int b) { this->b = b; }
	int getB() { return b; }

	void setC(int c) { this->c = c; }
	int getC() { return c; }

	int calcVolume() {
		float p = (this->a + this->b + this->c) / 2;
		return sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));
	}

	void print_sqr() {
		cout << " A: " << this->a
			<< " B: " << this->b
			<< " C: " << this->c
			<< " Volume: " << this->calcVolume() << endl;
	}

	friend Triangle frd(Triangle a, Triangle b);

};

Triangle frd(Triangle a, Triangle b) {
	Triangle c = Triangle(a.a + b.a, a.b + b.b, a.c + b.c);

	return c;
}

Triangle genTriangle() {
	int a, b, c;
	cout << " Write a: "; cin >> a;
	cout << " Write b: "; cin >> b;
	cout << " Write c: "; cin >> c;
	Triangle res = Triangle(a, b, c);

	cout << " Some info about triangle: " << endl;
	res.print_sqr();

	return res;
}

int main() {
	Triangle Triangle1 = genTriangle();
	Triangle Triangle2 = genTriangle();
	Triangle TriangleRes = frd(Triangle1, Triangle2);
	cout << endl << " Info about final triangle: " << endl;
	TriangleRes.print_sqr();
}
