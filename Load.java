import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;

import javax.swing.JFileChooser;

class Load {
	private LinkedList<Node> loadList = null;
	private File fileName = null;
	
	Load() {														// initialize
		loadList = new LinkedList<Node>();
	}
	
	void loadFromFile() {
		if(fileName == null) {
			return;
		}
		
		try {
			BufferedReader in = new BufferedReader(new FileReader(fileName));
			String oneLine = null;
			
			
			while((oneLine = in.readLine()) != null) {							// read each line until EOF
				Node oneLineNode = new Node();
				oneLineNode.setString(oneLine);
				
				loadList.add(oneLineNode);
			}
			
			in.close();
		} catch(IOException e) {
			System.out.println("Error : IOException");
		}
	}
	
	LinkedList<Node> getList() {												// return LinkedList
		return loadList;
	}
	
	File getFileName() {
		return fileName;
	}
	
	void openPopup() {
		JFileChooser chooser = new JFileChooser();
		chooser.setDialogTitle("load");
		
		int returnValue = chooser.showOpenDialog(null);
		
		if(returnValue == JFileChooser.APPROVE_OPTION) {
			fileName = chooser.getSelectedFile();
		} else {
			System.out.println("Cancel File Select");
		}
	}
}
