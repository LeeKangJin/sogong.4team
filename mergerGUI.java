package fefe;
import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import java.awt.FlowLayout;

import javax.swing.JButton;

import java.awt.GridLayout;
import java.awt.Color;

import javax.swing.JCheckBox;
import javax.swing.JProgressBar;
import javax.swing.JRadioButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JLabel;

import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;

import javax.swing.JEditorPane;
import javax.swing.JTextArea;
import javax.swing.JTabbedPane;
import javax.swing.JSplitPane;
import javax.swing.JToggleButton;
import javax.swing.JTextField;
import javax.swing.JList;
import javax.swing.JScrollBar;
import javax.swing.ScrollPaneConstants;
import javax.swing.SwingConstants;
import javax.swing.DropMode;

import java.awt.Component;
import java.awt.Rectangle;
import java.awt.Dimension;

import javax.swing.JScrollPane;
import javax.swing.JComboBox;
import javax.swing.BoxLayout;
import javax.swing.Box;

public class mergerGUI extends JFrame {
 private JPanel contentPane;	
        static boolean edit1 = false;
	static boolean edit2 = false;
	
 /**
  * Launch the application.
  */
 public static void main(String[] args) {
  EventQueue.invokeLater(new Runnable() {
   public void run() {
    try {
     mergerGUI frame = new mergerGUI();
     frame.setVisible(true);
    } catch (Exception e) {
     e.printStackTrace();
    }
   }
  });
 }
 /**
  * Create the frame.
  */
 public mergerGUI() {

  //create frame	 
  setBackground(Color.WHITE);
  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  setBounds(100, 100,1500,800);
  setResizable(false);
  contentPane = new JPanel();
  contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
  contentPane.setLayout(new BorderLayout(0, 0));
  setContentPane(contentPane);
  //create panel (up)
  JPanel panel = new JPanel();
  contentPane.add(panel, BorderLayout.NORTH);
  panel.setLayout(new GridLayout(0, 3, 0, 0));
  
  JPanel panel_1 = new JPanel();
  panel.add(panel_1);
  panel_1.setLayout(new GridLayout(0, 3, 0, 0));
  //create left-up button
  JButton btnNewButton_5 = new JButton("load");
  panel_1.add(btnNewButton_5);
  
  btnNewButton_5.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	      //Do it
	    }
	});

  JButton btnNewButton = new JButton("edit");
  panel_1.add(btnNewButton);
  

  JButton btnNewButton_3 = new JButton("save");
  panel_1.add(btnNewButton_3);
  btnNewButton_3.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	      //Do it
	    }
	});
 
  JPanel panel_2 = new JPanel();
  panel.add(panel_2);
  
  JPanel panel_4 = new JPanel();
  panel.add(panel_4);
  panel_4.setLayout(new GridLayout(0, 3, 0, 0));
  //create right -up button
  JButton btnNewButton_1 = new JButton("load");
  panel_4.add(btnNewButton_1);
  btnNewButton_1.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	      //Do it
	    }
	});
  JButton btnNewButton_2 = new JButton("edit");
  panel_4.add(btnNewButton_2);

  JButton btnNewButton_4 = new JButton("save");
  panel_4.add(btnNewButton_4);
  btnNewButton_4.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	      //Do it
	    }
	});
  JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
  contentPane.add(tabbedPane, BorderLayout.WEST);
  
  JTabbedPane tabbedPane_1 = new JTabbedPane(JTabbedPane.TOP);
  contentPane.add(tabbedPane_1, BorderLayout.EAST);
  
  JPanel panel_3 = new JPanel();
  contentPane.add(panel_3, BorderLayout.CENTER);
  panel_3.setLayout(new BoxLayout(panel_3, BoxLayout.X_AXIS));
  
   // create  left text area 
   JTextArea textArea_2 = new JTextArea(10,50);
    panel_3.add(textArea_2);
    textArea_2.setEditable(false);
   
    btnNewButton.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	    
	    	edit1=!edit1;
	    	textArea_2.setEditable(edit1);

	    }
	});
    textArea_2.setLineWrap(true);
   JScrollPane scrollPane = new JScrollPane(textArea_2);
  
   scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);
   scrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

   getContentPane().add(BorderLayout.CENTER,panel_3);

   panel_3.add(scrollPane);
 
  
  JPanel panel_5 = new JPanel();
  panel_5.setPreferredSize(new Dimension(14, 39));
  panel_3.add(panel_5);
  panel_5.setLayout(new BorderLayout(0, 0));
  
  JPanel panel_6 = new JPanel();
  panel_5.add(panel_6, BorderLayout.NORTH);
  panel_6.setLayout(new GridLayout(0, 1, 0, 0));
  //create center button (compare & merge)
  JButton btnNewButton_6 = new JButton("compare");
  panel_6.add(btnNewButton_6);
  btnNewButton_6.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	      //Do it
	    }
	});
  JPanel panel_7 = new JPanel();
  panel_5.add(panel_7, BorderLayout.CENTER);
  panel_7.setLayout(new GridLayout(1, 0, 0, 0));
  
  JButton btnNewButton_7 = new JButton("<-");
  panel_7.add(btnNewButton_7);
  btnNewButton_7.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	      //Do it
	    }
	});
  JButton btnNewButton_8 = new JButton("->");
  panel_7.add(btnNewButton_8);
  btnNewButton_8.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	      //Do it
	    }
	});
  // create right textarea
  JTextArea textArea = new JTextArea(10,50);
  panel_3.add(textArea);
  textArea.setEditable(false);
  btnNewButton_2.addActionListener(new ActionListener() {
	    public void actionPerformed(ActionEvent e) {
	    
	    	edit2= !edit2;
	    	textArea.setEditable(edit2);
	    }
	});
  textArea.setLineWrap(true);
  JScrollPane scrollPane2 = new JScrollPane(textArea);
  scrollPane2.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);
  scrollPane2.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
  getContentPane().add(BorderLayout.CENTER,panel_3);
  panel_3.add(scrollPane2);
 }
}
 
