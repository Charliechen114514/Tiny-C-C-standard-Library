#pragma once
#include"CCSTDC_Utils.h"

#define CCSTRING_READYSEARCH NULL

typedef struct _CCSTDC_String_ {

	char* dataString;

	size cur_Size;

	char* stringFront;

	char* stringRear;

	char* searchPointer; // no related API ,waiting to be added...
}CCSTDC_String;

#define QuickCheckOfString(CCString) if(!isGoodString(CCString)){CCSTDC_INFO_Line("something went wrong! the string is going to be fixed!");fixBadString(CCString);}

// functional 1 : initializations

CCSTDC_String* initEmptyString();

CCSTDC_String* initSAMEAlphaString(const char val, int num);

CCSTDC_String* updateString(const char* ordCString, int ordCStringSize);

CCSTDC_String* copyFromCCString(CCSTDC_String* copied);

// functional 2 : isValid or isNull

CCSTDC_BOOL isVaildString(CCSTDC_String* pointerToString);

CCSTDC_BOOL isEmptyString(CCSTDC_String* pointerToString);

CCSTDC_BOOL isGoodString(CCSTDC_String* pointerToWaited);

void fixBadString(CCSTDC_String* pointerToString);

// applications
void reverseString(CCSTDC_String* pointerToString);

void printString(CCSTDC_String* pointerToString);

CCSTDC_String* to_StringInt(int numToString);

CCSTDC_String* catCCString(CCSTDC_String* beCatted, CCSTDC_String* catter);

CCSTDC_String* insertCCString(CCSTDC_String* beCatted, CCSTDC_String* catter, int place);

int* fastCountInASCII_String(CCSTDC_String* pointerToCounted);

void stringSortArrange(CCSTDC_String* string, CCSTDC_sortCode code);

void eraseString(CCSTDC_String* pStr);
#ifdef CCSTDC_VECTOR_H_
CCSTDC_Vector* countElemInString(CCSTDC_String* pointerToCounted);
#endif