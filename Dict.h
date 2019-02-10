/// KVO Dictionary Jesus++ 2016
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "new.h"

#define DICT 0xD1C7
#define SDIC 0x5D1C
#define HDIC 0x8D1C

#define HDSZ sizeof(void*)

typedef char BOOL;
static BOOL YES = 1;
static BOOL NO = 0;

/// Value for other types wrap in Dict-nodes
typedef struct Value
{
	void *ptr;
	long size;
	long type;
} Value;

/// Dictionary like a NSDictionary
typedef struct Dict
{
	struct Dict **subNodes;
	Value *value;
	BOOL isInit;
} Dict;

/// Definition:
Dict *initNewDict(void);
void setValueForKey(Dict *dict, Value *value, char *key);
Value *getValueForKey(Dict *dict, char *key);
//char **getAllKeys(Dict *d);