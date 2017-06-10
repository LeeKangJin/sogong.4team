#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
//코드 0 맨뒤에 사이즈를 보관하는것 에서 문제가생김...
typedef struct _ruleList {
	struct _node *cur;
	struct _node *head;
	struct _node *tail;
}ruleList;

typedef struct _node {
	char data;
	int listsize;
	struct _node *next;
	struct _node *before;
}node;

typedef struct _iList {
	struct _iNode *cur;
	struct _iNode *head;
	struct _iNode *tail;
}iList;


typedef struct _iNode {
	ruleList **iData;
	int iNum;
	struct _iNode *next;
}iNode;

typedef struct _gotoNode {
	int ibefoNum;
	char inputChar;
	int iafterNum;
	struct _gotoNode *next;

}gotoNode;

typedef struct _gotoList {
	struct _gotoNode *cur;
	struct _gotoNode *head;
	struct _gotoNode *tail;
}gotoList;

#define STACK_SIZE 100

char stack[STACK_SIZE];
int STACK_TOP = 0;
int TSIZE = 0;
int NTSIZE = 0;
int IListNum = 0;
int COUNTING = 0;
int ILIST_COUNTING = 0;
//Stack 함수
void push(char a);
void pop();
void sprint();
//
void saveListSize(ruleList *L, int listsize);
void listsetting(ruleList *L);                           //Linked List를 null로 초고화 해주는함수.
void createNode(ruleList *L, char tdata);                  //node를 만들어서 List뒤에 달아주는함수.
void deleteelastNode(ruleList *L);                        //Linked List 삭제
void printNodes(ruleList *L);                           //Linked List 인쇄
int closure(iList *ilistx, ruleList **closured, ruleList *T, ruleList **rule, int ruleNum);
void gotofuc(ruleList **iData, char moveDotOfChar, gotoList *saveigoto, ruleList *T, ruleList **rule, int ruleNum,iList *ilist);
void findNT(ruleList **L, ruleList *T, ruleList *NT, int ruleNum, int localTsize, int localNTsize);
void findFirst(ruleList *L, char terminal, ruleList *T, ruleList *NT, ruleList **rule, int ruleNum);
int ifterminal(ruleList *T, char checkT);                  //terminal인지 확인
int ifsamenode(ruleList *L, char checkND);
int ifsameList(ruleList **L, ruleList *R, int Lsize); // L안에 R이 있는지 확인
void findFllow(ruleList **L, ruleList **FirstSet, char terminal, ruleList *T, ruleList *NT, ruleList **rule, int ruleNum);
int isEpsilron(ruleList **L, ruleList *T, int ruleNum, char checkE);
ruleList *FirstIs(ruleList **FirstSet, char checkFirst);
int FllowRow(ruleList **L, char checkF);
void checkRightTerminal(ruleList **L, ruleList **rule, ruleList **firstset, char terminal, ruleList *T, int ruleNum);//Fllow에 쓰일 input terminal 오른쪽에 terminal이 있는지 확인하고 붙여주는것.
void Equal(ruleList **fllowset, char left, ruleList **flowOrfirstset, char right);
int SearchList(ruleList *L, char checkC);
int iListNum(ruleList **rule, int ruleNum);
int searchAfterDot(ruleList **SearchList, ruleList *DotList, int ruleNum);
int CountHead(ruleList **rule, char countchar, ruleList *T, int ruleNum);
int isiList(iList *ilist, ruleList **contra);
//function prototype
void iListSetting(iList *L);
ruleList **makeListNotSame(ruleList **temp1, ruleList **temp2);
void CtrlCList(ruleList **temp, ruleList **CtrlCed);
void createGotoNode(gotoList *L, int ibeforenum, char inputchar, int iafternum);
void createiNode(iList *L, ruleList **iset, int listnum);
void RuleListSetting(ruleList **rule, int size);
void AddRule(ruleList **tempNode, ruleList **rule, ruleList *T, char chaseingTerminal, int ruleNum, int size);
void CtrlCRule(ruleList *CtrlCed, ruleList *Addrule);         // 링크드리스트 left <- right 복사
int main() {
	FILE *fp;


	int i = 0;
	char c;
	char a[100] = { 0, };
	int ruleNum;
	int localNTsize = 0;
	int localTsize = 0;
	int iNum = 0;
	ruleList *nonterminal = (ruleList*)malloc(sizeof(ruleList)); //말그대로 nonterminal들 
	ruleList *terminal = (ruleList*)malloc(sizeof(ruleList));    // terminal set



	listsetting(nonterminal);
	listsetting(terminal);

	//~@rule size를 찾기.
	fp = fopen("rule.txt", "r");
	if (fp == NULL)
	{
		printf("파일이없습니다.");
		return 0;
	}

	while (fscanf(fp, "%c%d\n", &c, &ruleNum) != EOF) {
		fscanf(fp, "%s\n", a);
	}


	printf("rule num: %d", ruleNum);
	fclose(fp);
	//test...
	ruleList **rule = (ruleList**)malloc(sizeof(ruleList*)*(ruleNum + 1));  //Rule들의 집합(링크드리스트)
	RuleListSetting(rule, ruleNum + 1);
	saveListSize(rule[0],  ruleNum + 1);
	fp = fopen("rule.txt", "r");

	//ruleList배열에 규칙 담기
	while (fscanf(fp, "%c%d\n", &c, &ruleNum) != EOF) {

		while (c != '\n') {
			if (fscanf(fp, "%c", &c) == EOF)
				break;

			if (c != '\n')
				createNode(rule[i + 1], c);
		}
		fscanf(fp, "\n", c);
		i++;
	}
	//초기설정(S>E) 여기서 E는 첫번째 받은 terminal로 설정
	createNode(rule[0], 'S');
	createNode(rule[0], '>');
	createNode(rule[0], rule[1]->head->data);
	//nonterminal 집합 만들기

	printf("%c", rule[0]->head->next->data);
	printf("%c", rule[0]->head->next->next->before->data);

	findNT(rule, terminal, nonterminal, ruleNum, localTsize, localNTsize);
	localTsize = TSIZE;
	localNTsize = NTSIZE;
	ruleList **firstset = (ruleList**)malloc(sizeof(ruleList*)*localTsize);
	terminal->cur = terminal->head;
	saveListSize(firstset[0], localTsize);
	for (int i = 0; i <localTsize; i++)
	{
		node*n = (node*)malloc(sizeof(node));
		n->next = NULL;
		firstset[i] = n;
		listsetting(firstset[i]); //모든 first룰규칙들 NULL초기화
		createNode(firstset[i], terminal->cur->data);
		terminal->cur = terminal->cur->next;
	}

	// firstset
	terminal->cur = terminal->head;
	for (int j = 0; j < localTsize; j++) {
		findFirst(firstset[j], terminal->cur->data, terminal, nonterminal, rule, ruleNum);
		terminal->cur = terminal->cur->next;
	}

	ruleList **fllowset = (ruleList**)malloc(sizeof(ruleList*)*localTsize);
	saveListSize(fllowset, localTsize);
	terminal->cur = terminal->head;
	for (int i = 0; i <localTsize; i++)
	{
		node*n = (node*)malloc(sizeof(node));
		n->next = NULL;
		fllowset[i] = n;
		listsetting(fllowset[i]); //모든 fllow룰규칙들 NULL초기화
		createNode(fllowset[i], terminal->cur->data);
		terminal->cur = terminal->cur->next;
	}


	terminal->cur = terminal->head;
	for (int j = 0; j < localTsize; j++) {
		findFllow(fllowset, firstset, terminal->cur->data, terminal, nonterminal, rule, ruleNum);
		terminal->cur = terminal->cur->next;
	}

	// iNum = iListNum(rule, ruleNum);
	//terminal 수 nonterminal수 세기 
	iList *ilist = (iList*)malloc(sizeof(iList));//총 index수만큼 i list를 만든다.
	ruleList *DotList = (ruleList*)malloc(sizeof(ruleList));                                                                    //i 의 index는 총 몇개인지? (공식이아닌듯) 
	ruleList *SDot = (ruleList*)malloc(sizeof(ruleList));
	gotoList *SaveGotoRule = (gotoList*)malloc(sizeof(gotoList));
	listsetting(SaveGotoRule);
	listsetting(ilist);
	printNodes(fllowset[0]);
	printNodes(firstset[0]);
	printNodes(fllowset[2]);

	//S->.E를 만들자
	CtrlCRule(SDot, rule[0]);
	node *AddDot = (node*)malloc(sizeof(node));
	AddDot->next = NULL;
	AddDot->data = '.';
	AddDot->next = SDot->head->next->next;
	SDot->head->next->next = AddDot;//Dot 추가

	int *num1 = (int*)malloc(sizeof(int));
	*num1 = 1;
	SDot->tail->next = num1;

	ruleList **LDot = (ruleList**)malloc(sizeof(ruleList*));
	RuleListSetting(LDot, 1);
	CtrlCRule(LDot[0], SDot);
	
	

	createGotoNode(SaveGotoRule, 0, rule[1]->head->data, -1);
	closure(ilist, LDot, terminal, rule, ruleNum, SaveGotoRule);//i0생성
	// i0 0번째 S->E.으로..
	
	for (int i = 0; i < ilist->head->iData[0]->tail->next->data; i++) {
		printNodes(ilist->head->iData[i]); //testing
	}
	iNode *tempPointer = (iNode*)malloc(sizeof(iNode));
	tempPointer->next = NULL;

	//main here
	ilist->cur = ilist->head;
	
	while (ilist->cur != NULL) {
		
		searchAfterDot(ilist->cur->iData, SDot, ilist->cur->iData[0]->tail->next->data);
		SDot->cur = SDot->head;
	
		while (SDot->cur->next != NULL) { //Dot뒤에가없으면 while문 안들어감
			tempPointer->next = ilist->cur;
			gotofuc(ilist->cur->iData, SDot->cur->data, SaveGotoRule, terminal, rule, ruleNum,ilist);
			ilist->cur = tempPointer->next;
			SDot->cur = SDot->cur->next;
		}
		
		listsetting(SDot);
	
		ilist->cur = ilist->cur->next;
	}

	ilist->cur = ilist->head;
	{
		while (ilist->cur->next != NULL) {
			for (int i = 0; i < ilist->cur->iData[0]->tail->next->data; i++)
				printNodes(ilist->cur->iData[i]);
			ilist->cur = ilist->cur->next;
		}
		printf("\n\n");
	}








	// ilist ->head 에있는 즉 i0 
	// i0 0번은 S->E.으로 만들어준다. 다음 closure의 편의를 위하여 i0 1번부터 사용할것. 

	//main here
	//GOTO(I0 E){}
	// I0 에서 E를 검사후 쩜하나 옴긴다..!!! ***



	/*
	void c0(iList *ilist){

	while (ilist->cur->iData != NULL)
	{
	listsetting(DotList);
	searchAfterDot(ilist->iData, DotList);
	creategotoList(ilist->cur->iNum, DotList->cur->data, 0); //table에 필요한 정보 스캔..
	gotofuc(ilist->cur->iNum)
	}





	goto(i0, DotList(1)) -> i1생성  //할때마다 isettingList에서 .을 이동해준다.
	goto(i0, DotList(2)) -> i2생성..// 생성시에 입력이 nonterminal이고 .뒤에 terminal이 생기면 ilist[0]에서 그 terminal이 앞에있는것들도 넣어줌.
	..
	..
	goto(i0,DotList(final)) ->i final 생성

	if serachAferDot 이 없으면 종료.
	serachAfterDot
	goto(i1, Dot(1))
	..
	goto(ij Dot n)

	j++

	j가없을 경우종료.


	gotofunc(ilist[0], 'E') = i1; //goto fun에서 i를 setting 해줘야할듯 ,input이 ilist가 들어가서 그다음 인풋을 모든 t,nt에서 돌려서 list다음번째에 그게있는지 확인해야할듯
	printNodes(ilist[0][1]);
	*/

	scanf("%d", &i);
	return 0;

}
//fun now


