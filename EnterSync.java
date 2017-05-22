package compare;
import java.util.LinkedList;
public class EnterSync {
	
	public void enterSync(LinkedList<node> L1, LinkedList<node> L2){
		node enterNode;
		for(int i = 0; i < L1.size() || i < L2.size(); i++){
			//두 리스트간에 같은 문자열은 같은 위치에 가도록 enter노드 삽입
			if(L1.get(i).getIsLCS() && !L2.get(i).getIsLCS()){
				//노드를 새로 생성하여 String에 "\n"를, isAddedEnter를 true로 만든다.
				enterNode = new node("\n",true);
				L1.add(i,enterNode);
				enterNode = null;
			}
			else if(!L1.get(i).getIsLCS() && L2.get(i).getIsLCS()){
				enterNode = new node("\n",true);
				L2.add(i,enterNode);
				enterNode = null;
			}
			//두 리스트의 길이를 맞추기 위해 enter노드 삽입
			if(i == L1.size() && i < L2.size()){
				enterNode = new node("\n",true);
				L1.add(i,enterNode);
				enterNode = null;
			}
			else if(i < L1.size() && i == L2.size()){
				enterNode = new node("\n",true);
				L2.add(i,enterNode);
				enterNode = null;
			}
		}
	}
}
