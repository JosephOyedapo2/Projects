package nim;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JPanel;
import static java.awt.Color.*;
import static nim.PlayView.FONT;

public class StickPanel extends JPanel {
	private static final long serialVersionUID = -3431414751840044608L;
	private static final BasicStroke wideStroke = new BasicStroke(8);
	private Stick[] sticks;
	private PlayView playView;
	private Color[] colors = {YELLOW, RED, WHITE, CYAN, GREEN, MAGENTA, 
			ORANGE, PINK, BLUE};
	// Omit ALL GRAY and BLACK
	// NOTE THAT import static java.awt.Color.*;
	// allows use to write BLUE instead of Color.BLUE, etc.

	public StickPanel(PlayView playViewIn) {
		playView = playViewIn;
		int numSticks = playView.getNumSticks();
		if(numSticks > 0) {
			sticks = new Stick[numSticks];
			int colorIndex = 0;
			for(int i = 0; i < sticks.length; i++) {
				sticks[i] = new Stick(colors[colorIndex++%colors.length]);
			}
		}
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(BLACK);
		g.fillRect(0, 0, getWidth(), getHeight());
		Graphics2D graphics = (Graphics2D)g;
		graphics.setStroke(wideStroke);
		int numSticks = playView.getNumSticks();
		if (sticks != null) {
			for(int i = 0; i < numSticks; i++)	{
				sticks[i].draw(graphics);
			}
		}
		graphics.setColor(WHITE);
		graphics.setFont(FONT);
		graphics.drawString("#Sticks = " + numSticks, 10, 30);
	}	

}
