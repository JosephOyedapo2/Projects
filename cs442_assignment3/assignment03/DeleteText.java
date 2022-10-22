package assignment03;

import java.util.ArrayList;

public class DeleteText implements EditCommand {

	private int deleteLine;
	private int deleteColumn;
	private int numChars2delete;
	
	public DeleteText(int deleteLineIn, int deleteColumnIn, int numChars2deleteIn) {
		deleteLine = deleteLineIn;
		deleteColumn = deleteColumnIn;
		numChars2delete = numChars2deleteIn;
	}

	@Override
	public void redo(ArrayList<String> text) {
		// Using the substring(int) and substring(int,int) methods
		// to delete numChars2delete characters from line deleteLine,
		// starting at column deleteColumn. NOTE the first line has
		// deleteLine equal to 0 and the first column has deleteColumn to 0.
		// You will also need text.set(deleteLine, ...) to change the line
		// that has characters deleted.
		String tmp = text.get(deleteLine);
		tmp = tmp.substring(deleteColumn + numChars2delete);
		text.set(deleteLine, tmp);
	}
}
