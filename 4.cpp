#include <iostream>
using namespace std;
struct DoubleList //îïèñàíèå óçëà ñïèñêà
{
	int data; //èíôîðìàöèîííîå ïîëå
	DoubleList* next; //óêàçàòåëü íà ñëåäóþùèé ýëåìåíò
	DoubleList* prev; //óêàçàòåëü íà ïðåäûäóùèé ýëåìåíò
};
DoubleList* head; //óêàçàòåëü íà ïåðâûé ýëåìåíò ñïèñêà
//**********************ÄÎÁÀÂËÅÍÈÅ ÝËÅÌÅÍÒÀ**********************
void AddList(int value, int position)
{
	DoubleList* node = new DoubleList; //ñîçäàíèå íîâîãî ýëåìåíòà
	node->data = value; //ïðèñâîåíèå ýëåìåíòó çíà÷åíèÿ
	if (head == NULL) //åñëè ñïèñîê ïóñò
	{
		node->next = node; //óñòàíîâêà óêàçàòåëÿ next
		node->prev = node; //óñòàíîâêà óêàçàòåëÿ prev
		head = node; //îïðåäåëÿåòñÿ ãîëîâà ñïèñêà
	}
	else
	{
		DoubleList* p = head;
		for (int i = position; i > 1; i--) p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	cout << "\nÝëåìåíò äîáàâëåí...\n\n";
}
//***********************ÓÄÀËÅÍÈÅ ÝËÅÌÅÍÒÀ***********************
int DeleteList(int position)
{
	if (head == NULL) { cout << "\nÑïèñîê ïóñò\n\n"; return 0; }
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList* a = head;
		for (int i = position; i > 1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	cout << "\nÝëåìåíò óäàëåí...\n\n";
}
//*************************ÂÛÂÎÄ ÑÏÈÑÊÀ*************************
void PrintList()
{
	if (head == NULL) cout << "\nÑïèñîê ïóñò\n\n";
	else
	{
		DoubleList* a = head;
		cout << "\nÝëåìåíòû ñïèñêà: ";
		do
		{
			cout << a->data << " ";
			a = a->next;
		} while (a != head); cout << "\n\n";
	}
}
//************************ÃËÀÂÍÀß ÔÓÍÊÖÈß************************
int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	do
	{
		cout << "1. Äîáàâèòü ýëåìåíò" << endl;
		cout << "2. Óäàëèòü ýëåìåíò" << endl;
		cout << "3. Âûâåñòè ñïèñîê" << endl;
		cout << "0. Âûéòè" << endl;
		cout << "\nÍîìåð îïåðàöèè > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Çíà÷åíèå > "; cin >> value;
			cout << "Ïîçèöèÿ > "; cin >> position;
			AddList(value, position); break;
		case 2:
			cout << "Ïîçèöèÿ > "; cin >> position;
			DeleteList(position); break;
		case 3: PrintList(); break;
		}
	} while (x != 0);
}
