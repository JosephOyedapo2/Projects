package nim;

import static nim.Play.FRUGAL;
import static nim.Play.GREEDY;
import static nim.Play.GUESS;
import static nim.Play.SMART;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

public class PlayView {
	public static final int WIDTH = 600;
	public static final int HEIGHT = 700;
	public static final Font FONT = new Font("Dialog",Font.BOLD, 18); 
	private JFrame frame = new JFrame("One-pile NIM subtraction game (mis\u00E8re game). Remove up to half of pile");
	private StickPanel stickPanel; 
	private Nim nim;
	private JLabel humanTurn = new JLabel("Human Turn", JLabel.CENTER);
	private JLabel computerTurn = new JLabel("Computer Turn", JLabel.CENTER);
	private JLabel humanPrompt = new JLabel("Human takes? ", JLabel.RIGHT);
	private JLabel computerTake = new JLabel("Computer: ", JLabel.RIGHT);
	private JLabel computerAmount = new JLabel("");
	private JTextField humanEntry = new JTextField();
	private int numSticks;
	private Timer timer = new Timer(3000, this::computerTurn);
	private PlayState state = PlayState.HUMAN_TURN; 
	
	public enum PlayState {
		COMPUTER_TURN, HUMAN_TURN
	}
	
	public void switchState() {
		if(state == PlayState.COMPUTER_TURN) state = PlayState.HUMAN_TURN;
		else state = PlayState.COMPUTER_TURN;
		update();
		
		if (state == PlayState.COMPUTER_TURN) timer.restart();
		else timer.stop();
	}

	public void computerTurn(ActionEvent e) {
		nim.takeTurn();
	}

	public void update() {
		switch(state) {
		case COMPUTER_TURN: 
			computerTurn.setBackground(Color.WHITE);
			humanTurn.setBackground(Color.GRAY);
			humanEntry.setEnabled(false);
			humanPrompt.setBackground(Color.GRAY);
			computerTake.setBackground(Color.WHITE);
			computerAmount.setBackground(Color.WHITE);				
			break;
		case HUMAN_TURN:
			computerTurn.setBackground(Color.GRAY);
			humanTurn.setBackground(Color.WHITE);
			humanEntry.setEnabled(true);
			humanPrompt.setBackground(Color.WHITE);
			computerTake.setBackground(Color.GRAY);
			computerAmount.setBackground(Color.GRAY);
		}
		stickPanel.repaint();
	}

	public int getNumSticks() {
		return numSticks;
	}
	public void setNumSticks(int numSticksIn) {
		numSticks = numSticksIn;
		if(numSticks == 0) nim.announceResult(state);
	}
	public void setComputerAmount(int numSticksTaken) {
		computerAmount.setText("" + numSticksTaken);
	}

	public PlayView(int numSticksIn, Nim nimIn) {
		nim = nimIn;
		numSticks = numSticksIn;
		stickPanel = new StickPanel(this);
		JMenuBar bar = new JMenuBar();
		populateBar(bar);
		// Note: I wanted to change the font of the title "NIM" but it is a lot of work:
		// it needs:
		// - turning off the outer rim of the frame, 
		// - adding JLabel with the correct font at the top
		// - setting the font of that JLabel
		// - adding a JPanel below the JLabel
		// - adding a Menu in the top of that last JPanel instead 
		//   of setting the menu bar of the frame
		// - see 
		// - https://stackoverflow.com/questions/42925151/how-can-i-change-the-font-of-the-jframes-title
		// - https://stackoverflow.com/questions/4299846/add-jmenubar-to-a-jpanel
		frame.setJMenuBar(bar);
		frame.setSize(WIDTH, HEIGHT);
		frame.add(stickPanel);
		frame.add(createInputArea(), BorderLayout.PAGE_END);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
	}

	void populateBar(JMenuBar bar) {
		JMenu menu = new JMenu("Strategies");
		menu.setFont(FONT);
		JMenuItem frugal = new JMenuItem("Frugal");
		frugal.addActionListener(e -> nim.setComputer(FRUGAL));
		frugal.setFont(FONT);
		menu.add(frugal);
		JMenuItem greedy = new JMenuItem("Greedy");
		frugal.addActionListener(e -> nim.setComputer(GREEDY));
		greedy.setFont(FONT);
		menu.add(greedy);
		JMenuItem guess = new JMenuItem("Guess");
		frugal.addActionListener(e -> nim.setComputer(GUESS));
		guess.setFont(FONT);
		menu.add(guess);
		JMenuItem smart = new JMenuItem("Smart");
		frugal.addActionListener(e -> nim.setComputer(SMART));
		smart.setFont(FONT);
		menu.add(smart);
		bar.add(menu);
	}

	JPanel createInputArea() {
		JPanel panel = new JPanel();
		panel.setLayout(new GridLayout(0,2));
		panel.add(humanTurn);
		humanTurn.setFont(FONT);
		humanTurn.setOpaque(true);
		panel.add(computerTurn);
		computerTurn.setFont(FONT);
		computerTurn.setOpaque(true);
		JPanel innerLeft = new JPanel();
		innerLeft.setLayout(new GridLayout(0,2));

		humanPrompt.setFont(FONT);
		humanPrompt.setOpaque(true);
		innerLeft.add(humanPrompt);
		humanEntry.setFont(FONT);
		humanEntry.setOpaque(true);
		innerLeft.add(humanEntry);
		JPanel innerRight = new JPanel();
		panel.add(innerLeft);

		humanEntry.addActionListener(this::action);

		innerRight.setLayout(new GridLayout(0,2));
		computerTake.setFont(FONT);
		computerTake.setOpaque(true);
		innerRight.add(computerTake);
		computerAmount.setFont(FONT);
		computerAmount.setOpaque(true);		
		innerRight.add(computerAmount);
		panel.add(innerRight);
		update();
		return panel;
	}

	public void action(ActionEvent e) {
		int numberToTake = -1;
		String str = humanEntry.getText();
		Scanner input = new Scanner(str);
		if(input.hasNextInt()){
			numberToTake = input.nextInt();
			if ((numSticks != 1 && (numberToTake < 1 || numberToTake > numSticks/2))
					|| (numSticks == 1 && numberToTake != 1)) {	
				numberToTake = -1;
				JOptionPane.showMessageDialog(null, 
						"You can only take between\n" +
								"1 and " + (numSticks == 1 ? 1 : numSticks/2) + " sticks from the pile");
			}
		}
		else{
			JOptionPane.showMessageDialog(null, 
					"You did not enter an integer");
		}
		if(numberToTake > 0) {
			System.out.println(numberToTake);
			numSticks -= numberToTake;
			if(numSticks == 0) nim.announceResult(state);
			stickPanel.repaint();
			switchState();
			humanEntry.setText(""); 
		}
	}

}
