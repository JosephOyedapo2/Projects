package assignment03;

import java.awt.Font;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class DrawTextArea {
	private JFrame frame = new JFrame("Head First Design Patterns");
	private ArrayList<String> text = new ArrayList<>();
	
	public DrawTextArea() throws IOException {
		List<String> lines = Files.readAllLines(Path.of("batteries.txt"));
		for(String line : lines) {
			text.add(line);
		}		
	}

	private void insert(Comp comp) {
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(new JScrollPane(comp));
		frame.setSize(600,600);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);				
	}
	
	class Comp extends JTextArea {
		private static final long serialVersionUID = -3119623605676650073L;
		Comp() {
			this.setFont(new Font("Serif", Font.PLAIN, 24));
			setEditable(false);
		}
		void update() {
			this.setText("");
			for(var line : text) {
				this.append(""+line);
				this.append("\n");
			}
		}
	}

	ArrayList<String> getText() {
		return text;
	}
	
	public static void main(String[] args) throws IOException {	
		DrawTextArea test0 = new DrawTextArea();
		Comp comp0 = test0.new Comp();
		test0.insert(comp0);
		comp0.update();
		test0.frame.setLocation(100, 100);
		
		DrawTextArea test = new DrawTextArea();
		Comp comp = test.new Comp();
		test.insert(comp);
		comp.update();

		// TESTING DeleteLines, DeleteText, InsertLines, InsertText
		EditCommand comm = new InsertText(0,0,"here");
		 comm.redo(test.getText()); // uncomment when comm is not null
		comm = new DeleteText(8,0,3);
		comm.redo(test.getText());
		String[] str = new String[2];
		str[0] = "Test 1";
		str[1] = "Test 2";

		comm = new InsertLines(12, str);
		comm.redo(test.getText());

		comm = new DeleteLines(10,5);
		comm.redo(test.getText());

		comm = new InsertText(10,15,"here");
		comm.redo(test.getText());
		comp.update();

	}
}

