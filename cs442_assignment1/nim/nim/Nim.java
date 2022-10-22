package nim;

import javax.swing.JOptionPane;

public class Nim {
	private Play computer = Play.SMART;
	private PlayView playView;

	public void setComputer(Play computerIn) {
		computer = computerIn;
	}

	public static void announceResult(PlayView.PlayState state) {
		if(state == PlayView.PlayState.HUMAN_TURN) {
			JOptionPane.showMessageDialog(null, "You lost");
		} else {
			JOptionPane.showMessageDialog(null, "You won");			
		}
		System.exit(0);
	}

	public static void main(String[] args) {		
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				Nim nim = new Nim();
				int currentState = 10 + (int)(90*Math.random());
				nim.playView = new PlayView(currentState, nim);
			}
		});
	}

	public void takeTurn() {
		int numSticks = playView.getNumSticks();
		int numToTake = computer.takeTurn(numSticks);
		playView.setNumSticks(numSticks - numToTake);
		playView.setComputerAmount(numToTake);
		playView.switchState();
	}		
}
