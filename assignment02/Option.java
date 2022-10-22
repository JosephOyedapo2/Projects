package assignment02;

public record Option(String desription, double costAddition, String partNumber) {
	public String toString() {
		return String.format("%s %.2f", desription, costAddition, partNumber);
	}
}
