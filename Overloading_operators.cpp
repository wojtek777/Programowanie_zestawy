#include <iostream>

class ComplexNumbers
{
public:
	double x;
	double y;
	
public:
	ComplexNumbers (double re, double im) : x(re), y(im)
	{

	}
	
	
	friend std::ostream& operator<<(std::ostream&, const ComplexNumbers&);
	
	friend std::istream& operator>>(std::istream&, const ComplexNumbers&);
	
void operator = (const ComplexNumbers& t1)
{
	//~ pierwszym argumentem jest auto-argument, bedacy obiektem na ktorym wywolano metode
	x = t1.x;
	y = t1.y;
}

void operator ++ ()
{
	x++;
}

void operator -- ()
{
	x--;
}

void operator ++ (int)
{
	y++;
}

void operator -- (int)
{
	y--;
}
	
};



ComplexNumbers operator+ (ComplexNumbers t1, ComplexNumbers t2)
{
	ComplexNumbers wynik(0, 0);
	wynik.x = t1.x + t2.x;
	wynik.y = t1.y + t2.y;
	return wynik;
}

ComplexNumbers operator- (ComplexNumbers t1, ComplexNumbers t2)
{
	ComplexNumbers wynik(0, 0);
	wynik.x = t1.x - t2.x;
	wynik.y = t1.y - t2.y;
	return wynik;
}

ComplexNumbers operator* (ComplexNumbers t1, ComplexNumbers t2)
{
	ComplexNumbers wynik(0, 0);
	wynik.x = t1.x * t2.x - t1.y * t2.y;
	wynik.y = t1.x * t2.y + t2.x * t1.y;
	return wynik;
}

ComplexNumbers operator/ (ComplexNumbers t1, ComplexNumbers t2)
{
	ComplexNumbers wynik(0, 0);
	wynik.x = (t1.x * t2.x + t1.y * t2.y) / (t2.x * t2.x + t2.y * t2.y);
	wynik.y = (t1.y * t2.x - t1.x * t2.y) / (t2.x * t2.x + t2.y * t2.y);
	return wynik;
}

bool operator == (ComplexNumbers t1, ComplexNumbers t2)
{
	if (t1.x == t2.x && t1.y == t2.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool operator != (ComplexNumbers t1, ComplexNumbers t2)
{
	if (t1.x == t2.x && t1.y == t2.y)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void operator += (ComplexNumbers& t1, ComplexNumbers t2)
{
	//~ dodawanie dwoch zespolonych
	t1.x = t1.x + t2.x;
	t1.y = t1.y + t2.y;
}

void operator += (ComplexNumbers& t1, int liczba)
{
	//~ dodawanie zespolonej do zwyklej liczby
	t1.x = t1.x + liczba;
}

void operator -= (ComplexNumbers& t1, ComplexNumbers t2)
{
	t1.x = t1.x - t2.x;
	t1.y = t1.y - t2.y;
}

void operator -= (ComplexNumbers& t1, int liczba)
{
	t1.x = t1.x - liczba;
}

void operator *= (ComplexNumbers& t1, ComplexNumbers t2)
{
	//~ mnozenie dwoch zespolonych
	t1.x = t1.x * t2.x - t1.y * t2.y;
	t1.y = t1.x * t2.y + t2.x * t1.y;
}

void operator *= (ComplexNumbers& t1, int liczba)
{
	//~ mnozenie zespolonej i zwyklej liczby
	t1.x = t1.x * liczba;
	t1.y = t1.y * liczba;
}

void operator /= (ComplexNumbers& t1, ComplexNumbers t2)
{
	//~ dzielenie zespolonej przez zespolona
	t1.x = (t1.x * t2.x + t1.y * t2.y) / (t2.x * t2.x + t2.y * t2.y);
	t1.y = (t1.y * t2.x - t1.x * t2.y) / (t2.x * t2.x + t2.y * t2.y);
}

void operator /= (ComplexNumbers& t1, int liczba)
{
	//~ dzielenie zespolonej przez zwykla liczbe
	t1.x = t1.x / liczba;
	t1.y = t1.y / liczba;
}

std::ostream& operator<<(std::ostream& strumien, ComplexNumbers& num)
{
	strumien << num.x << " + " << num.y << "i";
	return strumien;
}

std::istream& operator>>(std::istream& strum, ComplexNumbers& numb)
{
	strum >> numb.x >> numb.y;
	return strum;
}

void operator - (ComplexNumbers& t1)
{
	t1.x = -t1.x;
	t1.y = -t1.y;
}

void operator ! (ComplexNumbers& t1)
{
	t1.y = -t1.y;
}

int main()
{
	ComplexNumbers z(1, 2);
	ComplexNumbers zz(1, 2);
	ComplexNumbers zWyn(0, 0);
	std::cout << z << std::endl;
	std::cin >> z;
	std::cout << z << std::endl;
	zWyn = z * zz;
	ComplexNumbers deszcz(1, 3);
	deszcz *= 3;
	std::cout << deszcz << std::endl;
	//std::cout << zWyn << std::endl;
	deszcz *= deszcz;
	ComplexNumbers znaki(4, 5);
	!znaki;
	std::cout << znaki << std::endl;
	-znaki;
	std::cout << znaki << std::endl;
	znaki++;
	std::cout << znaki << std::endl;
	++znaki;
	std::cout << znaki << std::endl;
	
	
	return 0;
}