int searchAfterDot(ruleList **SearchList, ruleList *DotList, int ruleNum) { //.이후에있는 값들을 DotList에 저장한다.

	ruleList *tempDotList = (ruleList*)malloc(sizeof(ruleList));
	listsetting(tempDotList);
	for (int i = 0; i < ruleNum; i++) {

		SearchList[i]->cur = SearchList[i]->head->next->next;

		while (SearchList[i]->cur != NULL) {
			if (SearchList[i]->cur->data == '.' && SearchList[i]->cur->next != NULL) {
				if (ifsamenode(tempDotList, SearchList[i]->cur->next->data) == 0)
					createNode(tempDotList, SearchList[i]->cur->next->data);
			}
			SearchList[i]->cur = SearchList[i]->cur->next;
		}
	}


	DotList->head = tempDotList->head;
	DotList->tail = tempDotList->tail;
	if (DotList->head == NULL)                        //.이후에 뭐가없다. -> 0리턴
		return 0;

	else return 1;

}
int iListNum(ruleList **rule, int ruleNum) {
	int ilistnum = 0;

	for (int i = 0; i < ruleNum + 1; i++) {
		rule[i]->cur = rule[i]->head->next->next;
		while (rule[i]->cur != NULL) {
			ilistnum++;
			rule[i]->cur = rule[i]->cur->next;
		}
	}
	return ilistnum;

}
void findFllow(ruleList **L, ruleList **FirstSet, char terminal, ruleList *T, ruleList *NT, ruleList **rule, int ruleNum) {//Fllowset에 앞에 먼저 terminal을 달아줌.
	ruleList *tempList = (ruleList*)malloc(sizeof(ruleList));
	ruleList **tempRule = (ruleList**)malloc(sizeof(ruleList*)*(ruleNum + 1));
	int ruleindex;
	for (int a = 0; a < ruleNum + 1; a++)
	{
		node*n = (node*)malloc(sizeof(node));
		n->next = NULL;
		tempRule[a] = n;
		listsetting(tempRule[a]); //모든 룰규칙들 NULL초기화
	}
	listsetting(tempList);
	tempRule = rule;

	int j = 0;
	//step1 첫번째로 들어오는 ex) E 에 뒤에 달린거 조사.

	//해당 terminal의 뒤에달린걸 조사한뒤에 삽입.
	if (terminal == rule[1]->head->data) { //E냐?
		createNode(L[0], '$');
		checkRightTerminal(L, rule, FirstSet, terminal, T, ruleNum);

	}

	else if (terminal != rule[1]->head->data) {   //E가 아니면
		checkRightTerminal(L, rule, FirstSet, terminal, T, ruleNum);
	}


	//Fllow(E) = Fllow(T)이런것들.. (ifE가들어온상태)
	//ruleindex = SearchList(rule, terminal);//E가들어있는 룰 들을 찾음. 그룰들의 마지막을 서치 이넘이문제

	for (int i = 0; i < ruleNum + 1; i++) {
		rule[i]->cur = rule[i]->head;
		if (rule[i]->head->data == terminal) {
			while (rule[i]->cur->next != NULL) {
				rule[i]->cur = rule[i]->cur->next;
			}

			if (ifterminal(T, rule[i]->cur->data) == 0)
			{

				if (ifsamenode(L[FllowRow(L, terminal)], rule[i]->cur->data) == 0 && rule[i]->cur->data != '#')
					createNode(L[FllowRow(L, terminal)], rule[i]->cur->data);

			}

			else if (ifterminal(T, rule[i]->cur->data) != 0) {

				Equal(L, terminal, L, rule[i]->cur->data);
				Equal(L, rule[i]->cur->data, L, terminal);


			}
		}
	}


}

