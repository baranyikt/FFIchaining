#include <stdlib.h>			/* malloc, free */

char* RetrieveString(char* label, int* depth) {
	static const char* appendix = " -- stopped here in C";
	const size_t inLen = strlen(label);
	const size_t appendixLen = strlen(appendix);
	const size_t memNeeded = inLen + appendixLen + 1;
	char* retval = (char*)malloc(memNeeded);
	if (depth)
		(*depth)++;
	strcpy(retval, label);
	strcat(retval, appendix);
	return retval;
}

void ReleaseString(const char* cptr) { 
	free(cptr);
}


/*

a much more trivial (testing) version:

char* RetrieveString(char* label, int* depth) {
	static const char* answer = "Hello, ";
	return answer;
}
void ReleaseString(const char* cptr) {  } 

*/
