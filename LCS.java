package merge;

import java.util.LinkedList;
public class LCS {
	private int[][] LCS_table;
	private int LCS_length;
	
	// 두 LinkedList 간의 LCS table 계산 
	public void makeTable(LinkedList<Node> L1,LinkedList<Node> L2) {
		int len1 = L1.size();
		int len2 = L2.size();
		
		// set the table
		this.LCS_table = new int[len1][len2];
		for(int i = 0; i < len1; i++)
			LCS_table[0][i] = 0;
		
		//Calculation table index and LCS length
		int max;
		for(int i = 1; i < len2; i++){
			max = 0;
			LCS_table[i][0] = 0;
			for(int j = 1; j < len1; j++){
				// 두 노드의 string 비교
				if(L1.get(j).getString().equals(L2.get(i).getString())){
					max = LCS_table[i-1][j-1] + 1;
					LCS_table[i][j] = max;
				}
				else{
					if(LCS_table[i][j-1] > LCS_table[i-1][j])
						LCS_table[i][j] = LCS_table[i][j-1];
					else
						LCS_table[i][j] = LCS_table[i-1][j];
				}
			}
			if(LCS_length < max)
				LCS_length = max;
		}
		
	}
	// 두 노드간의 LCS table 계산
	public void makeTable(Node N1,Node N2) {
		int len1 = N1.getString().length();
		int len2 = N2.getString().length();
		
		// set the table
		this.LCS_table = new int[len1][len2];
		for(int i = 0; i < len1; i++)
			LCS_table[0][i] = 0;
		
		//Calculation table index and LCS length
		int max;
		for(int i = 1; i < len2; i++){
			max = 0;
			LCS_table[i][0] = 0;
			for(int j = 1; j < len1; j++){
				
				// 두 노드의 문자열의 문자비교
				if(N1.getString().charAt(j) == N2.getString().charAt(i)){
					max = LCS_table[i-1][j-1] + 1;
					LCS_table[i][j] = max;
				}
				else{
					if(LCS_table[i][j-1] > LCS_table[i-1][j])
						LCS_table[i][j] = LCS_table[i][j-1];
					else
						LCS_table[i][j] = LCS_table[i-1][j];
				}
			}
			if(LCS_length < max)
				LCS_length = max;
		}
		
	}
	
	// 두 LinkedList간의 LCS 계산
	public void calcLCS(LinkedList<Node> L1, LinkedList<Node> L2){
		
		int len1 = L1.size();
		int len2 = L2.size();
		int temp = this.LCS_length;
		int for_j = len1 - 1;
		 
		  //Calculation LCS
		  for (int i = len2-1; i >0; i--) {
		    for (int j = for_j; j > 0; j--) {
		      if (this.LCS_table[i][j] == temp && this.LCS_table[i][j - 1] == temp - 1 
		    		  && this.LCS_table[i - 1][j - 1] == temp - 1 && this.LCS_table[i - 1][j] == temp - 1) {
		        temp--;
		        L1.get(j).setIsLCS(true);
		        L2.get(i).setIsLCS(true);
		        for_j = j;
		        break;
		      }
		    }
		  }
		  this.LCS_table = null;
	}
	
	// 두 node간의 LCS 계산
	public void calcLCS(Node N1, Node N2){
		
		int len1 = N1.getString().length();
		int len2 = N2.getString().length();
		
		int temp = this.LCS_length;
		int for_j = len1 - 1;
		 
		  //Calculation LCS
		  for (int i = len2-1; i >0; i--) {
		    for (int j = for_j; j > 0; j--) {
		      if (this.LCS_table[i][j] == temp && this.LCS_table[i][j - 1] == temp - 1 
		    		  && this.LCS_table[i - 1][j - 1] == temp - 1 && this.LCS_table[i - 1][j] == temp - 1) {
		        temp--;
		        N1.addString_index(j);
		        N2.addString_index(i);
		        for_j = j;
		        break;
		      }
		    }
		  }
		  this.LCS_table = null;
	}
	
	public LCS(){
		this.LCS_length = 0;
		this.LCS_table = null;
	}
	
	
	
}
