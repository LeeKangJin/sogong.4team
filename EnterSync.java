package compare;
import java.util.LinkedList;
public class EnterSync {
	
	public void enterSync(LinkedList<node> L1, LinkedList<node> L2){
		node enterNode;
		for(int i = 0; i < L1.size() || i < L2.size(); i++){
			//�� ����Ʈ���� ���� ���ڿ��� ���� ��ġ�� ������ enter��� ����
			if(L1.get(i).getIsLCS() && !L2.get(i).getIsLCS()){
				//��带 ���� �����Ͽ� String�� "\n"��, isAddedEnter�� true�� �����.
				enterNode = new node("\n",true);
				L1.add(i,enterNode);
				enterNode = null;
			}
			else if(!L1.get(i).getIsLCS() && L2.get(i).getIsLCS()){
				enterNode = new node("\n",true);
				L2.add(i,enterNode);
				enterNode = null;
			}
			//�� ����Ʈ�� ���̸� ���߱� ���� enter��� ����
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
