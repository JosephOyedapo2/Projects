package assignment02;

public abstract class RamOptions {
	private Option [] options;
	public RamOptions(Option... optionsIn) {
		options = optionsIn;
	}
	public Option[] getOptions() {
		return options;
	}
}
