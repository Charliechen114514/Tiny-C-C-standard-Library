#define _CRT_SECURE_NO_WARNINGS 1
#define	OPENUPPOSARR 1
#define OPENUPDEFAULTSIZE 1
#define	QUICKMALLOC 1
//(General Version)
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Error Code Meaning
//Program Normally run till the end return NORMAL as 0
//When Error in mallocing Space the program return 1
//when inputing a NULL we returns -1
//when inputing a invalid input we returns -2
//Locations UnFind we returns -3 
//
typedef enum _DynamicFunctionStatues_ {
	DynamicArray_Normal = 0,
	DynamicArray_ERROR_IN_MALLOCING_SPACE=1,
	DynamicArray_NULL_INPUT=-1,
	DynamicArray_Invalid_Input=-2,
	DynamicArray_UnFind=-3,
	DynamicArray_Invalid_Free=-4
}DynamicArrayFunctionStatues;
//Mybool defined
//
typedef enum _bool_ {
	True = 1,
	False = 0
}Bool;
#define SHOW_ERROR_DynamicArray_NULL_INPUT printf("\nSorry! Your input NULL!\n")
#define SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE printf("\nSorry!Failed to malloc space for your data\n")
#define SHOW_ERROR_DynamicArray_Invalid_Input printf("\nYour input invalid, reject to run functions\n")
#define SHOW_ERROR_DynamicArray_UnFind printf("\nPositions unfind!\n")
#define SHOW_ERROR_DynamicArray_Invalid_Free printf("\nFree the invalid space,reject to run the functions\n")
//this type of int is specifically used in Returning Find Or Unfind.
//Recommmend to be used as a nickname:)
//Can use Find or Unfind to return the result
//
typedef enum _DynamicArray_isFind_ {
	Find=1,
	Unfind=0
}DynamicArray_isFind;

//A switch that used in better Print in Dynamic Array!
//Often use OPEN to beautify the control table
//
typedef enum _BetterPrintSwitch_for_dyarr_ {
	Dyarr_OPEN = 1,
	Dyarr_CLOSE = 0
}BetterPrintSwitch_for_dyarr;

//Main Definitions about DynamicArray
//When Programing , not recommend to Change the data directly! 
//
typedef struct _DynamicArray_ {
	void* DataPiece;
	size_t current_size;
	size_t total_usable_size;
	size_t Single_Data_size;
}DynamicArray;

//--------------------------------Default_size_Type--------------------------------------------
//These abstractions are used to reduce the input
//used as Dyarr_Default_TYPE(type_number) to replace the code:sizeof(Typename)*type_number
#if OPENUPDEFAULTSIZE

//Single Type size
//
#define Dyarr_SIGINT sizeof(int)
#define Dyarr_SIGCHAR sizeof(char)
#define Dyarr_SIGFLOAT sizeof(float)
#define Dyarr_SIGDOUBLE sizeof(double)
#define Dyarr_SIG(dataType) sizeof(dataType)

//Mutiply type size
//
#define Dyarr_INT_SIZE(X) sizeof(int)*X
#define Dyarr_CHAR_SIZE(X) sizeof(char)*X
#define Dyarr_FLOAT_SIZE(X) sizeof(float)*X
#define Dyarr_DOUBLE_SIZE(X) sizeof(double)*X
#define Dyarr_TYPE_SIZE(dataType,X) sizeof(dataType)*X

#endif


//-------------------------------------------QuickMalloc----------------------------------------

//As the name goes lol
//
#if QUICKMALLOC 

#define Dyarr_DEFAULT_MALLOC 5
#define MALLOCDYARR(datatype,data_num) (datatype*)malloc(sizeof(datatype)*data_num)

#endif


//----------------------------------------STD_FUNC_AND_INT_TYPE----------------------------------

// Return type of compared functions
//
typedef unsigned int Is_Used_Compared_Int;

// the pointer type of Print !
// When Printing , type :
// MyPrint user_print_function_name(datatype* e1, datatype* e2)
// {
//	print in your way for your data!
// }
//
typedef void(*MyPrint)(void*);

// the pointer type of Making change for the data that has been locates in the Dynamic Array!
// When want to make some change, type like this:
// Do_Specific_Change user_dochange_function_name(datatype* e1, datatype* e2)
//{
//	do some change here for your data!
//}
//
typedef void*(*Do_Specific_Change)(void*);

