#include<stdio.h>
typedef struct _table {
	char *set;
}table;

table FindFirst(table rule, char *TNT);
table FindFllow(table rule, table *FirstTable, char *TNT, char *LT);
int main()
{
	char *i = (char*)malloc(sizeof(char));
	char *LT = (char*)malloc(sizeof(char)); // termianl
	char *TNT = (char*)malloc(sizeof(char)); //non -terminal
	//���� �б�
	int Ltnum = 5;//terminal �� ���� ���ÿ�
	int Ntnum = 4;//nonterminal�� ���� ���ÿ�

	//data �о��ٰ� �����ϰ� ����
	
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