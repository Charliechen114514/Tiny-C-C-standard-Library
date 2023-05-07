#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*

	Developed and written in April 2nd

	by CharlieChen

*/

// -------------------Files_Include------------------------

#include<stdlib.h>
#include<stdio.h>
#include<memory.h>
#include<time.h>
#include<math.h>
#include<stdarg.h>


// -------------------END_INCLUDING------------------------


// ------------------------------------ Settings Abstractions --------------------------------------------------

#define CCSTDC_ERROR_THROW
#define CCSTDC_DATASTRUCTER_CASE
#define BetterPrint
// ---------------------------------------------- Sections include ----------------------------------------------

/// 
/// standard Developer and debuggar Kit 
/// this sections are aimed to helped a quick test and debug.
/// 
/// 
#define CCSTDC_QUICK_DEVELOPER_KIT
// --------------------------------------------------- PreWork -------------------------
// These sections are included for preWorking and preDealing 
// sections are included : 
// 1. my own bool defined, and also, to help run in all compiling platform
// 2. define size structs, in this way, programs can be better read for better understanding the programs
// 3. define byte type, to be using in bytes level
// 4. define the general error code for ccstdc Code
// 5. define the pair node for further HashSet or HashTable
// 6. define the Item node for general


// Section 1  -> undefined the bool type and turn to use our own one in CCSTDC Lib
#ifdef true
#undef true
#endif // true // erase the ordinary true

#ifdef false
#undef false
#endif // false // erase the ordinary false


#define CCSTDC_QUICKSLASH printf("\n")
#define CCSTDC_QUICKSLASH_N(N) for(int i = 0; i < N; i++, printf("\n"));
// --------------------------------------------------------------------------------


//
// Section 2 -> define the typical size , and recreate a new type called byte
// 


#ifdef size
#undef size
#endif

#ifdef pointerToSize
#undef pointerToSize
#endif

// ----------------------------define the size type------------------------------

typedef unsigned int size;

#define INT sizeof(int)
#define CHAR sizeof(char)
#define LONG sizeof(long)
#define DBL sizeof(double)
#define FLT sizeof(float)
#define SIZE(X) sizeof(X) 
typedef unsigned int* pointerToSize;

// ------------------------------------------------------------------------------

// define the byte type, to get operation in byte level
typedef unsigned char byte;

typedef enum _CCSTDC_BOOL_ {
	CCSTDC_FALSE,
	CCSTDC_TRUE
}CCSTDCbool;

typedef unsigned int CCSTDC_BOOL;
// define the common error code

typedef enum _CCSTDC_ERROR_CODE_ {

	// If the program process without throwing errors
	CCSTDC_NORMAL,

	CCSTDC_ERROR_MALLOCING_SPACE,

	CCSTDC_NULL_INPUT,

	CCSTDC_INVALID_INPUT,

	CCSTDC_INVALID_FREE

}CCSTDC_ERROR_CODE;

// generalFunctions Call

typedef void(*Printer)(void*);

typedef CCSTDCbool(*Compare)(void*, void*);

typedef void(*operateStructElem)(void*);
#ifdef CCSTDC_ERROR_THROW

// fast quit abstractions
#define CCSTDC_SHOWERROR_MSG(error) printf("\n[From CCSTDC_Error : MSG]%s\n",error)
#define CCSTDC_INFO(cString) printf("%s",cString)
#define CCSTDC_INFO_Line(cString) printf("%s\n",cString)
#define CCSTDC_INFO_CSTRING(CCString) printString(CCString)

#define GETVARNAME(VAR) #VAR
#define PRINTVARNAME(VAR) printf("%s ",#VAR);
#define CCSTDC_FASTQUIT(errorMsg,QuitCode) CCSTDC_SHOWERROR_MSG(errorMsg);exit(QuitCode);


#define CCSTDC_ERROR_MALLOCING_SPACE_str "Error in mallocing space, process might quit...\n"
#define CCSTDC_ERROR_NULL_INPUT_str "Error for your sadly null input, process might get quit\n"
#define CCSTDC_ERROR_INVALID_INPUT_str "Error for your invalid input! Well... simply check your program can help a lot...\n"
#define CCSTDC_ERROR_INVALID_FREE_str "Come on, it's no good free a invalid space...\n"

#endif

#ifdef BetterPrint

#define BetterPrint_String // if you dislike the abstractions plz comment it



#endif

typedef enum _CCSTDC_isFind_ {

	FIND_FAILED = -1,
	FIND_SUCCESS = 0

}CCSTDC_isFind;

typedef enum _CCSTDC_sortType_ {

	CCSTDC_ORDER_UP   = 0x00000001,
	CCSTDC_ORDER_DOWN = 0x00000002,

}CCSTDC_sortType;

typedef unsigned int CCSTDC_sortCode;
