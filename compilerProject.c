#include<stdio.h>
typedef struct _table {
	char *set;
}table;

table FindFirst(table rule, char *TNT);
table FindFllow(table rule, table *FirstTable, char *TNT, char *LT);
int main(int argc, char* argv[])
{
	FILE *fp=0;
	fp = fopen_s(&fp,argv[2],"r");
	char *i = (char*)malloc(sizeof(char));
	char *LT = (char*)malloc(sizeof(char)); // termianl
	char *TNT = (char*)malloc(sizeof(char)); //non -terminal
	//파일 읽기
	int Ltnum = 5;//terminal 의 개수 예시용
	int Ntnum = 4;//nonterminal의 개수 예시용
	char rule[2]={0,};
	int i=0;
	if(fp==NULL){
		printf("No text file");
		return 0;
	}
	while(fscnaf_s(fp,"%s",name.sizeof(rule))!=EOF){
		
		LT = (char*)malloc(sizeof(char)*i);
		fscanf_s(fp,"%c>%s",LT[i],TNT[i]);
		i++//
	}
	
	
	
	//data 읽었다고 가정하고 실행
	
	table *FirstTable;
	table *FllowTable;
	table *GotoTable;
	table *ActionTable;

	table *ruleTable;

	//for (int i = 0; i < a; i++)
	ruleTable = (table*)malloc(sizeof(table)*10);
	ruleTable->set = (char*)malloc(sizeof(char) * 10);

	ruleTable[0].set[0] = "E";
	ruleTable[0].set[1] = "E";
	ruleTable[0].set[2] = "+";
	ruleTable[0].set[0] = "T";

	FirstTable = (table*)malloc(sizeof(table)*Ltnum);
	FirstTable->set = (char*)malloc(sizeof(char)*Ntnum);

	FllowTable = (table*)malloc(sizeof(table)*Ltnum);
	FllowTable->set = (char*)malloc(sizeof(char)*Ntnum);





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
