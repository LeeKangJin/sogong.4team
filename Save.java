import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;

import javax.swing.JFileChooser;

public class Save {
	private LinkedList<Node> saveList = null;
	private File fileName = null;
	
	Save(LinkedList<Node> stringList) {							// initialize
		this.saveList = stringList;
	}
	
	void saveToFile() {
		if(fileName == null) {
			return;
		}
		
		try {
			BufferedWriter out = new BufferedWriter(new FileWriter(fileName));
			
			for(int i = 0; i < saveList.size(); i++) {								// write file until EOF
				if(saveList.get(i).getEnter()) {									// if boolean enter is true, continue
					continue;
				}
				
				out.write(saveList.get(i).getString());								// write oneLine to file
				out.newLine();														// make newLine
			}
			
			out.close();
		} catch(IOException e) {
			System.out.println("Error : IOException");
		}
	}
	
	void openPopup() {
		JFileChooser chooser = new JFileChooser();
		chooser.setDialogTitle("save");
		
		int returnValue = chooser.showOpenDialog(null);
		
		if(returnValue == JFileChooser.APPROVE_OPTION) {
			fileName = chooser.getSelectedFile();
		}
		
		else {
			System.out.println("Cancel File Select");
		}
	}
}
