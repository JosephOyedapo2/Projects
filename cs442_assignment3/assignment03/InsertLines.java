package assignment03;

import java.util.ArrayList;

public class InsertLines implements EditCommand {

	private int insertLine;
	private String[] lines;
	
	public InsertLines(int insertLineIn, String[] linesIn) {
		insertLine = insertLineIn;
		lines = linesIn;
	}

	@Override
	public void redo(ArrayList<String> text) {
		// insert the lines in the array "lines" starting the insertion
		// at insertLine. NOTE the line count starts at 0, so if insertLine
		// is 0, then the "lines" are inserted at the top of the tex
		for (String line : lines) {
			text.add(insertLine, line);
			insertLine += 1;
		}
	}
}
