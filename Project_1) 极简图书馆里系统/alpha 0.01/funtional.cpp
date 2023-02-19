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