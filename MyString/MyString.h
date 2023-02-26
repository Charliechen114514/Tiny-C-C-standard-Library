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