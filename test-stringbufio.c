#if 0
gcc -o test-stringbufio *.c -Wall -Wfatal-errors -O3
if [ "$?" = "0" ]; then
	time ./test-stringbufio
fi
exit
#endif

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "ref.h"
#include "stringbuf.h"
#include "stringbufio.h"

void test_1(void)
{
	stringbuf_t *buf = stringbufio_FromFile("hello.txt");
	assert(buf != NULL);
	assert(strcmp(buf->ptr, "Hello!") == 0);
}

int main(int argc, char *argv[])
{
	test_1();
	
	return 0;
}