void checkRightTerminal(ruleList **L, ruleList **rule, ruleList **firstset, char terminal, ruleList *T, int ruleNum) {//그 해당 terminal의 오른쪽이 terminal이냐?
	int temp;
	for (int i = 0; i < ruleNum + 1; i++) {
		rule[i]->cur = rule[i]->head->next->next;
		while (rule[i]->cur->next != NULL) {

			if (rule[i]->cur->data == terminal) {
				if (ifterminal(T, rule[i]->cur->next->data) == 0) //terminal이 아니면
					createNode(L[FllowRow(L, terminal)], rule[i]->cur->next->data); // 내오른쪽에 nonterminal이 있으면 나에 해당하는 Row에 nonterminal을 저장 


				else if (ifterminal(T, rule[i]->cur->next->data) != 0) //terminal인데, 그게 #으로 갈경우
				{

					for (int j = 0; j < ruleNum + 1; j++) {
						if (rule[j]->head->data == rule[i]->cur->next->data &&rule[j]->head->next->next->data == '#')//그 terminal중에 #으로가는게 있는가?
						{

							for (int k = 0; k < TSIZE; k++) {
								if (firstset[k]->head->data == rule[j]->head->data)
									temp = k;
							}
							Equal(L, rule[j]->head->data, firstset, rule[j]->head->data);//Fllow(E) =First(F)  EF라는식이있는경우.
							checkRightTerminal(L, rule, firstset, rule[j]->head->data, T, ruleNum);//다시한번 그오른쪽에 뭐가있나본다.

						}

					}
				}
			}
			rule[i]->cur = rule[i]->cur->next;
		}

	}
}
int SearchList(ruleList *L, char checkC) {
	int returnValue = 0;
	L->cur = L->head;

	while (L->cur != NULL) {

		if (L->cur->data == checkC)
			returnValue++;

		L->cur = L->cur->next;
	}
	L->cur = L->head;
	return returnValue;
}



