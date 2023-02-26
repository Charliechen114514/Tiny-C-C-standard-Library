# MyCString

## 课堂摸鱼制作（

​		这次的小工程是为了还原一些常见的C 字符串功能，以及这是为了可以模拟 C++ string 左准备！

## MyCString

```c
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//General Version
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


//Error Defined here
#define SHOW_NULL_INPUT_WARNING printf("this string seems to be NULL.")
#define SHOW_ERROR_MALLOCING_SPACE printf("can not find a space to store the data");
#define SHOW_INVALID_INPUT printf("cannot accept an invalid input!");

//Quick set Str's char number
#define Mystrlen(buffer) strlen(buffer)+1;

//Print in a line by using this abstractions
#define SLASHN printf("\n")

//ErrorCode_String
typedef enum _MyStringErrorCode_ {
	MyString_NULL_INPUT = 1,
	MyString_ERROR_IN_MALLOCING_SPACE = 2,
	MyString_INVALID_INPUT = 3,
	MySting_NORMAL = 0
}MyStringErrorCode;


// Main Body and basic structure in str
typedef struct MyString {
	char* charBuffer;
	unsigned int current_size;
}MyString;


typedef struct _ComparatorResult_ {
	void* equal;
	void* bigger;
	void* smaller;
}ComparatorResult;

//----------------------------------------------- init a comparator ----------------
ComparatorResult* initComparator(void* equal, void* bigger, void* smaller);

//----------------------------------------My_String------------------------------------

// ---------------------------- Init A string -----------------------------------------
// 1. initAString
// by using this, you can init a string by input a ordinary char array
// 
// input: char array
// output: MyString* (a pointer to the myString)
// ------------------------------------------------------------------------------------
// 2.copyAString
// by using this , you can copy a MyString as C++ copy init methods!
// 
// input: A pointer to MyString
// output: A pointer to MyString
// ------------------------------------------------------------------------------------
// 
MyString* initAString(const char* buffer);

MyString* copyAString(const MyString* pCopy);

void printString(MyString* mine);

void setElemString(MyString* be_set_String, char val, int place);

void MyStrrev(MyString* reverse);

// ----------------- Append and Copy -----------------------------
// 1. MyStrCat
// by using this , you can append a str at the end of a string
// 
// input : two strings :str1 (as be apeended) && appenderStr
// output: a str that finishing his work
// 
// ---------------------------------------------------------------
// 2. MyStrCpy
// by using this , you can get a copyed one and it will erase the data of the container
// 
// input :two strings :str1 (as be apeended) && copierStr
// output:a str that finishing his work
// 
// ----------------------------------------------------------------

MyString* MyStrCat(MyString* str1, MyString* appenderStr);

MyString* MyStrCpy(MyString* container, MyString* beCopied);

// ----------------------------------Compare-----------------------------------
// 1. MyStrCmp
// by using this , you can compare string as strcmp does
// 
// input : two strings taht you want to compare
// output: get result
// if str1's ASCII < str2's ASCII then returns 1;
// else if str1's ASCII > str2's ASCII then returns -1;
// else return 0 as equal
// ----------------------------------------------------------------------------
// MyStr_Self_Def_Cmp
// by using this,you can compare string as strcmp does,and return the value you want to return
// 
// input : two strings taht you want to compare , as well as the comparator
// output: the things that fits the situation you wants to return
// ----------------------------------------------------------------------------


int MyStrCmp(const MyString* str1, const MyString* str2);

void* MyStr_Self_Def_Cmp(const MyString* str1, const MyString* str2, ComparatorResult* res);
```

## MyCstring.cpp

