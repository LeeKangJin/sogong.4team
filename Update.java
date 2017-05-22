import java.util.LinkedList;

import javax.swing.JTextArea;

public class Update {
	JTextArea textArea = null;
	LinkedList<Node> list = null;
	
	Update(LinkedList<Node> list, JTextArea textArea) {
		this.list = list;
		this.textArea = textArea;
	}
	
	void areaToList() {
		// textArea strings move to list
		
		
	}
	
	void listToArea() {
		// print list to area
		
		if(list == null) {
			return;
		}
		
		textArea.setText("");
		
		for(int i = 0; i < list.size(); i++) {
			textArea.append(list.get(i).getString() + "\n");
		}
	}
}
