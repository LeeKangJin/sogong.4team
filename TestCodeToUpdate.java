import java.util.LinkedList;

import javax.swing.JFrame;
import javax.swing.JTextArea;

public class TestCodeToUpdate {
	public static void main(String[] args) {
		LinkedList<Node> list = null;
		JTextArea textArea = null;
		
		TestCodeToUpdate test = new TestCodeToUpdate();
		textArea = test.makeWindow();
		
		Load load = new Load();
		load.openPopup();
		load.loadFromFile();																			// load file
		
		list = load.getList();
		
		Update update = new Update(list, textArea);
		update.listToArea();
	}
	
	public JTextArea makeWindow() {
		JFrame frame = new JFrame("TestToUpdate");
		JTextArea textArea = new JTextArea(50,50);
		textArea.setEditable(false);
		
		frame.add(textArea);
		frame.pack();
		frame.setVisible(true);
		
		return textArea;
	}
}