```c
#define _CRT_SECURE_NO_WARNINGS 1
//General Version
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


//Error Defined here
#define SHOW_NULL_INPUT_WARNING printf("this string seems to be NULL.")
#define SHOW_ERROR_MALLOCING_SPACE printf("can not find a space to store the data");
#define SHOW_INVALID_INPUT printf("cannot accept an invalid input!");

//Quick set Str's char number
#define Mystrlen(buffer) strlen(buffer)+1;

//Print in a line by using this abstractions
#define SLASHN printf("\n")

//ErrorCode_String
typedef enum _MyStringErrorCode_ {
	MyString_NULL_INPUT = 1,
	MyString_ERROR_IN_MALLOCING_SPACE = 2,
	MyString_INVALID_INPUT = 3,
	MySting_NORMAL = 0
}MyStringErrorCode;


// Main Body and basic structure in str
typedef struct MyString {
	char* charBuffer;
	unsigned int current_size;
}MyString;


typedef struct _ComparatorResult_ {
	void* equal;
	void* bigger;
	void* smaller;
}ComparatorResult;

//----------------------------------------------- init a comparator ----------------
ComparatorResult* initComparator(void* equal, void* bigger, void* smaller)
{
	ComparatorResult* proUsableSpace = (ComparatorResult*)malloc(sizeof(ComparatorResult));
	if (proUsableSpace == NULL) {
		SHOW_ERROR_MALLOCING_SPACE;
		exit(MyString_ERROR_IN_MALLOCING_SPACE);
	}
	proUsableSpace->bigger = bigger;
	proUsableSpace->smaller = smaller;
	proUsableSpace->equal = equal;
	return proUsableSpace;
}

//----------------------------------------My_String------------------------------------

// ---------------------------- Init A string -----------------------------------------
// 1. initAString
// by using this, you can init a string by input a ordinary char array
// 
// input: char array
// output: MyString* (a pointer to the myString)
// ------------------------------------------------------------------------------------
// 2.copyAString
// by using this , you can copy a MyString as C++ copy init methods!
// 
// input: A pointer to MyString
// output: A pointer to MyString
// ------------------------------------------------------------------------------------
// 
MyString* initAString(const char* buffer) {
	MyString* pstring = (MyString*)malloc(sizeof(MyString));
	if (buffer == NULL) {
		SHOW_NULL_INPUT_WARNING;
		pstring->charBuffer = NULL;
		pstring->current_size = 0;
		return pstring;
	}
	char* usableSpace = (char*)malloc(strlen(buffer)+1);
	if (usableSpace == NULL) {
		SHOW_ERROR_MALLOCING_SPACE;
		exit(MyString_ERROR_IN_MALLOCING_SPACE);
	}
	memcpy(usableSpace, buffer, strlen(buffer) + 1);
	pstring->charBuffer = usableSpace;
	pstring->current_size = Mystrlen(buffer);//
	return pstring;
}

MyString* copyAString(const MyString* pCopy) {
	if (pCopy == NULL) {
		SHOW_NULL_INPUT_WARNING;
		exit(MyString_NULL_INPUT);
	}
	MyString* pstring = (MyString*)malloc(sizeof(MyString));
	if (pCopy->charBuffer == NULL) {
		SHOW_NULL_INPUT_WARNING;
		pstring->charBuffer = NULL;
		pstring->current_size = 0;
		return pstring;
	}
	char* proUsableSpace = (char*)malloc(strlen(pCopy->charBuffer) + 1);
	if (proUsableSpace == NULL) {
		SHOW_ERROR_MALLOCING_SPACE;
		exit(MyString_ERROR_IN_MALLOCING_SPACE);
	}
	memcpy(proUsableSpace, pCopy->charBuffer, strlen(pCopy->charBuffer)+1);
	pstring->charBuffer = proUsableSpace;
	pstring->current_size = pCopy->current_size;
	return pstring;
}


// ---------------------------- Do something -----------------------------------------
// 1. printString
// by using this, you can print a string
// 
// input: MyString* that aims to be printed in the control tab
// output: normal statues
// ------------------------------------------------------------------------------------
// 2.setElemString
// by using this , you can set a char into a targeted place
// 
// input: A pointer to MyString, your val that want to be inputed, and the place you specify
// output: normal statues
// ------------------------------------------------------------------------------------
// 3. MyStrrev
// by using this, it will help reverse a char array
// 
// input :A pointer to MyString
// output: normal statues
// ------------------------------------------------------------------------------------

void printString(MyString* mine) {
	if (mine == NULL) {
		SHOW_NULL_INPUT_WARNING;
		exit(MyString_NULL_INPUT);
	}
	for (int i = 0; i < mine->current_size; i++) {
		printf("%c", mine->charBuffer[i]);
	}
	return MySting_NORMAL;
}

void setElemString(MyString* be_set_String, char val,int place)
{
	if (be_set_String == NULL) {
		SHOW_NULL_INPUT_WARNING;
		exit(MyString_NULL_INPUT);
	}
	if (place >= be_set_String->current_size-1) {
		SHOW_INVALID_INPUT;
		exit(MyString_INVALID_INPUT);
	}
	be_set_String->charBuffer[place] = val;
	return MySting_NORMAL;
}

void MyStrrev(MyString* reverse) {
	if (reverse == NULL) {
		SHOW_NULL_INPUT_WARNING;
		exit(MyString_NULL_INPUT);
	}
	for (int i = 0; i < reverse->current_size / 2; i++) {
		char temp = 0;
		temp = reverse->charBuffer[i];
		reverse->charBuffer[i] = reverse->charBuffer[reverse->current_size - i - 2];
		reverse->charBuffer[reverse->current_size - i - 2] = temp;
	}
}

// ----------------- Append and Copy -----------------------------
// 1. MyStrCat
// by using this , you can append a str at the end of a string
// 
// input : two strings :str1 (as be apeended) && appenderStr
// output: a str that finishing his work
// 
// ---------------------------------------------------------------
// 2. MyStrCpy
// by using this , you can get a copyed one and it will erase the data of the container
// 
// input :two strings :str1 (as be apeended) && copierStr
// output:a str that finishing his work
// 
// ----------------------------------------------------------------


MyString* MyStrCat(MyString* str1, MyString* appenderStr) {
	if (appenderStr == NULL) {
		SHOW_NULL_INPUT_WARNING;
		printf("No need to append str!");
	}
	if (str1 == NULL) {
		memcpy(str1, appenderStr, strlen(appenderStr) + 1);
		str1->current_size = appenderStr->current_size;
		return str1;
	}
	if (str1 == appenderStr) {

		char* forCopy = (char*)malloc(2 * sizeof(str1->charBuffer));
		if (forCopy == NULL) {
			SHOW_ERROR_MALLOCING_SPACE;
			exit(MyString_ERROR_IN_MALLOCING_SPACE);
		}

		memcpy(forCopy, str1->charBuffer, sizeof(str1->charBuffer));

		for (int i = 0; i < appenderStr->current_size; i++) {
			str1->charBuffer[i + str1->current_size - 1] = appenderStr->charBuffer[i];
		}
		str1->current_size = str1->current_size + appenderStr->current_size - 1;
		return str1;
	}

	char* proUsableSpace = (char*)realloc(
		str1->charBuffer, 
		sizeof(str1->charBuffer)+sizeof(appenderStr->charBuffer)-1
	);
	
	for (int i = 0; i < appenderStr->current_size; i++) {
		str1->charBuffer[i + str1->current_size-1] = appenderStr->charBuffer[i];
	}
	str1->current_size = str1->current_size + appenderStr->current_size - 1;
	return str1;
}

MyString* MyStrCpy(MyString* container, MyString* beCopied) {
	if (beCopied == NULL) {
		SHOW_NULL_INPUT_WARNING;
		printf("No need to append");
		return container;
	}
	if (container == NULL) {
		SHOW_NULL_INPUT_WARNING;
		printf("Cannot input data into a NULL space");
		return container;
	}
	char* proUsableSpace = (char*)realloc(container->charBuffer,strlen(beCopied->charBuffer)+1);
	if (proUsableSpace == NULL) {
		SHOW_ERROR_MALLOCING_SPACE;
		exit(MyString_ERROR_IN_MALLOCING_SPACE);
	}
	memcpy(container->charBuffer, beCopied->charBuffer, strlen(beCopied->charBuffer) + 1);
	container->current_size = beCopied->current_size;
	return container;
}

// ----------------------------------Compare-----------------------------------
// 1. MyStrCmp
// by using this , you can compare string as strcmp does
// 
// input : two strings taht you want to compare
// output: get result
// if str1's ASCII < str2's ASCII then returns 1;
// else if str1's ASCII > str2's ASCII then returns -1;
// else return 0 as equal
// ----------------------------------------------------------------------------
// MyStr_Self_Def_Cmp
// by using this,you can compare string as strcmp does,and return the value you want to return
// 
// input : two strings taht you want to compare , as well as the comparator
// output: the things that fits the situation you wants to return
// ----------------------------------------------------------------------------


int MyStrCmp(const MyString* str1,const MyString* str2) {
	if (str1 == NULL || str2 == NULL) {
		SHOW_NULL_INPUT_WARNING;
		return;
	}
	char* CmpStr1 = str1->charBuffer;
	char* CmpStr2 = str2->charBuffer;
	while (*CmpStr1 != '\0' && *CmpStr2 != '\0') {
		if (*CmpStr1 != *CmpStr2) {
			return (
				    ((*CmpStr1 - *CmpStr2) < 0) - 
					((*CmpStr2 - *CmpStr1) < 0)
				);
		}
		CmpStr1++;
		CmpStr2++;
	}
	return 0;
}

void* MyStr_Self_Def_Cmp(const MyString* str1, const MyString* str2, ComparatorResult* res) 
{
	if (str1 == NULL || str2 == NULL) {
		SHOW_NULL_INPUT_WARNING;
		return;
	}
	char* CmpStr1 = str1->charBuffer;
	char* CmpStr2 = str2->charBuffer;
	while (*CmpStr1 != '\0' && *CmpStr2 != '\0') {
		if (*CmpStr1 >= *CmpStr2) {
			return res->bigger;
		}
		else if (*CmpStr1 == *CmpStr2) {
			return res->equal;
		}
		else {
			return res->smaller;
		}
		CmpStr1++;
		CmpStr2++;
	}
	return 0;
}
```

## MyTest.c

```c
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
```

