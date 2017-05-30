#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct _table {
	char *set;
}table;

table FindFirst(table rule, char *TNT);
table FindFllow(table rule, table *FirstTable, char *TNT, char *LT);

int main(int argc, char* argv[])
{
	FILE *fp = 0;
	fp = fopen(argv[1], "r");
	char *i;
	char *LT = (char*)malloc(sizeof(char)); ; // termianl
	char TNT[100][100];//non -terminal malloc으로 수정하기
	char tempR[100] = { NULL, };
	char tempC;
	int  tempRN;
	int ruleNum=0;
	int rulesize;

	if (fp == NULL) {
		printf("No text file");
		return 0;
	}
	else {
	//실험용

		while ((fscanf(fp, "%s\n", tempR)) != EOF)

			fscanf(fp, "%s\n", tempR);
		    
			printf("%s\n", rulesize);
	}




	
	while (fscanf(fp,"%c%d\n",tempC,tempRN) != EOF) {
		
		fscanf(fp, "%c>%s\n", tempC, tempR);
		LT[ruleNum] = tempC;
		*TNT[ruleNum] = tempR;
		ruleNum++;
		realloc(LT, sizeof(char)*ruleNum);
		// TNT realloc 할것

		//룰 개수 세기
	}
	//rule 개수만큼 할당


	



	//data 읽었다고 가정하고 실행

	table *FirstTable;
	table *FllowTable;
	table *GotoTable;
	table *ActionTable;

	table *ruleTable;

	//for (int i = 0; i < a; i++)
	ruleTable = (table*)malloc(sizeof(table) * 10);
	ruleTable->set = (char*)malloc(sizeof(char) * 10);

	FirstTable = (table*)malloc(sizeof(table));
	FirstTable->set = (char*)malloc(sizeof(char));

	FllowTable = (table*)malloc(sizeof(table));
	FllowTable->set = (char*)malloc(sizeof(char));





	//파일 내용 dataBase만들어서 보관

	// dataBase로 table 생성

	// table 이용 first, follow ,tableprint, action, goto, exit 함수 만들기
	if (i == "FIRST") {}
	else if (i == "FOLLOW") {}
	else if (i == "TABLE") {}
	else if (i == "ACTION") {}
	else if (i == "GOTO") {}
	else if (i == "exit") {}
	else if (i[0] == "I") {}
	

	fclose(fp);
	return 0;

}
/*
R1
E>E + T
R2
E>T
R3
T>T*F
R4
T>F
R5
F>(E)
R6
F>x
*/
