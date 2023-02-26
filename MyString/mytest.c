#define _CRT_SECURE_NO_WARNINGS 1
#include"MyString.h"
int main()
{
	// to init a String
	MyString* pInit = initAString("this is a string");
	printString(pInit);
	SLASHN;
	// to Copy a String
	MyString* pCopy = copyAString(pInit);
	printString(pInit);
	SLASHN;

	// to append a str
	MyString* pCat = MyStrCat(pCopy, pInit);
	printString(pCat);
	SLASHN;

	//to copy a str just by charbuffer
	MyString* pC2 = initAString("111");
	printString(pC2);
	SLASHN;
	MyStrCpy(pC2, pInit);
	printString(pC2);
	SLASHN;
	// to reverse a string
	MyString* prev = initAString("hello,world");
	printString(prev);
	MyStrrev(prev);
	printString(prev);

	// to compare
	MyString* pI = initAString("AA");
	MyString* pII = initAString("AB");
	MyString* pIII = initAString("AC");
	int t1 = MyStrCmp(pI, pII);
	int t2 = MyStrCmp(pIII, pII);
	int t3 = MyStrCmp(pI, pI);
}
