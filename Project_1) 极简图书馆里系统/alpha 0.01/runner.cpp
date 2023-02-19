#define _CRT_SECURE_NO_WARNINGS 1
#include"book.h"
#include<conio.h>
int main()
{
	BookList* list1 = new BookList;
	char keypress = 1;
	while (keypress != 'q') {
		showMenu();
		cin >> keypress;
		switch (keypress)
		{
		case '1': list1->showList(); break;
		case '2':
		{
			string name, ISBN;
			size_t price;
			cout << "Offer the name ,ISBN ,and price";
			cin >> name >> ISBN >> price;
			Book* book = new Book(name, price, ISBN);
			list1->getBook(book);
			getchar();
			break;
		}
		case '3':
		{
			cout << "choose a type to find books:>";
			cout << "\n" << "A:name     B:ISBN \n";
			char choice = 0;
			while (choice != 'A' && choice != 'B') {
				getchar();
				scanf("%c", &choice);
				getchar();
				if (choice == 'a' || choice == 'b') {
					toupper(choice);
				}
			}
			if (choice == 'A')
			{
				string checkName = "Default";
				cout << "Input your name!\n";
				cin >> checkName;
				list1->deleteBook(list1->checkBookbyName(checkName));
			}
			else
			{
				string checkISBN = "Default";
				cout << "Input your ISBN!\n";
				cin >> checkISBN;
				list1->deleteBook(list1->checkBookbyISBN(checkISBN));
			}
			break;
		}
		case '4':
		{
			cout << "check by what ? lol:>\n";
			cout << "\n" << "A:name     B:ISBN \n";
			char choice = 0;
			while (choice != 'A' && choice != 'B') {
				getchar();
				scanf("%c", &choice);
				getchar();
				if (choice == 'a' || choice == 'b') {
					toupper(choice);
				}
			}
			if (choice == 'A')
			{
				string checkName = "Default";
				cout << "Input your name!\n";
				cin >> checkName;
				Book* b1 = list1->checkBookbyName(checkName);
				b1->printBookMsg();
			}
			else
			{
				string checkISBN = "Default";
				cout << "Input your ISBN!\n";
				cin >> checkISBN;
				Book* b1 = list1->checkBookbyISBN(checkISBN);
				b1->printBookMsg();
			}
			break;
		}
		default:
			cout << "emmmmmmmmmmmmm,check your input lol.\n";
			break;
		}
	}
}