package assignment02;

public abstract class PowerSupplyOptions {
	private Option [] options;
	public PowerSupplyOptions(Option... optionsIn) {
		options = optionsIn;
	}
	public Option[] getOptions() {
		return options;
	}
}
