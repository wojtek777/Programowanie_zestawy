//Wojciech Zola
#include <iostream>

int dlugosc = 0;

struct LIST
{
	char nazwa;
	LIST* next;
};

void add (LIST* lista, char e)
{
	LIST* walking = lista->next;
	bool broke = 0;
	std::cout << "wywolano funkcje add" << std::endl;
	while (broke == 0)
	{
		if (walking == NULL)
		{
			broke = 1;
			LIST* added = new LIST;
			lista->next = added;
			added->nazwa = e;
			added->next = NULL;
			dlugosc++;
		}
		else if (walking->next == NULL)
		{
			broke = 1;
			LIST* added = new LIST;
			walking->next = added;
			added->nazwa = e;
			added->next = NULL;
			dlugosc++;
		}
		else
		{
			walking = walking->next;
		}
	}
}
bool contain (LIST* lista, char n)
{
	bool does = 0;
	LIST* walking;
	std::cout << "wywolano funkcje contain" << std::endl;
	for (walking = lista->next; walking != NULL; walking = walking->next)
	{
		if (walking->nazwa == n)
		{
			does = 1;
		}
	}
	if (does == 1)
	{
		std::cout << "zawiera element: " << n << std::endl;
		return 1;
	}
	else
	{
		std::cout << "nie zawiera elementu: " << n << std::endl;
		return 0;
	}
	walking = NULL;
}
	
void remove (LIST* lista, char n)
{
	LIST* walking = lista->next;
	LIST* prevList = NULL;
	LIST* nextList = NULL;
	bool broke = 0;
	std::cout << "wywolano funkcje remove" << std::endl;
	while (broke == 0)
	{
		if (walking == NULL)
		{
			broke = 1;
		}
		else if (walking->nazwa == n)
		{
			nextList = walking->next;
			delete(walking);
			walking = prevList;
			walking->next = nextList;
			dlugosc--;
			broke = 1;
		}
		else if (walking->next == NULL)
		{
			broke = 1;
		}
		else
		{
			prevList = walking;
			walking = walking->next;
		}
	}
}

void removeAll (LIST* lista, char n)
{
	LIST* walking = lista->next;
	LIST* prevList = NULL;
	LIST* nextList = NULL;
	bool broke = 0;
	std::cout << "wywolano funkcje removeAll" << std::endl;
	while (broke == 0)
	{
		if (walking == NULL)
		{
			broke = 1;
		}
		else if (walking->nazwa == n)
		{
			nextList = walking->next;
			delete(walking);
			walking = prevList;
			walking->next = nextList;
			dlugosc--;
		}
		else if (walking->next == NULL)
		{
			broke = 1;
		}
		else
		{
			prevList = walking;
			walking = walking->next;
		}
	}
}
	
void isEmpty(LIST* lista)
{
	if (lista->next == NULL)
	{
		std::cout << "Lista pusta" << std::endl;
	}
	else
	{
		std::cout << "Lista nie jest pusta" << std::endl;
	}
}

void clear(LIST* lista)
{
	LIST* walking = lista->next;
	LIST* tempList = NULL;
	bool broken = 0;
	while (broken == 0)
	{
		if (walking == NULL)
		{
			broken = 1;
		}
		else if (walking->next == NULL)
		{
			delete (walking);
			broken = 1;
		}
		else
		{
			tempList = walking->next;
			delete(walking);
			walking = tempList;
		}
	}
	dlugosc = 0;
}

void indexOf(LIST* lista, char n)
{
	std::cout << "wywolano funkcje indexOf" << std::endl;
	int index = 0;
	if (lista->nazwa == n)
	{
		std::cout << "index elementu n to: " << index << std::endl;
	}
	LIST* walking = lista->next;
	index++;
	bool broken = 0;
	while (broken == 0)
	{
		if (walking == NULL)
		{
			broken = 1;
		}
		else if (walking->nazwa == n)
		{
			std::cout << "index elementu n to: " << index << std::endl;
			broken = 1;
		}
		else if (walking->next == NULL)
		{
			broken = 1;
		}
		else
		{
			walking = walking->next;
			index++;
		}
	}
}

int length(LIST* lista)
{
	return dlugosc;
}

void add (LIST* lista, char n, int i)
{
	LIST* walking = lista->next;
	bool broken = 0;
	if (i >= dlugosc)
	{
		add(lista, n);
	}
	else
	{
		int kroki = 2;
		while (kroki < i)
		{
			walking = walking->next;
		}
		//jestem na i - 1 pozycji, na nastepnej dokladam obiekt
		LIST* prevList = walking;
		walking = walking->next;
		LIST* nextList = walking;
		walking = prevList;
		LIST* added = new LIST;
		walking->next = added;
		added->nazwa = n;
		added->next = nextList;
		dlugosc++;
	}
}

void removeRep(LIST* lista)
{
	LIST* walking = lista;
	bool broken = 0;
	while (broken == 0)
	{
		if (walking->next == NULL)
		{
			broken = 1;
		}
		else if (contain(walking->next, walking->nazwa))
		{
			removeAll(walking->next, walking->nazwa);
		}
		else
		{
			walking = walking->next;
		}
		
	}
}

LIST* reverse(LIST* lista)
{
	LIST* firstElem = lista;
	LIST* walking = lista;
	LIST* nextList;
	LIST* prevList;
	bool broken = 0;
	while (broken == 0)
	{
		if (walking->next == NULL)
		{
			//jestesmy w ostatnim stanie, jego wskaznik jest ustawiony na stan "poprzedni", wiec funkcja konczy dzialanie 
			broken = 1;
			return walking;	//zwracamy wskaznik na nowego roota
		}
		else if (walking != firstElem)	
		{
			//wchodzimy do stanu B, ktory od razu zapisujemy jako prev
			//nastepnie od razu przechodzimy do C, gdzie jako nextList zapisujemy D, po to zeby zwolnic wskaznik z C
			//i przekierowac go na B, nastepny obieg rozpoczniemy w C, itd. dopoki nie znajdziemy sie w stanie koncowym
			prevList = walking;
			walking = walking->next;
			nextList = walking->next;
			walking->next = prevList;
			
		}
		else if (walking == firstElem)	
		{
			//jestesmy w stanie A, poczatkowym, zapisujemy przyszly B, a potem ustawiamy jego wskaznik na NULL
			//nastepnie zapisujemy stan A jako prev, i udajemy sie do B, ktory jest zapisany w nextList
			//od razu nadpisujemy jako nextList stan C, zeby go nie zgubic, a wskaznik z B kierujemy na A,
			//zapisany w prev, poczatek listy sie "odwraca"
			nextList = walking->next;
			walking->next = NULL;
			prevList = walking; 
			walking = nextList;
			nextList = walking->next;
			walking->next = prevList;
		}
	}
	return walking;
}

char* toArray(LIST* lista)
{
	int ii = length(lista);
	int licznik = 0;
	char* elementy = new char[ii];
	LIST* walking = lista;
	while (walking->next != NULL)
	{
		elementy[licznik] = walking->nazwa;
		licznik++;
	}
	elementy[licznik] = walking->nazwa;
	return elementy;
}

int main()
{
	LIST* root = new LIST;
	root->nazwa = 'R';
	root->next = NULL;
	
	add(root, 't');
	add(root, 'g');
	contain(root, 't');
	contain(root, 'g');
	contain(root, 'x');
	remove(root, 'g');
	contain(root, 'g');
	
	
	
	return 0;
}