void Equal(ruleList **fllowset, char left, ruleList **flowOrfirstset, char right) {//left에다가 right것들을 집어넣음

	ruleList *tempLeft = (ruleList*)malloc(sizeof(ruleList));
	ruleList *tempRight = (ruleList*)malloc(sizeof(ruleList));
	//Fllow(left)=Fllow(right)
	//Flow(left) = First(right)
	int leftnum;
	for (int i = 0; i < TSIZE; i++)//TSIZE 전역변수 안되면Do it
	{
		if (right == flowOrfirstset[i]->head->data)
		{
			tempRight = flowOrfirstset[i];
		}
		if (left == fllowset[i]->head->data)
		{
			tempLeft = fllowset[i];
			leftnum = i;
		}
	}
	tempRight->cur = tempRight->head->next;// right를 탐색   
	while (tempRight->cur != NULL) {

		if (SearchList(tempLeft, tempRight->cur->data) == 0)
			createNode(fllowset[leftnum], tempRight->cur->data);
		tempRight->cur = tempRight->cur->next;
	}

}

int FllowRow(ruleList **L, char checkF) {
	for (int i = 0; i < TSIZE; i++) {// TSIZE안되면 지역변수로 받을것 Do it
		if (L[i]->head->data == checkF) {
			return i;
		}
	}
	return 0;

}
void findFirst(ruleList *L, char terminal, ruleList *T, ruleList *NT, ruleList **rule, int ruleNum) {// E 

	char temp;
	int k;
	int i = 1;
	ruleList *tempList = (ruleList*)malloc(sizeof(ruleList));
	ruleList **tempRule = (ruleList**)malloc(sizeof(ruleList*)*(ruleNum + 1));
	for (int a = 0; a < ruleNum + 1; a++)
	{
		node*n = (node*)malloc(sizeof(node));
		n->next = NULL;
		tempRule[a] = n;
		listsetting(tempRule[a]); //모든 룰규칙들 NULL초기화
	}
	tempRule = rule;

	listsetting(tempList);


	createNode(tempList, terminal);

	tempList->cur = tempList->head;

	for (; i < ruleNum + 1; i++)
	{
		tempRule[i]->cur = tempRule[i]->head;
		if (tempRule[i]->cur->next != NULL) {
			if (tempRule[i]->cur->next->next != NULL) {
				if (tempRule[i]->cur->data == tempList->cur->data && tempRule[i]->cur->next->next->data != tempList->cur->data != NULL) //E와 같다면
				{
					if (ifterminal(T, tempRule[i]->cur->next->next->data) == 0)//첫번째 우항이 terminal이 아니라면  
					{
						if (ifsamenode(L, tempRule[i]->cur->next->next->data) == 0) // 저장이 안되어있다면 저장
						{
							createNode(L, tempRule[i]->cur->next->next->data);

						}

					}

					else if (ifterminal(T, tempRule[i]->cur->next->next->data) != 0) {//첫번째 우항이 terminal이라면
						createNode(tempList, tempRule[i]->cur->next->next->data);//그 terminal을 넣는다.
						i = 1;
						tempList->cur = tempList->cur->next; //이제 그 넣은 terminal을 조사한다.
					}
				}


				if (tempRule[i]->cur->next->next->data == '#' && i == ruleNum) { //'#일때 예외처리'

					for (int j = 0; j < ruleNum + 1; j++) {
						if (tempRule[j]->cur->next->next != NULL && tempRule[j]->cur->next->next->next != NULL) {
							if (tempRule[j]->cur->next->next->data == tempRule[i]->head->data) //F가있는 첫번째행을 찾는다.
							{
								if (tempRule[j]->cur->next->next->next != NULL) {
									if ((ifterminal(T, tempRule[j]->cur->next->next->next->data) == 0)) //terminal이 아니면
										createNode(L, tempRule[j]->cur->next->next->next->data);

								}
								if ((ifterminal(T, tempRule[j]->cur->next->next->next->data) != 0))// termianl 이면
								{
									tempRule[i]->cur->next->next = tempRule[i]->cur->next->next->next;
									i = 1;

								}
							}
						}
					}
				}
			}
		}
	}

}

