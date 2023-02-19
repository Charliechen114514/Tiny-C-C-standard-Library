# C++ 极简图书查询系统源码

Project 1 : C++ 

version: demo

## 头文件

```C++
#pragma once
#include<iostream>
#include<string>
#include<list>

using namespace std;
class Book {
public:
	string getBookName();
	size_t getBookPrice();
	string getBookISBN();
	size_t getCurBookNum();
	Book(string name, int price, string ISBN);
	bool operator== (Book* b1);
	void setName(string name);
	void setPrice(int price);
	void setISBN(string ISBN);
	void setCurBookNum(int num);
	bool compareBookISBN(string ISBN);
	bool compareBookName(string name);
	bool compareBookType(Book* book);
	void printBookMsg();
private:
	string bookname;
	size_t price;
	string ISBN;
	size_t current_book_num;
};

class BookList {
public:
	BookList();
	size_t getCurBookTypeNum();
	size_t getcurBookTotalNum();
	void getBook(Book* book);
	void showList();
	void deleteBook(Book* book);
	Book* checkBookbyName(string name);
	Book* checkBookbyISBN(string ISBN);
private:
	list<Book> booklist;
	size_t cur_book_type_num;
	size_t cur_book_total_num;
};

void showMenu();
```

## 		实现文件

```C++
#define _CRT_SECURE_NO_WARNINGS 1

#include"book.h"


//getter

string Book::getBookISBN(){
	return this->ISBN;
}

string Book::getBookName() {
	return this->bookname;
}

size_t Book::getBookPrice() {
	return this->price;
}

size_t Book::getCurBookNum() {
	return this->current_book_num;
}

//setter

Book::Book(string name, int price, string ISBN)
{
	this->bookname = name;
	this->price = price;
	this->ISBN = ISBN;
	this->current_book_num = 1;
}

void Book::setCurBookNum(int num) {
	this->current_book_num = num;
}

void Book::setISBN(string ISBN) {
	this->ISBN = ISBN;
}

void Book::setName(string name) {
	this->bookname = name;
}

void Book::setPrice(int price) {
	this->price = price;
}

//func
bool Book::compareBookISBN(string ISBN) {
	if (this->ISBN != ISBN) {
		return false;
	}
	return true;
}

bool Book::compareBookName(string name) {
	if (this->bookname != name) {
		return false;
	}
	return true;
}

bool Book::operator==(Book* b1) {
	if (this->bookname == b1->bookname && this->ISBN == b1->ISBN) {
		return true;
	}
	return false;
}


bool Book::compareBookType(Book* book) {
	if (book->ISBN == this->ISBN) {
		return true;
	}
	return false;
}



void Book::printBookMsg() {
	cout << "书的名字：" << bookname << "\n";
	cout << "书的ISBN编码：" << ISBN << "\n";
	cout << "书的价格：" << price << "\n";
	cout << "书的现存个数：" << current_book_num << "\n";
}
// BookList



size_t BookList::getCurBookTypeNum() {
	return this->cur_book_type_num;
}

size_t BookList::getcurBookTotalNum() {
	return this->cur_book_total_num;
}

BookList::BookList() {
	this->booklist = list<Book>();
	this->cur_book_total_num = 0;
	this->cur_book_type_num = 0;
}

void BookList::getBook(Book* book) {
	this->cur_book_total_num++;
	for (list<Book>::iterator it = this->booklist.begin(); it != this->booklist.end(); it++) 
	{
		if ((*it).compareBookType(book)) 
		{
			(*it).setCurBookNum((*it).getCurBookNum() + 1);
			return;
		}
	}
	this->booklist.push_back(*book);
	this->cur_book_type_num++;
}

void BookList::showList() {
	if (this->booklist.empty()) {
		cout << "No book in the checking lib , just input your books here!\n";
		return;
	}
	for (list<Book>::iterator it = this->booklist.begin(); it != this->booklist.end(); it++)
	{
		(*it).printBookMsg();
		cout << endl;
	}
}

void BookList::deleteBook(Book* book) {
	if (book == nullptr) {
		return;
	}
	for (list<Book>::iterator it = this->booklist.begin(); it != this->booklist.end(); it++)
	{
		if ((*it).compareBookType(book))
		{
			this->booklist.erase(it);
			return;
		}
	}
	cout << "Book unfind! check tour input!\n";
}

Book* BookList::checkBookbyName(string name) {
	for (list<Book>::iterator it = this->booklist.begin(); it != this->booklist.end(); it++) {
		if ((*it).compareBookName(name)) {
			Book* targetBook = new Book(*it);
			return targetBook;
		}
	}
	cout << "Book unfind! check tour input!\n";
	return nullptr;
}

Book* BookList::checkBookbyISBN(string ISBN) {
	for (list<Book>::iterator it = this->booklist.begin(); it != this->booklist.end(); it++) {
		if ((*it).compareBookName(ISBN)) {
			Book* targetBook = new Book(*it);
			return targetBook;
		}
	}
	cout << "Book unfind! check tour input!\n";
	return nullptr;
}




void showMenu()
{
	cout << "--------------------------------------------------------------------\n";
	cout << "						Book Management system                       \n";
	cout << " 1 : Show all books                                                 \n";
	cout << " 2 : Add a book                                                     \n";
	cout << " 3 : delete a book                                                  \n";
	cout << " 4 : check and show book msg!                                       \n";
	cout << "--------------------------------------------------------------------\n";
}
```

## 运行文件

```C++
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
```

