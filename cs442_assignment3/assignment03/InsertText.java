  package assignment03;

import java.util.ArrayList;

import assignment03.EditCommand;

public class InsertText implements EditCommand {

	private final int insertLine;
	private final int insertColumn;
	private final String insertText;
	
	public InsertText(int insertLineIn, int insertColumnIn, String insertTextIn) {
		insertLine = insertLineIn;
		insertColumn = insertColumnIn;
		insertText = insertTextIn;
	}

	@Override
	public void redo(ArrayList<String> text) {
		// Insert "insertText" in line "insertLine" starting at column
		// "insertColumn".
		// Using the substring(int) and substring(int,int) methods
		// to break up the insertLine and insert the "insertText" String
		// between these left and right parts of the line to form a new String. 
		// You need text.set(deleteLine, ...) to change the line
		// that has characters inserted. NOTE that line and column numbers
		// are counted from 0. For example new InsertText(0,0,"ABC") inserts
		// "ABC" at the very beginning of text.
		String tmp = text.get(insertColumn);
		String insert = tmp.substring(0, insertLine);
		String end = tmp.substring(insertLine, tmp.length());
		String ret = insert + insertText + end;
		text.set(insertColumn, ret);
	}
}
