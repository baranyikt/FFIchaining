#include "mex.h"

#define		ARG_OUT_STR		plhs[0]
#define		ARG_OUT_NUM		plhs[1]
#define		ARG_IN_PREFIX	prhs[0]
#define		ARG_IN_POSTFIX	prhs[1]
#define		ARG_IN_NUM		prhs[2]

char* RetrieveString(char* label, int* depth);
void ReleaseString(const char* cptr);

/* calls RetrieveString() and embraces the result with the two input parameters, returns the whole string as a 1x3 cell in the first and only output parameter */
void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[]) {
	char* strings[3];
	int* pInt;
	mwSize nrOfConcatElements;
	switch (nrhs) {
		case 1: {
			nrOfConcatElements = 2;
			if (!mxIsChar(ARG_IN_PREFIX)) {
				mexErrMsgIdAndTxt("MATLAB:mstub:rhstype", "First input argument need to be of string type");
			}
			strings[0] = mxArrayToString(ARG_IN_PREFIX);	/* return value initialized & allocated to the proper size by mxMalloc/mxCreate within mxArrayToString() */
			strings[2] = NULL;
			pInt = NULL;
			break;
		}
		case 2: {
			nrOfConcatElements = 3;
			if (!mxIsChar(ARG_IN_PREFIX)) {
				mexErrMsgIdAndTxt("MATLAB:mstub:rhstype", "First input argument need to be of string type");
			}
			if (!mxIsChar(ARG_IN_POSTFIX)) {
				mexErrMsgIdAndTxt("MATLAB:mstub:rhstype", "Second input argument (if any) need to be of string type");
			}
			strings[0] = mxArrayToString(ARG_IN_PREFIX);	/* return value initialized & allocated to the proper size by mxMalloc/mxCreate within mxArrayToString() */
			strings[2] = mxArrayToString(ARG_IN_POSTFIX);	/* return value initialized & allocated to the proper size by mxMalloc/mxCreate within mxArrayToString() */
			pInt = NULL;
			break;
		}
		case 3: {
			nrOfConcatElements = 3;
			if (!mxIsChar(ARG_IN_PREFIX)) {
				mexErrMsgIdAndTxt("MATLAB:mstub:rhstype", "First input argument needs to be of string type");
			}
			if (!mxIsChar(ARG_IN_POSTFIX)) {
				mexErrMsgIdAndTxt("MATLAB:mstub:rhstype", "Second input argument (if any) needs to be of string type");
			}
			if (!mxIsClass(ARG_IN_NUM, "int32")) {
				mexErrMsgIdAndTxt("MATLAB:mstub:rhstype", "Third input argument (if any) needs to be of int32 type");
			}
			strings[0] = mxArrayToString(ARG_IN_PREFIX);	/* return value initialized & allocated to the proper size by mxMalloc/mxCreate within mxArrayToString() */
			strings[2] = mxArrayToString(ARG_IN_POSTFIX);	/* return value initialized & allocated to the proper size by mxMalloc/mxCreate within mxArrayToString() */
			pInt = (int*)mxGetData(ARG_IN_NUM);
			break;
		}
		default: {
			mexErrMsgIdAndTxt("MATLAB:mstub:rhscount", "1, 2 or 3 input argument needed");
			break;
		}
	}
	if ((nrhs == 3 && nlhs == 2) || (nrhs == 2 && nlhs == 1)) {
		//OK
	} else {
		mexErrMsgIdAndTxt("MATLAB:mstub:lhscount", "Wrong number of output arguments");
	}

	strings[1] = RetrieveString("from within C", pInt);	/* return value needs to be released by ReleaseString() at the end */
	
	if (pInt) {
		ARG_OUT_NUM = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
		int* pIntOut = (int*)mxGetData(ARG_OUT_NUM);
		*pIntOut = (*pInt);
	}

	ARG_OUT_STR = mxCreateCharMatrixFromStrings(nrOfConcatElements, (const char **)strings);
	
	mxFree(strings[0]);
	ReleaseString(strings[1]);
	if (strings[2])
		mxFree(strings[2]);
}
