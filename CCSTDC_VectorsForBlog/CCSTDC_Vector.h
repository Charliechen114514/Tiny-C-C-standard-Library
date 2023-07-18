#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define CCSTDC_Error_Throw(Error_Code) printf("Error occured!");exit(Error_Code)

typedef char CCSTDC_Bool;
typedef enum {
    CCSTDC_True = 1,
    CCSTDC_Flase = 0
};
typedef unsigned int CCSTDC_Moving_Selection;
typedef enum {
    CCSTDC_Copy = 1,
    CCSTDC_Move = 2
};
typedef void(*Printer)(void*);
typedef CCSTDC_Bool(*CCSTDC_Comparator)(void*, void*);


typedef struct _CCSTDC_Vector {

    void* coreData;		// ������ͨ��ָ����ϵ������
    size_t dataSize;	// ������ָ���洢Ԫ�صĴ�С
    size_t curSize;		// ������ָ���洢Ԫ�ص����и���
    size_t capicity;		// �����������������ɶ���Ԫ��
}CCSTDC_Vector;

CCSTDC_Vector* CCSTDC_Vector_EmptyInit(int dataSize, int wishing_capicity);
CCSTDC_Bool* CCSTDC_Vector_Resize(CCSTDC_Vector* vector, int wishing_capicity);
CCSTDC_Bool CCSTDC_Vector_PushBack(CCSTDC_Vector* vector, void* data, int datasize);
CCSTDC_Bool CCSTDC_Vector_PrintList(CCSTDC_Vector* vector, Printer printFunc);
CCSTDC_Bool CCSTDC_Vector_DestroyWhole(CCSTDC_Vector* vector);
CCSTDC_Bool CCSTDC_Vector_Insert(CCSTDC_Vector* vector, int pos, void* elem);

typedef CCSTDC_Vector CCSTDC_GainGuide_PosArray;
CCSTDC_GainGuide_PosArray* CCSTDC_Vector_FindTarget(
    CCSTDC_Vector* vec,
    void* Elem,
    CCSTDC_Comparator compareFunc
);

void* CCSTDC_Vector_GetPyPos(CCSTDC_Vector* vec, int pos, CCSTDC_Moving_Selection usrChoice);
CCSTDC_Bool CCSTDC_Vector_EraseByPos(CCSTDC_Vector* vec, int place);
CCSTDC_Bool CCSTDC_Vector_EraseByGivenData(CCSTDC_Vector* vec, void* targetElem, CCSTDC_Comparator compareFunc);