ruleList* FirstIs(ruleList **FirstSet, char checkFirst) {
	//해당 문자의 First를 리턴해주기 #은 제외( Fllow에서 사용하는것임으로)
	ruleList *temp = (ruleList*)malloc(sizeof(ruleList));
	listsetting(temp);

	for (int i = 0; i < TSIZE; i++) //전역변수 이상하면 넘겨받기 
	{
		FirstSet[i]->cur = FirstSet[i]->head;
		if (FirstSet[i]->cur->data == checkFirst) {
			while (FirstSet[i]->cur->next != NULL) {
				if (FirstSet[i]->cur->data != '#')
					createNode(temp, FirstSet[i]->cur->data);
				FirstSet[i]->cur = FirstSet[i]->cur->next;
			}
		}
	}
	if (temp->head != NULL)
		return temp;
	else if (temp->head == NULL)
		return NULL;

}



int ifterminal(ruleList *T, char checkT) {

	node *temp = (node*)malloc(sizeof(node));
	temp = T->cur;
	T->cur = T->head;
	int k = 0;
	for (int i = 0; i < TSIZE; i++)
	{
		if (checkT == T->cur->data)
			k++;
		T->cur = T->cur->next;
	}

	T->cur = temp;
	if (k != 0)
		return 1; // terminal이 있으면

	else if (k == 0)
		return 0; // terminal이 없으면

}

int isEpsilron(ruleList **L, ruleList *T, int ruleNum, char checkE) {
	//checkE가 앱실론을 가지고 있으면 1
	//앱실론 없으면 0반환
	if (ifterminal(T, checkE) != 0) { //terminal이 아니면 무조건  0반환
		for (int i = 0; i < ruleNum + 1; i++) {
			if (L[i]->head->data == checkE &&
				L[i]->head->next->next->data == '#') {
				return 1;

			}
		}
	}
	return 0;
}
// edit..
int ifsameList(ruleList **L, ruleList *R, int Lsize) {//L 에 R이 있는지 검사. 
	int check = 0;
	int k = 0;
	int j = 0;
	for (int i = 0; i < Lsize; i++) {
		L[i]->cur = L[i]->head;
		R->cur = R->head;
		k = 0;
		j = 0;
		while (R->cur != NULL &&L[i]->cur != NULL) {
			//now
			if (R->cur == R->tail->next && L[i]->cur == L[i]->tail->next ){
				break;
			}


			if (R->cur->data == L[i]->cur->data)
			{
				k++; //같으면 k증가
			}

			j++;
			R->cur = R->cur->next;
			L[i]->cur = L[i]->cur->next;
		}
		if (k == j && k != 0 && j != 0)// 한 리스트가 모두 같다 -> k==j이다
			return 1; //같은 노드가있다.

	}

	return 0; // 같은 노드가 없다.


}

int ifsamenode(ruleList *L, char checkND) { //중복제거 함수

	int k = 0;
	L->cur = L->head;
	while (L->cur != NULL) {
		if (L->cur->data == checkND)
			k++;
		L->cur = L->cur->next;
	}
	if (k == 0)
		return 0;//겹치는게 하나도 없다 -> 리턴 0
	else
		return 1; //겹치는게 하나라도 있다 -> 리턴 ~


}

void findNT(ruleList **L, ruleList *T, ruleList *NT, int ruleNum, int localTsize, int localNTsize) {

	node *temp = (node*)malloc(sizeof(node));
	temp->data = NULL;
	temp->next = NULL;
	char *terminal = (char*)malloc(sizeof(char)*(ruleNum + 1));
	char *tempterminal = (char*)malloc(sizeof(char)*(ruleNum + 1));
	int j = 0;
	int k = 0;
	localTsize = 0;
	localNTsize = 0;
	for (int i = 0; i < ruleNum + 1; i++) {
		terminal[i] = L[i]->head->data;  //terminal 집합 만들기
		L[i]->cur = L[i]->head->next;
	}


	while (j != (ruleNum + 1)) {
		for (int i = 0; i < ruleNum + 1; i++) {
			if (terminal[i] == L[j]->cur->data)
				k++;            // >우변에서 terminal과 일치하는 개수보기

		}
		if (k == 0 && L[j]->cur->data != '>') {   //terminal 집합과 일치하는게 하나도없다, >도 아니다 !
			createNode(NT, L[j]->cur->data);    //그것은 nonterminal 이군 NT에들어가
			localNTsize++;                          //겸사겸사 nonterminal 수도세기

		}
		k = 0;

		if (L[j]->cur->next != NULL)
			L[j]->cur = L[j]->cur->next;       //볼것이 더있으면 next node로

		else {
			L[j]->cur = L[j]->head;
			j++;                               //볼게 없으면 다음번 리스트로 이동
		}
	}
	createNode(T, terminal[1]);
	T->cur = T->head;


	while (1) {
		j = 0;
		for (int i = 1; i < ruleNum + 1; i++)
		{
			if (terminal[i] == T->cur->data) {
				terminal[i] = 1;
			}
			if (terminal[i] == 1) {
				j++;
			}
		}
		k = 1;
		while (1)
		{
			if (terminal[k] != 1)
			{
				createNode(T, terminal[k]);
				T->cur = T->cur->next;
				localTsize++;
				break;
			}
			k++;
		}
		if (j == ruleNum)
			break;

	}
	printNodes(T);



	TSIZE = localTsize;
	NTSIZE = localNTsize;
	printf("\n%d\n", NTSIZE);//Do del
	printf("%d\n", TSIZE);//Do del


}
int CountHead(ruleList **rule, char countchar, ruleList *T, int ruleNum) {

	int k = 0;
	for (int i = 0; i < ruleNum + 1; i++) {
		if (rule[i]->head->data == countchar)   // E->T , T->F F->(E)
		{
			k++;
			if (ifterminal(T, rule[i]->head->next->next->data) != 0 && rule[i]->head->data == countchar && rule[i]->head->next->next->data != countchar) // E->T 같은게 있다면
				k = k + CountHead(rule, rule[i]->head->next->next->data, T, ruleNum);
		}
	}
	return k;

}




