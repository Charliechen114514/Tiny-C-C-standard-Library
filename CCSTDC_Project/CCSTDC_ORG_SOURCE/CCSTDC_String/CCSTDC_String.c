#include"CCSTDC_String.h"

// ----------------------------- string -----------------------------------

// ----------------------------- init -------------------------------------

CCSTDC_String* initEmptyString()
{
	CCSTDC_String* newString = (CCSTDC_String*)malloc(sizeof(CCSTDC_String));

	if (newString == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	char* dataNote = (char*)malloc(sizeof(char));

	if (dataNote == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	dataNote[0] = '\0';

	newString->dataString = dataNote;

	newString->stringFront = dataNote;

	newString->stringRear = dataNote;

	newString->searchPointer = CCSTRING_READYSEARCH;

	newString->cur_Size = 1;

	return newString;
}

CCSTDC_String* initSAMEAlphaString(const char val, int num)
{

	if (num < 0) {

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_INVALID_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_INVALID_INPUT_str, CCSTDC_INVALID_INPUT);

#endif
	}

	CCSTDC_String* newString = (CCSTDC_String*)malloc(sizeof(CCSTDC_String));

	if (newString == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	char* dataNote = (char*)malloc(sizeof(char) * num + 1);

	if (dataNote == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	for (int i = 0; i < num; i++)
	{
		dataNote[i] = val;
	}

	dataNote[num] = '\0';

	newString->cur_Size = num + 1;
	newString->dataString = dataNote;
	newString->stringFront = dataNote;
	newString->stringRear = &dataNote[num];
	newString->searchPointer = CCSTRING_READYSEARCH;

	return newString;
}

CCSTDC_String* updateString(const char* ordCString, int ordCStringSize)
{

	if (ordCString == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW

	}

	if (ordCStringSize < 0)
	{

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_INVALID_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_INVALID_INPUT_str, CCSTDC_INVALID_INPUT);

#endif // CCSTDC_ERROR_THROW

	}

	CCSTDC_String* newString = (CCSTDC_String*)malloc(sizeof(CCSTDC_String));

	if (newString == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	char* dataNote = (char*)malloc(sizeof(char) * ordCStringSize + 1);

	if (dataNote == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}


	memcpy(dataNote, ordCString, ordCStringSize + 1);

	dataNote[ordCStringSize] = '\0';

	newString->dataString = dataNote;

	newString->cur_Size = ordCStringSize;

	newString->stringFront = dataNote;

	newString->stringRear = &dataNote[newString->cur_Size];

	newString->searchPointer = CCSTRING_READYSEARCH;

	return newString;

}

CCSTDC_String* copyFromCCString(CCSTDC_String* copied)
{

	if (copied == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW
	}

	QuickCheckOfString(copied);

	CCSTDC_String* newString = (CCSTDC_String*)malloc(sizeof(CCSTDC_String));

	if (newString == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	char* dataNote = (char*)malloc(sizeof(char) * copied->cur_Size);

	if (dataNote == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}


	memcpy(dataNote, copied->dataString, copied->cur_Size);

	newString->dataString = dataNote;

	newString->cur_Size = copied->cur_Size;

	newString->stringFront = dataNote;

	newString->stringRear = &dataNote[newString->cur_Size];

	newString->searchPointer = CCSTRING_READYSEARCH;

	return newString;

}

CCSTDC_BOOL isExistedSingleCharInString(CCSTDC_String* string, char ch)
{
	if (string == NULL && isEmptyString(string)) {

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW

	}


	for (const char* ptrCh = string->stringFront; ptrCh != string->stringRear; ptrCh++) {

		if (*ptrCh == ch) {
			return CCSTDC_TRUE;
		}

	}

	return CCSTDC_FALSE;

}

// functions return the first place where we found the elem.
int searchElementarySingleCharInString(CCSTDC_String* string, char ch)
{

	if (string == NULL && isEmptyString(string)) {

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW

	}

	if (isExistedSingleCharInString(string, ch) == CCSTDC_FALSE) {

		return FIND_FAILED;

	}

	for (int i = 0; i < string->cur_Size; i++)
	{
		if (string->dataString[i] == ch)
			return i;
	}


}
#ifdef CCSTDC_VECTOR_H_ && CCSTDC_Pair_H_
CCSTDC_BOOL CCSTDC_ElemCount_isSameCharacter(const CCSTDC_Pair* ch1, CCSTDC_Pair* ch2) {

	return *((char*)ch1->m_Obj1) == *((char*)ch2->m_Obj1);

}




CCSTDC_Vector* countElemInString(CCSTDC_String* pointerToCounted)
{
	if (pointerToCounted == NULL && isEmptyString(pointerToCounted)) {

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW

	}

	if (isEmptyString(pointerToCounted)) {

		CCSTDC_SHOWERROR_MSG("No neccessity to find something!");

		return;
	}


	CCSTDC_Vector* getVec = initEmptyVector(SIZE(CCSTDC_Pair), 10, NULL);

	const char* front = pointerToCounted->stringFront;

	for (; front != pointerToCounted->stringRear; front++)
	{
		int elemCount = 1;

		CCSTDC_Pair* getPair = initPair(front, &elemCount, CHAR, INT);

		if (isExsitedinVector(getVec, getPair, CCSTDC_ElemCount_isSameCharacter)) {

			CCSTDC_Pair* place = searchTargetEleminVector(getVec, getPair, CCSTDC_ElemCount_isSameCharacter);

			(*(int*)place->m_Obj2)++;


		}
		else {

			pushBackVector(getVec, getPair, SIZE(CCSTDC_Pair));

		}

		free(getPair);
	};

	return getVec;
}

#endif


int* fastCountInASCII_String(CCSTDC_String* pointerToCounted) {

	if (pointerToCounted == NULL) {

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW

	}


	int* elemCount = (int*)malloc(sizeof(int) * 128);
	if (elemCount == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	for (int i = 0; i < pointerToCounted->cur_Size; i++) {

		elemCount[pointerToCounted->dataString[i]]++;

	}

	return elemCount;


}

// add

CCSTDC_String* insertCCString(CCSTDC_String* beCatted, CCSTDC_String* catter, int place) {
	if (isEmptyString(beCatted) || isEmptyString(catter)) {

		CCSTDC_SHOWERROR_MSG("string is emptied! try others!");

	}

	if (place < 0 || place > beCatted->cur_Size) {

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_INVALID_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_INVALID_INPUT_str, CCSTDC_INVALID_INPUT);

#endif // CCSTDC_ERROR_THROW
	}


	beCatted->dataString = (char*)realloc(beCatted->dataString, beCatted->cur_Size + catter->cur_Size - 1);

	if (beCatted->dataString == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	char* scanner = catter->stringFront;
	char* copier = beCatted->stringFront;
	for (int i = 0; i < place; i++, copier++);

	memmove(copier + catter->cur_Size - 1, copier, beCatted->cur_Size - place);

	for (int i = 0; i < catter->cur_Size - 1; i++, *copier++ = *scanner++);

	for (; *beCatted->stringRear++ != '\0';);

	beCatted->cur_Size += catter->cur_Size - 1;

	return beCatted;
}



CCSTDC_String* catCCString(CCSTDC_String* beCatted, CCSTDC_String* catter)
{

	if (isEmptyString(beCatted) || isEmptyString(catter)) {

		CCSTDC_SHOWERROR_MSG("string is emptied! try others!");

	}

	beCatted->dataString = (char*)realloc(beCatted->dataString, beCatted->cur_Size + catter->cur_Size - 1);

	if (beCatted->dataString == NULL) {
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	char* scanner = catter->stringFront;

	for (; *scanner != '\0'; *beCatted->stringRear++ = *scanner++);

	beCatted->cur_Size += catter->cur_Size - 1;

	return beCatted;
}




// --------------------------------- judgeMents --------------------------------------//
CCSTDC_BOOL isVaildString(CCSTDC_String* pointerToString) {

	if (pointerToString == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW
	}


	if (*pointerToString->stringRear == '\0') {
		return CCSTDC_TRUE;
	}

	return CCSTDC_FALSE;
}

CCSTDC_BOOL isEmptyString(CCSTDC_String* pointerToString)
{
	if (pointerToString == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW
	}
	if (*pointerToString->dataString == '\0') {
		return CCSTDC_TRUE;
	}

	return CCSTDC_FALSE;
}

CCSTDC_BOOL isGoodString(CCSTDC_String* pointerToWaited)
{
	if (pointerToWaited == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW
	}

	if (pointerToWaited->dataString == '\0')
	{
		if (pointerToWaited->cur_Size != 1)
		{
			return CCSTDC_FALSE;
		}

		if (pointerToWaited->stringFront != pointerToWaited->dataString)
		{
			return CCSTDC_FALSE;
		}

		if (pointerToWaited->stringRear != pointerToWaited->dataString)
		{
			return CCSTDC_FALSE;
		}

		return CCSTDC_TRUE;
	}

	char* checker = pointerToWaited->dataString;

	size cur_checked_size = 1;

	for (; *checker != '\0'; cur_checked_size++, checker++);
	/* lol, just for a fun writing, which is the abbr of this kind of for loop:

	for(char* checker = pointerToWaited->dataString; *checker != '\0'; checker++){

		cur_checked_size ++;

	}

	*/

	if (cur_checked_size++ != pointerToWaited->cur_Size) {
		return CCSTDC_FALSE;
	}

	if (checker != pointerToWaited->stringRear) {
		return CCSTDC_FALSE;
	}

	return CCSTDC_TRUE;

}

void fixBadString(CCSTDC_String* pointerToString)
{
	if (pointerToString == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW
	}

	if (isGoodString(pointerToString)) {

		CCSTDC_SHOWERROR_MSG("I don't think there is a neccessity of fixing your string... come on!\n");

		return;
	}

	char* checker = pointerToString->dataString;

	size cur_checked_size = 1;

	pointerToString->stringFront = checker;


	for (; *checker != '\0'; cur_checked_size++, checker++);
	/* lol, just for a fun writing, which is the abbr of this kind of for loop:

	for(char* checker = pointerToWaited->dataString; *checker != '\0'; checker++){

		cur_checked_size ++;

	}

	*/

	pointerToString->cur_Size = cur_checked_size;

	pointerToString->stringRear = &pointerToString->dataString[cur_checked_size];

	return;
}


// -------------------------------- Print String! ------------------
void printString(CCSTDC_String* pointerToString) {

	if (isEmptyString(pointerToString)) {
		CCSTDC_SHOWERROR_MSG("No need to print sth!\n");
		return;
	}

#ifdef BetterPrint_String
	printf("\nThe string will be shown as follows:>\n");
#endif 

	for (

		const char* printer = pointerToString->stringFront;

		printer != pointerToString->stringRear;

		printer++

		)
	{
		printf("%c", *printer);
	}

#ifdef BetterPrint_String
	printf("\nThe string finished it's shown-mission!\n");
#endif 

	return;
}

void reverseString(CCSTDC_String* pointerToString)
{

	if (pointerToString == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW
		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);
#endif 

	}

	QuickCheckOfString(pointerToString);

	if (isEmptyString(pointerToString))
	{

		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW 
		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);
#endif

	}
	char* fronter = pointerToString->stringFront;
	char* rearer = pointerToString->stringRear - 2;
	for (; fronter <= rearer; fronter++, rearer--) {

		char temp = *fronter;
		*fronter = *rearer;
		*rearer = temp;

	}

	return;
}

CCSTDC_String* to_StringInt(int numToString)
{
	int getter = numToString;
	int counter = 0;
	for (; getter != 0; getter /= 10, counter++);

	char* res = (char*)malloc(counter + 1);

	if (res == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_MALLOCING_SPACE_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_MALLOCING_SPACE_str, CCSTDC_ERROR_MALLOCING_SPACE);

#endif
	}

	getter = numToString;

	for (int i = 0; i < counter; i++) {

		res[i] = getter % 10 + '0';

		getter /= 10;
	}

	res[counter] = '\0';
	CCSTDC_String* get = updateString(res, counter + 1);
	reverseString(get);
	return get;
}

int isOrderUpFor_stringSortArrange(const char* ch1, const char* ch2) {
	return *ch1 > *ch2;
}

int isOrderDownFor_stringSortArrange(const char* ch1, const char* ch2) {
	return *ch1 < *ch2;
}

void stringSortArrange(CCSTDC_String* string,CCSTDC_sortCode code) {

	if(string == NULL)
	{
		CCSTDC_SHOWERROR_MSG(CCSTDC_ERROR_NULL_INPUT_str);

#ifdef CCSTDC_ERROR_THROW

		CCSTDC_FASTQUIT(CCSTDC_ERROR_NULL_INPUT_str, CCSTDC_NULL_INPUT);

#endif // CCSTDC_ERROR_THROW
	}

	switch (code)
	{
	case CCSTDC_ORDER_UP:
	{
		qsort(string->dataString, string->cur_Size - 1,CHAR, isOrderUpFor_stringSortArrange);
		break;
	}
	case CCSTDC_ORDER_DOWN:
	{
		qsort(string->dataString, string->cur_Size - 1, CHAR, isOrderDownFor_stringSortArrange);
		break;
	}
	default:
		CCSTDC_SHOWERROR_MSG("Invalid input, process reject to do any kind of sort!");
		break;
	}

	return;
}

void eraseString(CCSTDC_String* pStr) {

	if (isEmptyString(pStr)) {

		CCSTDC_SHOWERROR_MSG("Nope! that's invalid to erase a null ptr!");

		return;

	}

	free(pStr->dataString);

	free(pStr);

	return;
}