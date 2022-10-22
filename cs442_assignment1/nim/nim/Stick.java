package nim;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.util.Random;

public class Stick {
	private double lowx;
	private double lowy;
	private double hix;
	private double hiy;
	private Color color;
	private double angle;
	private Random random = new Random();

	public Stick(Color color) {
		this.color = color;
		throwStick();
	}
	public void throwStick() {
		lowx = Math.round(200+200*random.nextDouble());
		lowy = Math.round(100+200*random.nextDouble());
		angle = 180*random.nextDouble();
		hix = Math.round(lowx + 200*Math.cos(Math.toRadians(angle)));
		hiy = Math.round(lowy + 200*Math.sin(Math.toRadians(angle)));
	}
	public void draw(Graphics2D g) {
		Color col = g.getColor();
		g.setColor(color);
		Line2D.Double line = new Line2D.Double(lowx,lowy,hix,hiy);
		g.draw(line);
		g.setColor(col);
		
	}
}