void RuleListSetting(ruleList **rule, int size) {
	for (int i = 0; i < size; i++) {
		node*n = (node*)malloc(sizeof(node));
		n->next = NULL;
		rule[i] = n;
		listsetting(rule[i]); //m모든 룰규칙들 NULL초기화
	}
}

void CtrlCList(ruleList **temp, ruleList **CtrlCed) {//temp의 크기가 커야함 ctrled할것은 작아도 들어감.
	int ctrlcedsize = CtrlCed[0]->tail->next->data;

	for (int i = 0; i < ctrlcedsize; i++) {
		CtrlCRule(temp[i], CtrlCed[i]);
	}
}


ruleList **makeListNotSame(ruleList **temp1, ruleList **temp2) {
	int temp1size = temp1[0]->tail->next->data;
	int temp2size = temp2[0]->tail->next->data;
	int j = 0;
	ruleList **newtemp = (ruleList*)malloc(sizeof(ruleList)*(temp1size + temp2size));
	RuleListSetting(newtemp, temp1size + temp2size);
	CtrlCList(newtemp, temp1);

	for (int i = 0; i < temp2size; i++)
	{
		if (ifsameList(newtemp, temp2[i], temp1size) == 0) //같은 노드가없다.
		{
			while (newtemp[j]->head != NULL) {
				j++;
			}
			CtrlCRule(newtemp[j], temp2[i]);
		}
	}

	return newtemp;

}
//deep copy????
void CtrlCRule(ruleList *CtrlCed, ruleList *Addrule) {
	//Addrule이 이미있는 LinkedList, CtrlCed가 새로 복사할 LinkedLIst 이함수는 
	listsetting(CtrlCed);
	int *size = (int*)malloc(sizeof(int));
	Addrule->cur = Addrule->head;
	
	while (Addrule->cur != NULL) {

		createNode(CtrlCed, Addrule->cur->data);
		Addrule->cur = Addrule->cur->next;
	}
	saveListSize(CtrlCed, Addrule->tail->listsize);
}

void AddRule(ruleList **tempNode, ruleList **rule, ruleList *T, char chaseingTerminal, int ruleNum, int size) {
	//chaseingTerminal 을 계속해서 추적해서 
	// >다음에 .을달고 >앞이chaseingTerminal과 다른 terminal일때 
	//또다시 addRule을한다.
	//추가해야될 rule은 head가 널인곳에 넣어주기.
	int j = 0;
	ruleList *Addrule = (ruleList*)malloc(sizeof(ruleList));
	listsetting(Addrule);
	node *AddDot = (node*)malloc(sizeof(node));
	AddDot->next = NULL;
	AddDot->data = '.';

	for (int i = 0; i < ruleNum + 1; i++) {
		rule[i]->cur = rule[i]->head;
		if (rule[i]->head->data == chaseingTerminal) {

			if (ifterminal(T, rule[i]->head->next->next->data) != 0 && rule[i]->head->next->next->data != chaseingTerminal)
				AddRule(tempNode, rule, T, rule[i]->head->next->next->data, ruleNum, size);

			CtrlCRule(Addrule, rule[i]);//chaseingTerminal이 가지고 있는 LinkedList를 복사.
			AddDot->next = Addrule->head->next->next;
			Addrule->head->next->next = AddDot;//Dot 추가

			while (tempNode[j]->head != NULL) {
				if (j >= size - 1)
					break;
				j++;

			}

			if (j < size && ifsameList(tempNode, Addrule, size) == 0 && rule[i]->head->next->next->data != '#')
				CtrlCRule(tempNode[j], Addrule);
		}
	}
}
/*
while(ilist->iData->cur != NULL)
searchAfterDot (ilist->iData , DotList); //마지막 ilist idata를 집어넣는다.
(쩜이후에 뭔가가있을 경우에 searchAfterDot 리턴값으로 )
if( 리턴값 ==0) 이면 goto함수 실행 안하고
ilist를 next한다.
고투 함수 시작
void gotofuc(iLIst  , char DotList->cur , save ilist){
쩜이후에 뭐가있는 iList가들어옴 그다음에 char들도 들어옴)
goto list에 (쩜이후에 뭐가있는 ilist의 index , 쩜다음 문자 , closure 리턴값 )저장
그럼 closure을 실행
}


void findDOt



}
*/


