package assignment02;

public class TestDrive {

	public static void main(String[] args) {
		Configurator HPtest = new Configurator(new HPEnvyConfigFactory());
		String order = HPtest.makeOrder();
	}

}
