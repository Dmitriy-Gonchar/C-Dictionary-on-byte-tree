#include "Dict.h"

Dict *initNewDict(void)
{
	Dict *dict = NEW(Dict);
	dict->isInit = YES;
	dict->subNodes = NEW(Dict *, 255);

	return dict;
}

void setValueForKey(Dict *dict, Value *value, char *key)
{
	do
	{
		if(!*key)
		{
			dict->value = value;
			return;
		}
		if(!dict->subNodes[*key])
			dict->subNodes[*key] = initNewDict();
		dict = dict->subNodes[*key];

		++key;
	} while (1);

	return;
}

Value *getValueForKey(Dict *dict, char *key)
{
	if(!dict || !dict->isInit || !key)
		return NULL;

	do
	{
		dict = dict->subNodes[*key];
		if(!dict || !dict->isInit || !dict->subNodes)
			return NULL;
		if(!*++key)
			return dict->value;
	} while (*key);

	return NULL;
}