package assignment03;

import java.util.ArrayList;

public class DeleteLines implements EditCommand {

	private int deleteLine;
	private int numLines2delete;
	
	public DeleteLines(int deleteLineIn, int numLines2deleteIn) {
		deleteLine = deleteLineIn;
		numLines2delete = numLines2deleteIn;
	}

	@Override
	public void redo(ArrayList<String> text) {
		// remove numLines2delete lines starting from deleteLine
		// NOTE the line count starts at 0--to delete the first line
		// use deleteLine equal to 0
		for (int i = 0; i < numLines2delete; i++) {
			text.remove(deleteLine);
			deleteLine += 1;
		}
	}
}
