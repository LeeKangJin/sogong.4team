package compare;
import java.util.LinkedList;

public class compare {
	
	private LCS LCS_checker;
	
	public void compareList(LinkedList<node> L1, LinkedList<node> L2){
		for(int i = 0; i < L1.size()/*이 시점에서 두 리스트의 사이즈가 같아야 한다.*/; i++){
			LCS_checker = new LCS();
			LCS_checker.makeTable(L1.get(i), L2.get(i));
			LCS_checker.calcLCS(L1.get(i), L2.get(i));
			LCS_checker = null;
			
		}
	}
	
}
