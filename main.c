#include <stdio.h>
#include <stdlib.h>
#include "Dict.h"

char *random_string(long maxsize, long minsize)
{
	long size = arc4random()%(maxsize-minsize) + minsize;
	char *str = NEW(char, size);


	str[size-1] = 0;
	for(long i = size-1; i--;)
	{
		str[i] = arc4random()%127+1;
	}

	return str;
}

long rlen(long number, long base)
{
	return (number ? log(number) : 1)/log(base) + 1;
}

char *itoa_autobuff(int num, int base)
{
	long len = rlen(num, base);
	char *buff = NEW(char, len);
	sprintf(buff, "%d", num);

	return buff;
}

int main()
{
	Dict *dict = initNewDict();

	// write to Dictionary:
	for(long i = 1000*1000; i--;)
	{
		char *key = itoa_autobuff(i, 10);
		char *val = random_string(5, 15);

		if(getValueForKey(dict, key))
			free(getValueForKey(dict, key));
		setValueForKey(dict, val, key);
	}
	// read from Dictionary:
	for(long i = 1000*1000; i--;)
	{
		char *key = itoa_autobuff(i, 10);
		char *s = getValueForKey(dict, key);
		printf("%s\n", s);
	}
	return 0;
}