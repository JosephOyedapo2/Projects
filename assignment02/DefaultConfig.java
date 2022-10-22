package assignment02;

public abstract class DefaultConfig {
	private String description;
	private double price;
	private String partNumber;
	public DefaultConfig(String descriptionIn, double priceIn, String partNumberIn) {
		description = descriptionIn;
		price = priceIn;
		partNumber = partNumberIn;
	}
	public String getDescription() {
		return description;
	}
	public double getPrice() {
		return price;
	}
	public String getPartNumber() {
		return partNumber;
	}
}