// the pointer type of using when comparing for your data
// When want to make a comparisons, type like this:
// CompareFunc user_comp_function_name(datatype* e1, datatype* e2)
//{
//	return //the wishing compare!//
//}
//
typedef Is_Used_Compared_Int(*CompareFunc)(void*,void*);

// the pointer type of using when checking iflocated for your data
// When want to make a comparisons, type like this:
// LocateFunc user_loc_function_name(datatype* e1, datatype* e2)
//{
//	return data1==data2(define by yourself! if complicated, just return Find or unfind to show whether is found)
//}
//
typedef Is_Used_Compared_Int(*LocateFunc)(void*, void*);


//-----------------------Position_Stored_Dynamic_Array_For_Dyarr---------------------------------
#if OPENUPPOSARR
//Main data structure!
//Used in returning multitude locations
//
typedef struct _Dyarrposarr_ {
	int* posSpace;
	size_t pos_size;
}Position_Stored_Dynamic_ArrayFordyarr;

//Want a better Print to beutify your control table? try this one
//
typedef enum _BetterPrintSwitch_for_pos_dyarr_ {
	PSDA_dyarr_OPEN = 1,
	PSDA_dyarr_CLOSE = 0
}BetterPrintSwitch_for_pos_dyarr;

//can use this type when indicating the type
//
typedef unsigned int BetterPrintfor_PosDyarr;

