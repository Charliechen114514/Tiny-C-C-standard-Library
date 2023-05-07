#include"CCSTDC_String.h"


void testStringFuncs()
{
	// init Empty String

	CCSTDC_String* emptyString = initEmptyString();

	// init same alphas string

	CCSTDC_String* sameAlphaString = initSAMEAlphaString('c', 10);

	// update string

	CCSTDC_String* updateStringsample = updateString("hello world", sizeof("hello world"));

	// copy one!

	CCSTDC_String* copyOne = copyFromCCString(updateStringsample);

	// this std-String should be OK...
	// let's test if it is true!

	CCSTDC_INFO_Line("This is a sample of whether the string is correct!");

	if (isEmptyString(emptyString))
	{
		CCSTDC_INFO_Line("yes,the string:>");
		PRINTVARNAME(emptyString);
		CCSTDC_INFO_Line("is as the name goes!!!");
	}

	if (isGoodString(sameAlphaString)) {

		CCSTDC_INFO_Line("yes,the string:>");
		PRINTVARNAME(sameAlphaString);
		CCSTDC_INFO_Line("is as the name goes!!!");

	}

	// to test the fixStringFunc, let's do some modify diredctly

	CCSTDC_String* wrong = initSAMEAlphaString('a', 10);
	if (isGoodString(sameAlphaString)) {

		CCSTDC_INFO_Line("yes,the string:>");
		PRINTVARNAME(wrong);
		CCSTDC_INFO_Line("is as the name goes!!!");

	}

	CCSTDC_INFO_Line("howerver...");

	wrong->cur_Size = 114514;

	CCSTDC_String* copyOne2 = copyFromCCString(wrong);

	if (isGoodString(copyOne2)) {
		printf("\nGood");
	}
	if (!isGoodString(wrong)) {
		CCSTDC_INFO_Line("Something went wrong!");
	}

	fixBadString(wrong);

	if (isGoodString(sameAlphaString)) {
		CCSTDC_INFO_Line("After fixing!> \n");
		CCSTDC_INFO_Line("yes,the string:>");
		PRINTVARNAME(wrong);
		CCSTDC_INFO_Line("is as the name goes!!!");

	}

	puts("------------------------------------------------------------------------");

	// test stringInt and reverse
	CCSTDC_String* getRev = updateString("hello!", sizeof("hello"));

	reverseString(getRev);

	printString(getRev);

	CCSTDC_String* newI = to_StringInt(1000739821);

	printString(newI);
	
	// test Cat and insert
	printString(catCCString(updateString("aaa", 4), updateString("bbb", 4)));
	printString(insertCCString(updateString("aaa", 4), updateString("bbb", 4), 1));

	// test sort

	CCSTDC_String* sort = updateString("abcdefghigklmnopqrstuvwxyz", 27);

	stringSortArrange(sort, CCSTDC_ORDER_DOWN);

	printString(sort);


	//erase

	//emptyString sameAlphaString updateStringsample copyOne wrong getRev newI sort 
	eraseString(emptyString);
	eraseString(sameAlphaString);
	//eraseString(updateStringsample);
	eraseString(copyOne);
	eraseString(wrong);
	eraseString(getRev);
	eraseString(newI);
	eraseString(sort);
}


int main() {

	testStringFuncs();

}