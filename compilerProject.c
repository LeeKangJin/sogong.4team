#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct _table {
	char *set;
}table;

table FindFirst(table rule, char *TNT);
table FindFllow(table rule, table *FirstTable, char *TNT, char *LT);

char* TNTsetting(char *LT, char **RT, int ruleNum);

int main(int argc, char* argv[])
{
	FILE *fp = 0;
	fp = fopen(argv[1], "r");
	char *LT = (char*)malloc(sizeof(char)); ; // termianl
	char RT[100][100];//non -terminal malloc으로 수정하기
	char TNT[100];
	char tempR[100] = { "", };
	char tempC;
	int ruleNum = 0;
	int rulesize;

	if (fp == NULL) {
		printf("No text file");
		return 0;
	}
	while (fscanf(fp, "%c%d\n", tempC, ruleNum) != EOF) {

		fscanf(fp, "%c>%s\n", tempC, tempR);
		LT[ruleNum] = strcat(".", tempC);
		rulesize = max(rulesize, sizeof(tempC));
		*RT[ruleNum] = tempR;
		realloc(LT, sizeof(char)*ruleNum);
	}
	LT[0] = "S";
	*RT[0] = LT[1];
	*TNT = TNTsetting(LT, RT, ruleNum);
	
	//closure 배열 이 I(0 ...6 이런거)


	
	
	
	
	
	//tnt 에 goto에 넣을것들 순서가 들어있음
									   /*
									   for(i)//i의 길이끝)
									   for (j)//tnt의 길이끝)
									   {
									   Goto(closure배열중 set, TNT[j])

									   //더이상의 Goto가 없으면 break;
									   }

									   Do it




									   */
									   //rule 개수만큼 할당




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


void Closure(int i, char *TNT) {// 배열에 .을 만들어 주는 함수.  ->.이 찍힌 배열을 closure라던지 따로 생성해줄필요 있음.




	//.과 룰들이 담겨져있음.


}

void Goto(char *a, char b) {


//Closure 배열(a)중 .앞에 b가 있으면 새로운 clouser 배열을 생성한다. .과 b를 temp


}

void First(char* LT, char **RT) {

// non termianl을 찾은뒤 그뒤에 terminal이 있으면
// 그 terminal의 first는 찾은 nonterminal이 된다.


}

void Fllow() {

//Lingsum알고리즘이용
}

void SLRTable() {//slrtable을 setting 해주는것.

//이게 메인과정 여태껏 만든 closure을 받아서 Table형성

}

void SLRparsing() {
// 메인과정 . table이용해서 parsing
}

//@override
char* TNTsetting(char *LT, char **RT, int ruleNum) {
	char temp[100];
	int z=1;
	temp[0] = LT[1];

	for (int i = 1; i < ruleNum; i++) {
		if (!strchr(temp, LT[i]))
		{
			temp[z] = LT[i];
			z++;
		}
	}
	
	for (int j = 0; j < ruleNum; j++)//RT size까지
	{
		for (int i = 0; i < 100; i++) {
			if (!strchr(temp, RT[j][i]))
			{
				temp[z] = RT[j][i];
				z++;
			}

		
		}
	}


}




char* TNTsetting(char *LT, char **RT, int ruleNum) {
	char temp[100];
	char tempR[100][100];
	char tempT[100];
	int z;

	for (int i = 0; i < ruleNum; i++) {
		temp[i] = LT[i];
	}
	for (int i = 0; i< ruleNum; i++) {
		for (int j = 0; j < 100; j++)
		{
			tempR[i][j] = RT[i][j];
		}
	}


	for (int j = 0; j < ruleNum; j++)
	{
		for (int k = 0; k < ruleNum; k++)
		{
			if (temp[j] == temp[k] && j != k);
			temp[k] == "";
		}

		for (int x = 0; x < 100; x++)
		{
			if (temp[j] == RT[j][x])
				tempR[j][x] = "";

		}
	}

	for (int i = 0; i < ruleNum; i++) {
		if (temp[i] != "") {
			tempT[z] = temp[i];
			z++;
		}
	}

	for (int i = 0; i < ruleNum; i++)
		for (int j = 0; j < 100; j++)
		{
			if (tempR[i][j] != "")
				tempT[z] = tempR[i][j];
			z++;
		}
	return tempT;

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