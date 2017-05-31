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
	char RT[100][100];//non -terminal malloc���� �����ϱ�
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
	
	//closure �迭 �� I(0 ...6 �̷���)


	
	
	
	
	
	//tnt �� goto�� �����͵� ������ �������
									   /*
									   for(i)//i�� ���̳�)
									   for (j)//tnt�� ���̳�)
									   {
									   Goto(closure�迭�� set, TNT[j])

									   //���̻��� Goto�� ������ break;
									   }

									   Do it




									   */
									   //rule ������ŭ �Ҵ�




									   //���� ���� dataBase���� ����

									   // dataBase�� table ����

									  
									   // table �̿� first, follow ,tableprint, action, goto, exit �Լ� �����
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


void Closure(int i, char *TNT) {// �迭�� .�� ����� �ִ� �Լ�.  ->.�� ���� �迭�� closure����� ���� ���������ʿ� ����.




	//.�� ����� ���������.


}

void Goto(char *a, char b) {


//Closure �迭(a)�� .�տ� b�� ������ ���ο� clouser �迭�� �����Ѵ�. .�� b�� temp


}

void First(char* LT, char **RT) {

// non termianl�� ã���� �׵ڿ� terminal�� ������
// �� terminal�� first�� ã�� nonterminal�� �ȴ�.


}

void Fllow() {

//Lingsum�˰����̿�
}

void SLRTable() {//slrtable�� setting ���ִ°�.

//�̰� ���ΰ��� ���²� ���� closure�� �޾Ƽ� Table����

}

void SLRparsing() {
// ���ΰ��� . table�̿��ؼ� parsing
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
	
	for (int j = 0; j < ruleNum; j++)//RT size����
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