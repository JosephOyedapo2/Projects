package assignment02;

public abstract class GraphicsCardOptions {
	private Option[] options;
	public GraphicsCardOptions(Option... optionsIn) {
		options = optionsIn;
	}
	public Option[] getOptions() {
		return options;
	}
}
