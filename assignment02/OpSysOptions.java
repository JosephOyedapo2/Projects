package assignment02;

public abstract class OpSysOptions {
	private Option [] options;
	public OpSysOptions(Option... optionsIn) {
		options = optionsIn;
	}
	public Option[] getOptions() {
		return options;
	}
}
