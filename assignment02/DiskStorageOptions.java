package assignment02;

public abstract class DiskStorageOptions {
	private Option[] options;
	public DiskStorageOptions(Option... optionsIn) {
		options = optionsIn;
	}
	public Option[] getOptions() {
		return options;
	}
}
