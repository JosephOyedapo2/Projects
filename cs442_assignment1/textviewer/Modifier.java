package textviewer;
/**
 * @author CS 442 / CS 542
 */
public interface Modifier {
	public Block[][] modify(Block[][] blocks, int width);
	Modifier FULL = new FullModifier();
	Modifier LEFT = new LeftModifier();
	Modifier RIGHT = new RightModifier();
	Modifier CENTER = new CenterModifier();
}
