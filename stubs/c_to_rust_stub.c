#pragma comment(lib, "c_to_rust.lib")			// linking against the Rust library
#pragma comment(lib, "ws2_32.lib")				// Rust static library has external links to these libraries
#pragma comment(lib, "userenv.lib")				//	these are listed here to avoid link time errors
#pragma comment(lib, "advapi32.lib")

char* RetrieveString(char* label, int* depth);
void ReleaseString(const char* cptr);

int main()
{
	const char* inputarg = "from within C";
	int i = 1;
	int* pInt = &i;
	char* p;
	printf("Before RetrieveString...\n");
#ifdef _DEBUG	
	printf("C/outputarg = %p, C/inputarg = %p, C/depth = %p, C/*depth = %i\n", 
		(void*)p,
		(void*)inputarg,
		(void*)pInt,
		(int)*pInt);
#endif
	p = RetrieveString("from within C", pInt);
	printf("After RetrieveString...\n");
#ifdef _DEBUG	
	printf("C/outputarg = %p, C/inputarg = %p, C/depth = %p, C/*depth = %i\n", 
		(void*)p,
		(void*)inputarg,
		(void*)pInt,
		(int)*pInt);
	printf("Listing outputarg:");
	for (int i = 0; i < 10; ++i) {
		printf("\t[%c]",p[i]);
	}
	printf("\n");
#endif
	printf("string = %s, int = %i\n", p, i);
	ReleaseString(p);
	printf("After ReleaseString...exiting\n");
}