void gotofuc(ruleList **iData, char moveDotOfChar, gotoList *saveigoto, ruleList *T, ruleList **rule, int ruleNum,iList *ilist) {
	//상위 단계에서 saveigoto 저장되어있는상태.
	//i0에서 moveDotOfChar 가 .앞에있으면 .을 이동시킴. 이동시킨것들을 closure해줌.

	int rulesize = 0;
	int j = 0;
	int tempsize;
	rulesize = 0;

	if (iData[0]->head != NULL){
		rulesize = iData[0]->tail->next->data;
	
	}
	ruleList **temp = (ruleList**)malloc(sizeof(ruleList*)*rulesize);
	RuleListSetting(temp, rulesize);
	node *tempPointer = (node*)malloc(sizeof(node));
	tempPointer->next = NULL;
	if (iData[0]->head != NULL)
	{
		for (int i = 0; i < rulesize; i++) {

			iData[i]->cur = iData[i]->head;
			printNodes(iData[i]);
			printf("\n\n");
			while (iData[i]->cur != NULL) {

				if (iData[i]->cur->data == '.' && iData[i]->cur->next->data == moveDotOfChar)
				{
					
					tempPointer->next = iData[i]->cur;
					CtrlCRule(temp[j], iData[i]);
				

					iData[i]->cur = tempPointer->next;
					//i0가 들어오면 char 앞에 쩜이있는것들을 temp에 저장
					temp[j]->cur = temp[j]->head;
					while (temp[j]->cur->next != NULL) { //.한칸이동

						if (temp[j]->cur->data == '.') {
							temp[j]->cur->data = moveDotOfChar;
							temp[j]->cur->next->data = '.';
							break;
						}
						temp[j]->cur = temp[j]->cur->next;
					}
					j++;
				
				}
				iData[i]->cur = iData[i]->cur->next;
			}

		}
	}
	temp[0]->tail->next->data = j;
	saveigoto->cur = saveigoto->head;

	while (saveigoto->cur->next != NULL) {
		saveigoto->cur = saveigoto->cur->next; //dynamic analy
	}



	saveigoto->cur->iafterNum = closure(ilist, temp, T, rule, ruleNum); // goto(i0 E) = i1 (의 1번이라는 정보 저장
	//i list는 갱신이 되어잇는 상태

}

//now
int closure(iList *ilistx, ruleList **closured, ruleList *T, ruleList **rule, int ruleNum) { //  ix를 넣고 closure할것들을 들여보내면 쩜하나 이동한다음에 ix에 붙인다. S->.E가 들어오면 S->.E, E->E.T ...을 붙이는거
	// input이 ruleList **이 되어야겠는데? now./..
	// closure에 s->E 랑 E->E+T가 들어옴
	int iindex = -1;
	int closuredsize = closured[0]->tail->next->data;
	int t = 0;
	char tracedata = 0;
	int totaltempsize = 0;

	iList *tempSave = (iList*)malloc(sizeof(iList)* 10);
	iListSetting(tempSave);
	

	//임시로 t를보관
	for (int i = 0; i < closuredsize; i++) {
		t = 0;
		closured[i]->cur = closured[i]->head;

		while (closured[i]->cur != NULL) {
			if (closured[i]->cur == closured[i]->tail->next)
				break;

			if (closured[i]->cur->next != NULL){
			if (closured[i]->cur->data == '.' && ifterminal(T, closured[i]->cur->next->data) != 0)
			{
				tracedata = closured[i]->cur->next->data;
				t = CountHead(rule, closured[i]->cur->next->data, T, ruleNum);
			}
			closured[i]->cur = closured[i]->cur->next;
			}
		
		}

		t = t + 1;
		int* saveSize = (int*)malloc(sizeof(int));
		ruleList** temp = (ruleList**)malloc(sizeof(ruleList*)*t);

		RuleListSetting(temp, t);

		CtrlCRule(temp[0], closured[i]);               //closure을 temp에 복사
		AddRule(temp, rule, T, tracedata, ruleNum, t);
		*saveSize = t;
		temp[0]->tail->next->data = saveSize; // *********중요 ruleLsit[0] ->tail->next에다가 크기를 저장함.


		createiNode(tempSave, temp, i);
		printNodes(tempSave->head->iData[0]);
	}
	tempSave->cur = tempSave->head;
	for (int i = 0; i < closuredsize; i++) {
		totaltempsize = totaltempsize + tempSave->cur->iData[0]->tail->next->data;
		tempSave->cur = tempSave->cur->next;
	}
	//tempSave에 두가지가 들어옴.
	ruleList **result = (ruleList**)malloc(sizeof(ruleList*)*totaltempsize);
	RuleListSetting(result, totaltempsize);
	// temp [0] , temp[1] ...들과 비교해서 중복을 없앰.
	tempSave->cur = tempSave->head;//now here
	

	for (int i = 0; i < closuredsize; i++)
	{
		if (tempSave->cur->next != NULL)
			CtrlCList(result, makeListNotSame(tempSave->cur->iData, tempSave->cur->next->iData));

		else if (tempSave->cur->next == NULL) {
			CtrlCList(result, tempSave->cur->iData);
		}

	}

	
	iindex = isiList(ilistx, result);

	//now
	if (iindex == -1) {

		if (ilistx->tail != NULL) {
			createiNode(ilistx, result, (ilistx->tail->iNum) + 1); //i1~ 만들기
			return  ilistx->tail->iNum;
		}
		else if (ilistx->tail == NULL) {
			createiNode(ilistx, result, 0); // i0 만들기
			return 0;
		}

		//create될때 ilistx가 몇번째 인덱스 까지있는지 확인해서 마지막 하나 gotoLIst 3번째 int에 저장.
	}
	else {

		return iindex;
		// save iindex
		// 전역변수는 증가시키지 않고 save 인덱스를 gotoList 3번째 int에 저장.(외부에서)
	}





}
int isiList(iList *ilist, ruleList **contra) {   //return -1 은 같은 인덱스가 없다. 나머지 0~는 같은 인덱스를 반환
	ilist->cur = ilist->head;
	int size = 0;
	int count = 0;
	int ilistindex = 0;
	ilist->cur = ilist->head;
	while (ilist->cur != NULL) {
		//ilist->cur->iData vs contra
		count = 0;


		if (ilist->cur->iData[0]->tail->next->data == contra[0]->tail->next->data) //tail에 next에 size를 보관한다.
		{
			size = ilist->cur->iData[0]->tail->next->data;
			for (int i = 0; i < size; i++) {
				contra[i]->cur = contra[i]->head;
				for (int j = 0; j < size; j++) {
					ilist->cur->iData[j]->cur = ilist->cur->iData[j]->head;

					while (ilist->cur->iData[j]->cur->next != NULL && contra[i]->cur->next != NULL) {

						if (ilist->cur->iData[j]->cur->data != contra[i]->cur->data)
						{
							count++;                                                         // ex 3*3     -> 1 1 0
						}                                                                  //           -> 1 0 1
						ilist->cur->iData[j]->cur = ilist->cur->iData[j]->cur->next;                     //            -> 0 1 1
						contra[i]->cur = contra[i]->cur->next;                                       // 이런식으로 카운트가 size(size-1)만큼 된다면 같은거임.
					}


				}
			}

		}
		if (count == size*(size - 1))
			return ilistindex;

		ilistindex++;
		ilist->cur = ilist->cur->next;

	}

	return -1;

}


