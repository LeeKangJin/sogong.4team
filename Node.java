
class Node {
	private String text;							// store string text
	private boolean isLcs;
	private boolean isAddedEnter;
	
	Node() {										// initialize
		this.text = null;
		this.isLcs = false;
		this.isAddedEnter = false;
	}
	
	public String getString() {						// get or set string
		return this.text;
	}
	
	public void setString(String oneLine) {
		this.text = oneLine;
	}
	
	public boolean getEnter() {						// get or set enter
		return isAddedEnter;
	}
	
	public void setEnter(boolean addedEnter) {
		this.isAddedEnter = addedEnter;
	}
	
	public boolean getLcs() {						// get or set lcs
		return isLcs;
	}
	
	public void setLcs(boolean lcs) {
		this.isLcs = lcs;
	}
}