//About Position_Stored_Dynamic_Array_Func
//Create A Position_Stored_Dynamic_Array! Can init it in this way:
//>>Position_Stored_Dynamic_ArrayFordyarr* Name=Init_A_Postion_Stored_Dynamic_ArrayFordyarr();
//
Position_Stored_Dynamic_ArrayFordyarr* Init_A_Postion_Stored_Dynamic_ArrayFordyarr()
{
	Position_Stored_Dynamic_ArrayFordyarr* pro_usable_space = MALLOCDYARR(Position_Stored_Dynamic_ArrayFordyarr, 1);
	if (!pro_usable_space)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
  	pro_usable_space->posSpace = NULL;
	pro_usable_space->pos_size = 0;
	return pro_usable_space;
}
//About Positions_Stored_Dynamic_Array
//this function is aimed to output a series of locations that is stored in the pos
////Use PSDA_dyarr_OPEN to have a better shown ,else use PSDA_dyarr_CLOSE
//
DynamicArrayFunctionStatues Show_All_Locations_In_PSDAfor_dyarr(
	Position_Stored_Dynamic_ArrayFordyarr*				posarr,
	BetterPrintfor_PosDyarr								Whether_Better_Print
)
{
	if (!posarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (Whether_Better_Print == PSDA_dyarr_OPEN)
		printf("\nPositions are shown! :\n");
	for (int i = 0; i < posarr->pos_size; i++)
		printf("%u ", posarr->posSpace[i]);
	if (Whether_Better_Print == PSDA_dyarr_OPEN)
		printf("\nFinish Printing!\n");
	return DynamicArray_Normal;
}\

//About Positions_Stored_Dynamic_Array
//this function is aimed to push back a position into the Position_Stored_Dynamic_ArrayFordyarr
//
DynamicArrayFunctionStatues Push_back_a_locations_in_PSDA_dyarr(
	Position_Stored_Dynamic_ArrayFordyarr*				posarr, 
	int													pos_acquired
)
{
	int* pro_usable_space = (int*)realloc(posarr->posSpace, sizeof(int) * (posarr->pos_size + 1));
	if (!pro_usable_space)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	posarr->posSpace = pro_usable_space;
	posarr->posSpace[posarr->pos_size] = pos_acquired;
	posarr->pos_size++;
	return DynamicArray_Normal;
}

//About Positions_Stored_Dynamic_Array
//this function is aimed to return the number of locations
//Use PSDA_dyarr_OPEN to have a better shown ,else use PSDA_dyarr_CLOSE
//
size_t Get_pos_size_From_PSDA_for_dyarr(
	Position_Stored_Dynamic_ArrayFordyarr*				posarr,
	BetterPrintfor_PosDyarr								Whether_Shown_Print 
)
{
	if (!posarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (Whether_Shown_Print == PSDA_dyarr_OPEN)
		printf("\nCurrent targeted data's total num is:%u!\n",posarr->pos_size);
	return posarr->pos_size;
}

//About Positions_Stored_Dynamic_Array
//Erase a dynamic Array when donot using it!
//
DynamicArrayFunctionStatues DesTroy_A_PSDA_for_dyarr(
	Position_Stored_Dynamic_ArrayFordyarr*				pointer_to_wishedfreeposarr
)
{
	if (!pointer_to_wishedfreeposarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_Invalid_Free);
	}
	free(pointer_to_wishedfreeposarr->posSpace);
	free(pointer_to_wishedfreeposarr);
	pointer_to_wishedfreeposarr = NULL;
	return DynamicArray_Normal;
}

#endif

//----------------------------------DynamicArray----------------------------------------------------------------------
//About Dynamic Array
//A Properway to init a default and empty Dynamic Array
//Use like this: DynamicArray* Dyarr = Init_A_DynamicArray(expected_number, datasize)
//
DynamicArray* Init_A_DynamicArray(
	size_t												expected_number,
	size_t												datasize
)
{
	DynamicArray* pro_usable_space = MALLOCDYARR(DynamicArray, 1);
	if(!pro_usable_space)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	pro_usable_space->DataPiece = NULL;
	pro_usable_space->Single_Data_size = datasize;
	if (expected_number >= Dyarr_DEFAULT_MALLOC)
		pro_usable_space->total_usable_size = expected_number;
	else
		pro_usable_space->total_usable_size = Dyarr_DEFAULT_MALLOC;
	pro_usable_space->current_size = 0;
	return pro_usable_space;
}

//About Dynamic Array
//Copied up a Dyarr!
//Use like this: DynamicArray* copied_one = Init_A_DynamicArray_by_CopyADyarr(be_copied)
//
DynamicArray* Init_A_DynamicArray_by_CopyADyarr(
	DynamicArray*										dyarr_copied
)
{
	if (!dyarr_copied)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	DynamicArray* pro_usable_space = MALLOCDYARR(DynamicArray, 1);
	if (!pro_usable_space)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	void* pro_usable_data = MALLOCDYARR(char, (dyarr_copied->Single_Data_size * dyarr_copied->current_size));
	if(!pro_usable_space)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	pro_usable_space->DataPiece = pro_usable_data;
	memcpy(pro_usable_space->DataPiece, dyarr_copied->DataPiece, dyarr_copied->Single_Data_size * dyarr_copied->current_size);
	pro_usable_space->current_size = dyarr_copied->current_size;
	pro_usable_space->Single_Data_size = dyarr_copied->Single_Data_size;
	pro_usable_space->total_usable_size = dyarr_copied->total_usable_size;
	return pro_usable_space;
}

//About Dynamic Array
//An update! used to transform a static array to DynamicArray
//use like this:  
//DynamicArray* update_arr = Updata_A_Static_Array_To_Dynamic_Array(
//static arr,
//sizeof(data),
//how_many_data_are_there_in_the_static_array)
//
DynamicArray* Updata_A_Static_Array_To_Dynamic_Array(
	void*												data, 
	size_t												datasize,
	size_t												datanum
)
{
	if (!data)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	DynamicArray* pro_usable_space = MALLOCDYARR(DynamicArray, 1);
	if(!pro_usable_space)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	void* pro_usable_data = malloc(datasize * datanum*1.5);
	if(!pro_usable_data)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	memcpy(pro_usable_data, data, datasize * datanum);
	pro_usable_space->DataPiece = pro_usable_data;
	pro_usable_space->current_size = datanum;
	pro_usable_space->Single_Data_size = datasize;
	pro_usable_space->total_usable_size = 1.5 * datanum;
	return pro_usable_space;
}

//About Dynamic Array
//Push back a data into the Dynamic Array
//Use like this: Push_Back_Into_A_Dynamic_Array(dyarr,data)
//
DynamicArrayFunctionStatues Push_Back_Into_A_Dynamic_Array(
	DynamicArray*										dyarr, 
	void*												data
)
{
	if (!dyarr && !data)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (sizeof(data) != dyarr->Single_Data_size) 
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (dyarr->current_size == dyarr->total_usable_size)
		Resize_The_Dynamic_Array(dyarr, 2 * (dyarr->total_usable_size));
	void* Afteradd_piece = realloc(dyarr->DataPiece, (dyarr->current_size + 1)*dyarr->Single_Data_size);
	if (!Afteradd_piece)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	memcpy((char*)Afteradd_piece + dyarr->current_size * dyarr->Single_Data_size, data, dyarr->Single_Data_size);
	dyarr->DataPiece = Afteradd_piece;
	dyarr->current_size++;
	return DynamicArray_Normal;
}

//About Dynamic Array
//Push back a lot of data that has a organization that has all the same data
//Use like this: 
//Push_back_Same_data_Into_A_Dynamic_Array(dyarr,data,the_time_data_repeated,sizeof(data))
//
DynamicArrayFunctionStatues Push_back_Same_data_Into_A_Dynamic_Array(
	DynamicArray*										dyarr,
	void*												data,
	size_t												n_repeat,
	size_t												datasize
)
{
	if (!dyarr && !data)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (datasize != dyarr->Single_Data_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (dyarr->current_size == dyarr->total_usable_size)
		Resize_The_Dynamic_Array(dyarr, 2 * dyarr->total_usable_size);
	int datarate = datasize / dyarr->total_usable_size;
	if (datarate > 0)
		Resize_The_Dynamic_Array(dyarr, (datarate + 1) * dyarr->total_usable_size);
	void* newspace = realloc(dyarr->DataPiece, (dyarr->current_size + n_repeat) * dyarr->Single_Data_size);
	if (!newspace)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	for (int i = 0; i < n_repeat; i++)
		memcpy(
			(char*)newspace + (dyarr->current_size+i) * dyarr->Single_Data_size,
			data,
			dyarr->Single_Data_size
		);
	dyarr->DataPiece = newspace;
	dyarr->current_size += n_repeat;
	return DynamicArray_Normal;
}

//About Dynamic Array
//Push back a lot of data that has a organization that has a organiztion with static array
//Use like this: 
//Push_back_Same_data_Into_A_Dynamic_Array(
//dyarr,
//data,
//how_many_data_are_there_in_static_array,
//sizeof(data))
//
DynamicArrayFunctionStatues Push_Back_Some_data_Into_A_Dynamic_Array(
	DynamicArray*										dyarr, 
	void*												data_array, 
	size_t												array_num, 
	size_t												pos,
	size_t												data_inarray_size
)
{
	if (!dyarr && !data_array)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos<0 || pos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (data_inarray_size != dyarr->Single_Data_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	int DataRate = array_num / dyarr->total_usable_size;
	if (DataRate > 0)
		Resize_The_Dynamic_Array(dyarr, (DataRate + 1) * dyarr->total_usable_size);
	void* newspace = realloc(dyarr->DataPiece, (dyarr->current_size + array_num) * dyarr->Single_Data_size);
	if(!newspace)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	dyarr->DataPiece = newspace;
	for (int i = 0; i < array_num; i++)
		memcpy(
			(char*)dyarr->DataPiece + (pos + i) * dyarr->Single_Data_size,
			(char*)data_array + i * (dyarr->Single_Data_size),
			dyarr->Single_Data_size
		);
	dyarr->current_size += array_num;
	return DynamicArray_Normal;
}

//About Dynamic Array
//Reshape the dynamic array
//NOT ROCOMMEND TO USE UNLESS YOU ARE CONCIOUS OF WHAT YOU ARE DOING
//
DynamicArrayFunctionStatues Resize_The_Dynamic_Array(
	DynamicArray*										dyarr,
	size_t												wished_new_space_size
)
{
	if(!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	void* newspace = realloc(dyarr->DataPiece, wished_new_space_size * (dyarr->Single_Data_size));
	if (!newspace)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	dyarr->DataPiece = newspace;
	dyarr->total_usable_size = wished_new_space_size;
	if (dyarr->current_size > dyarr->total_usable_size)
		dyarr->current_size = dyarr->total_usable_size;//Used when still unable to contain data
	return DynamicArray_Normal;
}

// About Dynamic Array
// Insert back a data 
// use like this: 
// Insert_Into_A_Dynamic_Array(
// dyarr, 
// data, 
// where_to_insert,
//
DynamicArrayFunctionStatues Insert_Into_A_Dynamic_Array(
	DynamicArray*										dyarr, 
	void*												data, 
	size_t												pos
)
{
	if (!dyarr && !data)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos<0 || pos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (dyarr->current_size == dyarr->total_usable_size)
		Resize_The_Dynamic_Array(dyarr, 2 * (dyarr->total_usable_size));
	void* Afteradd_piece= realloc(dyarr->DataPiece, (dyarr->current_size + 1) * dyarr->Single_Data_size);
	if (!Afteradd_piece)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	memcpy(
		(char*)dyarr->DataPiece + (pos + 1) * dyarr->Single_Data_size,
		(char*)dyarr->DataPiece + pos * dyarr->Single_Data_size,
		dyarr->Single_Data_size*(dyarr->current_size-pos+1)
	);
	memmove(
		(char*)dyarr->DataPiece + pos * dyarr->Single_Data_size, 
		data, 
		dyarr->Single_Data_size
	);
	dyarr->current_size++;
	return DynamicArray_Normal;
}

//About Dynamic Array
//Insert back some data that organized in static array
//use like this: Insert_Into_A_Dynamic_Array(
// dyarr, 
// where_to_insert, 
// data, 
// how_many_data_are_there_in_static_array,
// sizeof(data)
//)
//
DynamicArrayFunctionStatues Insert_Some_Data_Into_A_Dynamic_Array(
	DynamicArray*										dyarr,
	size_t												pos,
	void*												data_array, 
	size_t												array_num,
	size_t												data_inarray_size
)
{
	if (!dyarr && !data_array)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos<0 || pos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (!dyarr->current_size)
	{
		Push_Back_Some_data_Into_A_Dynamic_Array(
			dyarr, 
			data_array, 
			array_num, 
			pos,
			data_inarray_size
		);
		return DynamicArray_Normal;
	}
	if (dyarr->current_size == dyarr->total_usable_size)
		Resize_The_Dynamic_Array(dyarr, 2 * dyarr->total_usable_size);
	int DataRate = array_num / dyarr->total_usable_size;
	if (DataRate > 0)
		Resize_The_Dynamic_Array(dyarr, (DataRate + 1) * dyarr->total_usable_size);
	void* Afteradd_piece = realloc(dyarr->DataPiece, (dyarr->current_size + array_num) * dyarr->Single_Data_size);
	if (!Afteradd_piece)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	memmove(
		(char*)dyarr->DataPiece + (pos + array_num) * dyarr->Single_Data_size,
		(char*)dyarr->DataPiece + pos * dyarr->Single_Data_size,
		dyarr->Single_Data_size*array_num
	);
	for (int i = 0; i < array_num; i++)
		memcpy(
			(char*)dyarr->DataPiece + (pos + i) * dyarr->Single_Data_size,
			(char*)data_array + i * (dyarr->Single_Data_size),
			dyarr->Single_Data_size
		);
	dyarr->current_size += array_num;
	return DynamicArray_Normal;
}

//About Dynamic Array
//Append another dynamic Array
// use like this:
// AppendByMergeDynamicArray(dyarr_be_appended, exp_append_array)
//
DynamicArrayFunctionStatues AppendByMergeDynamicArray(
	DynamicArray*											dyarr_be_appended,
	DynamicArray*											exp_append_array
)
{
	if (!dyarr_be_appended && !exp_append_array)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	int datarate = exp_append_array->current_size / dyarr_be_appended->total_usable_size;
	if (dyarr_be_appended->current_size == dyarr_be_appended->total_usable_size)
		Resize_The_Dynamic_Array(dyarr_be_appended, 2 * dyarr_be_appended->total_usable_size);
	if (datarate > 0)
		Resize_The_Dynamic_Array(dyarr_be_appended, (datarate + 1) * dyarr_be_appended->total_usable_size);
	void* AfterAppend = realloc(
		dyarr_be_appended->DataPiece,
		(dyarr_be_appended->current_size + exp_append_array->current_size) * dyarr_be_appended->Single_Data_size
	);
	if (!AfterAppend)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	dyarr_be_appended->DataPiece = AfterAppend;
	memcpy(
		(char*)dyarr_be_appended->DataPiece + dyarr_be_appended->current_size * dyarr_be_appended->Single_Data_size,
		(char*)exp_append_array->DataPiece,
		exp_append_array->current_size * exp_append_array->Single_Data_size
	);
	dyarr_be_appended->current_size += exp_append_array->current_size;
	
	return DynamicArray_Normal;
}

//About Dynamic Array
//Gain a copy of targeted array from the dynamic array
//use like this
// type* datawanna = Copy_A_Specific_DataFrom_A_Dynamic_Array_bypos(dyarr, datawanna, sizeof(datawanna))
//
void* Copy_A_Specific_DataFrom_A_Dynamic_Array_bypos(
	DynamicArray*											dyarr, 
	size_t													pos,
	void*													container,
	size_t													container_size
)
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos < 0 || pos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (dyarr->Single_Data_size> container_size)
	{
		printf("Specifically unable to contain your data! Try Larger one!\nNull pointer is returned!");
		return NULL;
	}
	if (dyarr->Single_Data_size < container_size)
	{
		printf(
			"Warning:Be Cautious the size doesn't fit!Please change your pointer step from %u to %u\nElse Error will be occurred", 
			container_size, 
			dyarr->Single_Data_size
		);
		exit(DynamicArray_Invalid_Input);
	}
	memcpy(
		container, 
		(char*)dyarr->DataPiece + pos * (dyarr->Single_Data_size), 
		container_size
	);
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually erase the final element!
// use like this:
// Pop_Out_From_A_Dynamic_Array(dyarr)
//
DynamicArrayFunctionStatues Pop_Out_From_A_Dynamic_Array(
	DynamicArray*											dyarr
)
{
	if(!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	dyarr->current_size--;
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually erase all elements!
// use like this:
// Clear_A_Dynamic_Array(dyarr)
//
DynamicArrayFunctionStatues Clear_A_Dynamic_Array(
	DynamicArray*											dyarr
)
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	dyarr->current_size = 0;
	if (!dyarr->DataPiece)
	{
		SHOW_ERROR_DynamicArray_Invalid_Free;
		printf("VOID DATA SHOULDN'T BE FREE!");
		exit(DynamicArray_Invalid_Free);
	}
	void* pro_usable_space= realloc(dyarr->DataPiece, dyarr->Single_Data_size);
	if (!pro_usable_space)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	dyarr->DataPiece=pro_usable_space;
	dyarr->total_usable_size = 1;
}

// About Dynamic Array
// Actually erase all elements! and unable to be used again!
// use like this:
// Destroy_A_Dynamic_Array(dyarr)
//
DynamicArrayFunctionStatues Destroy_A_Dynamic_Array(
	DynamicArray*												dyarr
)
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_Invalid_Free;
		exit(DynamicArray_Invalid_Free);
	}
	free(dyarr->DataPiece);
	free(dyarr);
	return DynamicArray_Normal;
}


// About Dynamic Array
// Actually Print All data
// use like this
// Print_ALL_Data_In_A_Dynamic_Array(dyarr,user_print_funtional_pointer, Dyarr_OPEN or Dyarr_ClOSE)
//
DynamicArrayFunctionStatues Print_ALL_Data_In_A_Dynamic_Array(
	DynamicArray*												dyarr,
	MyPrint														user_print,
	BetterPrintSwitch_for_dyarr									whether_better_print
)
{
	if (!dyarr && !user_print)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if(whether_better_print==Dyarr_OPEN)
	{
		printf("\nStart Printing\n");
	}
	for (int i = 0; i < dyarr->current_size; i++)
	{
		(*user_print)((char*)(dyarr->DataPiece) + i * (dyarr->Single_Data_size));
	}
	if (whether_better_print == Dyarr_OPEN)
	{
		printf("\nFinish Printing\n");
	}
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually Print a specific data
// use like this
//Print_Specific_Data_In_A_Dynamic_Array(dyarr, user_print, pos)
//
DynamicArrayFunctionStatues Print_Specific_Data_In_A_Dynamic_Array(
	DynamicArray*												dyarr, 
	MyPrint														user_print, 
	size_t														pos
) 
{
	if (!dyarr && !user_print)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos < 0 || pos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	printf("\nSpecific Data is Shown:\n");
	user_print((char*)(dyarr->DataPiece) + pos * (dyarr->Single_Data_size));
	printf("\nSpecific Data Finished Showing!\n");
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually make some change in all data
// use like this
// Do_Specific_Change_To_All_Data(dyarr, user_print, pos)
//
DynamicArrayFunctionStatues Do_Specific_Change_To_All_Data(
	DynamicArray*												dyarr, 
	Do_Specific_Change											user_change
) 
{
	if (!dyarr && !user_change)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	for (int i = 0; i < dyarr->current_size; i++)
		user_change((char*)(dyarr->DataPiece) + i * (dyarr->Single_Data_size));
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually make some change in a specific data
// use like this
// Do_Specific_Change_To_All_Data(dyarr, user_print, pos)
//
DynamicArrayFunctionStatues Do_Specific_Change_To_Specific_Data(
	DynamicArray*												dyarr, 
	Do_Specific_Change											user_change, 
	size_t														pos
)
{
	if (!dyarr && !user_change)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos < 0 || pos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	user_change((char*)(dyarr->DataPiece) + pos * (dyarr->Single_Data_size));
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually erase a specific data by pos
// use like this
// Delete_A_Specific_Data_From_the_DynamicArray(dyarr,  pos)
//
DynamicArrayFunctionStatues Delete_A_Specific_Data_From_the_DynamicArray(
	DynamicArray*												dyarr, 
	size_t														pos
)
{
	if(!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos < 0 || pos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	memcpy(
		(char*)dyarr->DataPiece+pos*dyarr->Single_Data_size,
		(char*)dyarr->DataPiece+(pos+1)*dyarr->Single_Data_size,
		dyarr->Single_Data_size*(dyarr->current_size-pos-1)
		);
	dyarr->current_size--;
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually erase some specific data by pos
// use like this
// Delete_A_Specific_Data_From_the_DynamicArray(dyarr, beginpos, endpos)
//
DynamicArrayFunctionStatues Delete_Some_Specific_Data_From_the_DynamicArray(
	DynamicArray*												dyarr, 
	size_t														Beginpos, 
	size_t														Endpos
)
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (Beginpos < 0 || Beginpos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (Endpos < 0 || Endpos>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	memcpy(
		(char*)dyarr->DataPiece + Beginpos * dyarr->Single_Data_size,
		(char*)dyarr->DataPiece + (Endpos + 1) * dyarr->Single_Data_size,
		dyarr->Single_Data_size * (dyarr->current_size - Endpos + 1)
	);
	dyarr->current_size -= Endpos - Beginpos + 1;
	if (dyarr->current_size <= dyarr->total_usable_size / 4 && dyarr->total_usable_size > 5)
	{
		Resize_The_Dynamic_Array(dyarr, dyarr->total_usable_size / 2);
		dyarr->total_usable_size /= 2;
	}
	return DynamicArray_Normal;
}

// About Dynamic Array
// Actually erase a specific data by pos
// use like this
// Delete_A_Specific_Data_From_the_DynamicArray(dyarr,  pos)
//
DynamicArrayFunctionStatues reverse_Data_In_DynamicArray(
	DynamicArray*												dyarr
) 
{
	if(!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	char* swapbit = (char*)malloc(dyarr->Single_Data_size);
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	for (int i = 0; i < dyarr->current_size / 2; i++)
	{
		memcpy(
			swapbit, 
			(char*)dyarr->DataPiece + i * dyarr->Single_Data_size, 
			dyarr->Single_Data_size
		);//ԭ�ͣ�int temp=*a,*a=*b,*b=temp
		memmove(
			(char*)dyarr->DataPiece + i*dyarr->Single_Data_size,
			(char*)dyarr->DataPiece + (dyarr->current_size - i-1) * dyarr->Single_Data_size,
			dyarr->Single_Data_size
		);
		memcpy(
			(char*)dyarr->DataPiece + (dyarr->current_size - i - 1) * dyarr->Single_Data_size, 
			swapbit, 
			dyarr->Single_Data_size
		);
	}
	free(swapbit);
	return DynamicArray_Normal;
}

//
// About Dynamic Array
// this is used in judging whether the dynamic array is empty
// use like this:
// isEmpty_InDynamicArray(dyarr)
//
Bool isEmpty_InDynamicArray(
	DynamicArray*												dyarr
) 
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!dyarr->current_size)
		return True;
	return False;
}

// About Dynamic Array
// this is used in swap data
// use like this:
// swapData_in_DynamicArray(dyarr,pos1,pos2)
//
DynamicArrayFunctionStatues swapData_in_DynamicArray(
	DynamicArray*												dyarr, 
	size_t														pos1, 
	size_t														pos2
)
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (pos1<0 || pos1>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	if (pos2<0 || pos2>dyarr->current_size)
	{
		SHOW_ERROR_DynamicArray_Invalid_Input;
		exit(DynamicArray_Invalid_Input);
	}
	char* swapbit = (char*)malloc(dyarr->Single_Data_size);
	if(!swapbit)
	{
		SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
		exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
	}
	memcpy(
		swapbit,
		(char*)dyarr->DataPiece + pos1 * dyarr->Single_Data_size,
		dyarr->Single_Data_size
	);
	memmove(
		(char*)dyarr->DataPiece + pos1 * dyarr->Single_Data_size,
		(char*)dyarr->DataPiece + pos2 * dyarr->Single_Data_size,
		dyarr->Single_Data_size
	);
	memcpy(
		(char*)dyarr->DataPiece + pos2 * dyarr->Single_Data_size,
		swapbit,
		dyarr->Single_Data_size
	);
	free(swapbit);
	return DynamicArray_Normal;
}

// About Dynamic Array
// sadly that is bubblesort :(
// I haven't make it in quicksort as it was toooooooooooooooooooooo tiring lol
// use like this:
// sort_In_Dynamic_Array(dyarr,comparision_funcuntional_pointer)
//
DynamicArrayFunctionStatues sort_In_Dynamic_Array(
	DynamicArray*												dyarr,
	CompareFunc													compfunc
) 
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!compfunc)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	for (int i = 0; i < dyarr->current_size-1; i++)
	{
		for (int j = 0; j < dyarr->current_size - i-1; j++)
		{
			if (
				compfunc(
							(char*)dyarr->DataPiece + j * dyarr->Single_Data_size,
							(char*)dyarr->DataPiece + (j + 1) * dyarr->Single_Data_size
						)
				)
				swapData_in_DynamicArray(dyarr, j, j + 1);
		}
	}
}

// About Dynamic Array
// check if located in the dynamic array
// use like this:
// isLocateinDyarr(dyarr, data, comparision_funcuntional_pointer)
//
DynamicArrayFunctionStatues isLocateinDyarr(
	DynamicArray*												dyarr,
	void*														data,
	LocateFunc													user_func
)
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!user_func)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!data)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	for (int i = 0; i < dyarr->current_size; i++)
	{
		if (user_func((char*)dyarr->DataPiece + i * dyarr->Single_Data_size, data))
		{
			return Find;
		}
	}
	return Unfind;
}

// About Dynamic Array
// return the position of data that is targeted 
// use like this:
// returnAElembyPos_inDyarr(dyarr, data, comparision_funcuntional_pointer)
//
DynamicArrayFunctionStatues returnAElembyPos_inDyarr(
	DynamicArray*												dyarr, 
	void*														data, 
	LocateFunc													user_func
) 
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!user_func)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!data)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	for (int i = 0; i < dyarr->current_size; i++)
	{
		if (user_func((char*)dyarr->DataPiece + i * dyarr->Single_Data_size, data))
		{
			return i;
		}
	}
	return Unfind;
}

// About Dynamic Array
// Using the function when Posarr is enable to use!
// return a bunch of position of data that is targeted 
// use like this:
// Position_Stored_Dynamic_ArrayFordyarr* pos =r eturnAElembyPos_inDyarr(dyarr, posArr,data, comparision_funcuntional_pointer)
//
#if OPENUPPOSARR
Position_Stored_Dynamic_ArrayFordyarr* returnABunchofData_inDyarr(
	DynamicArray*									dyarr, 
	Position_Stored_Dynamic_ArrayFordyarr*			posArr, 
	void*											data, 
	LocateFunc										user_func
)
{
	if (!dyarr)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!user_func)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	if (!data)
	{
		SHOW_ERROR_DynamicArray_NULL_INPUT;
		exit(DynamicArray_NULL_INPUT);
	}
	for (int i = 0; i < dyarr->current_size; i++)
	{
		int possible_count = 0;
		for (int i = 0; i < dyarr->current_size; i++)
		{
			if ((*user_func)(data, (char*)dyarr->DataPiece + i * dyarr->Single_Data_size))
			{
				int* pro_usable_stored_space = (int*)realloc(posArr->posSpace, sizeof(int) * (possible_count + 1));
				if (!pro_usable_stored_space)
				{
					SHOW_ERROR_DynamicArray_ERROR_IN_MALLOCING_SPACE;
					exit(DynamicArray_ERROR_IN_MALLOCING_SPACE);
				}
				posArr->posSpace = pro_usable_stored_space;
				posArr->posSpace[possible_count] = i;
				possible_count++;
				posArr->pos_size = possible_count;
			}
		}
		if (posArr->pos_size)
			return posArr;
		return Unfind;
	}
}
#endif
