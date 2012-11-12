#include <stdio.h>

#include "ref.h"
#include "stringbuf.h"

#include "stringbufio.h"

stringbuf_t *stringbufio_FromFile(const char *file)
{
	FILE *f = fopen(file, "r");
	if (f == NULL) {return NULL;}
	
	stringbuf_t *buf = stringbuf_New(1024);
	char c[2];
	c[1] = '\0';
	while (1) {
		c[0] = fgetc(f);
		if (feof(f)) break;
		
		stringbuf_Append(buf, c);
	}
	
	fclose(f);
	return buf;
}

