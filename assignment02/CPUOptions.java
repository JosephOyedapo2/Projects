package assignment02;

public abstract class CPUOptions {
	private Option[] options;
	public CPUOptions(Option... optionsIn) {
		options = optionsIn;
	}
	public Option[] getOptions() {
		return options;
	}
}
