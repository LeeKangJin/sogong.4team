
import java.util.LinkedList;
 
public class merge {	
	public void copytoright(LinkedList<node> node1, LinkedList<node> node2){
		int length = node1.size();		
		for(int i = 0; i < length; i++){
			if((node1.get(i).getisDiff() == true)){
				node2.get(i).setString(node1.get(i).getString());
			}
		}
	}
	public void copytoleft(LinkedList<node> node1, LinkedList<node> node2){
		int length = node1.size();		
		for(int i = 0; i < length; i++){
			if((node2.get(i).getisDiff() == true)){
				node1.get(i).setString(node2.get(i).getString());
			}
		}
	}
 
}