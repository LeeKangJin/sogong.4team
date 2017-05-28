#include <stdio.h> 



int main(){ 
	
	char *LT;//Terminal  
	char *NT;// non Terminal 
	int rule;//rule number  
	



	char *FirstTable;
	char *FllowTable;

	char *ActionTable;
	char *GotoTable;

	FirstTable = (char*)malloc(sizeof(char)*(sizeof(LT) / sizeof(LT[0])*(sizeof(NT)/sizeof(NT[0]))));
	FllowTable = (char*)malloc(sizeof(char)*(sizeof(LT) / sizeof(LT[0])*(sizeof(NT) / sizeof(NT[0]))));




		//First & Follow 
		//database of SLR parsing table(action +goto) 
		// I iterator(i0, i1 ..)  

	return 0; 
} 
/*example input 
R1  E>E + T 
R2  E>T 
R3  T>TF 
R4  T>F 
R5  F>(E)
R6  F>x 
*/