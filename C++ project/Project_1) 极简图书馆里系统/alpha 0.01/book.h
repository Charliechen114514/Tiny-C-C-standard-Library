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