void createiNode(iList *L, ruleList **iset, int listnum) {

	iNode* newNode = (iNode*)malloc(sizeof(iNode));
	newNode->iData = iset;
	newNode->next = NULL;
	newNode->iNum = listnum;

	if (L->head == NULL&&L->tail == NULL) {
		L->head = L->tail = newNode;
	}
	else {
		L->tail->next = newNode;
		L->tail = newNode;
	}

}

void createGotoNode(gotoList *L, int ibeforenum, char inputchar, int iafternum) {

	gotoNode *newNode = (gotoNode*)malloc(sizeof(gotoNode));
	newNode->ibefoNum = ibeforenum;
	newNode->inputChar = inputchar;
	newNode->iafterNum = iafternum;
	newNode->next = NULL;


	if (L->head == NULL&&L->tail == NULL) {
		L->head = L->tail = newNode;
	}
	else {
		L->tail->next = newNode;
		L->tail = newNode;
	}


}



void createNode(ruleList *L, char tdata) {
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = tdata;
	newNode->next = NULL;
	newNode->before = NULL;

	if (L->head == NULL&&L->tail == NULL) {
		L->head = L->tail = newNode;
	}
	else {
		if (L->head == L->tail)
			newNode->before = NULL;
		else
			newNode->before = L->tail;

		L->tail->next = newNode;
		L->tail = newNode;
	}


}

void deleteelastNode(ruleList *L) {
	node *p = L->head;
	while (p->next->next != NULL)p = p->next;
	p->next = p->next->next;
	L->tail = p;

}
void printNodes(ruleList *L)
{
	node *p = L->head;
	putchar('[');
	while (p != NULL)
	{
		printf("%c, ", p->data);
		p = p->next;
	}
	putchar(']');
	putchar('\n');

}
void iListSetting(iList *L) {

	L->cur = NULL;
	L->head = NULL;
	L->tail = NULL;

}


void listsetting(ruleList *L) {

	L->cur = NULL;
	L->head = NULL;
	L->tail = NULL;


}

void push(char a) {
	if (STACK_TOP >= STACK_SIZE)
	{
		printf("스택에 쌓을 공간이 없습니다.");
	}
	else {
		stack[STACK_TOP] = a;
		STACK_TOP++;
	}
}
void pop() {
	if (STACK_TOP == 0) {
		printf("스택에 내용물이 없습니다.");
	}
	else {
		stack[STACK_TOP - 1] = 0;
		STACK_TOP--;
	}
}
void sprint() {
	//print 및 stack 초기화.
	int i = 0;
	for (i = 0; i < STACK_SIZE; i++) {
		printf("%c", stack[i]);
		stack[i] = 0;
	}
	printf("\n\n");

	STACK_TOP = 0;
}

void saveListSize(ruleList *L, int listsize){
	L->tail->listsize = listsize;
}
