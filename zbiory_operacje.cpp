#include <iostream>

int pozycjaWyjsciowa = 15;

//Liczenie zaczyna sie od 0, czyli dodajac 1 element, dodajemy element "drugi" dla normalnych ludzi
void PrintCollection (unsigned short zbior)
{
	//Wypisiwanie elementow, najslabsze bity sa po prawej stronie
	for (int i = 15; i >= 0; i--)
	{
		if ((zbior & (1 << i)) != 0)
		{
			std::cout << "1 ";
		}
		else
		{
			std::cout << "0 ";
		}
	}
	std::cout << std::endl;
}

unsigned short Dopelnienie (unsigned short zbior)
{
	return ~zbior;
}

unsigned short Iloczyn (unsigned short zbior1, unsigned short zbior2)
{
	return (zbior1 & zbior2);
}

unsigned short Suma (unsigned short zbior1, unsigned short zbior2)
{
	return (zbior1 | zbior2);
}

unsigned short Roznica (unsigned short zbior1, unsigned short zbior2)
{
	return (zbior1 & ~zbior2);
}

unsigned short RoznicaSymetryczna (unsigned short zbior1, unsigned short zbior2)
{
	return ((zbior1 & ~zbior2) | (zbior2 & ~zbior1)); 
}

bool CzyZawiera (unsigned short zbior, short numerElementu)
{
	if (zbior & (1 << numerElementu) != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void DodajElement (unsigned short zbior, short numerElementu)
{
	zbior = (zbior | (1 << numerElementu)); 
	std::cout << zbior;
}

void UsunElement (unsigned short zbior, short numerElementu)
{
	zbior = (zbior & ~(1 << numerElementu)); 
	std::cout << zbior;
}

int MocZbioru (unsigned short zbior)
{
	int moc = 0;
	for (int i = 0; i < 16; i++)
	{
		if (zbior & (1 << i) != 0)
		{
			moc++;
		}
	}
	return moc;
}

int main()
{
	unsigned short a1 = 111;
	unsigned short a2 = 13;
	std::cout << "PrintCollecion: " << std::endl;
	PrintCollection(a1);
	std::cout << "PrintCollecion: " << std::endl;
	PrintCollection(a2);
	std::cout << "Dopelnienie: " << Dopelnienie(a1) << std::endl;
	std::cout << "Iloczyn: " << Iloczyn(a1, a2) << std::endl;
	std::cout << "Suma: " << Suma(a1, a2) << std::endl;
	std::cout << "Roznica: " << Roznica(a2, a1) << std::endl;
	std::cout << "RoznicaSymetryczna: " << RoznicaSymetryczna(a2, a1) << std::endl;
	std::cout << "CzyZawiera: " << CzyZawiera(a1, 2) << std::endl;
	std::cout << "DodajElement: " << std::endl;
	DodajElement(a1, 1);
	std::cout << "UsunElement: " << std::endl;
	UsunElement(a1, 1);
	std::cout << "MocZbioru: " << MocZbioru(a1) << std::endl;
	std::cout << "PrintCollecion: " << std::endl;
	PrintCollection(a1);
	std::cout << "PrintCollecion: " << std::endl;
	PrintCollection(a2);
	
	
	return 0;
}
