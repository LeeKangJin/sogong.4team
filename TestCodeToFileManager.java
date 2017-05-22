import java.util.LinkedList;

public class TestCodeToFileManager {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList<Node> originList = null;
		
		Load load = new Load();
		load.openPopup();
		load.loadFromFile();																			// load file
		
		originList = load.getList();																	// get list
		
		for(int i = 0; i < originList.size(); i++) {													// print all lines
			System.out.println(originList.get(i).getString());
		}
		
		Node node = new Node();																			// input test node
		node.setString("testString");
		
		originList.add(node);
		
		Save save = new Save(originList);
		save.openPopup();
		save.saveToFile();																				// save file
		
		originList = null;
	}
}
