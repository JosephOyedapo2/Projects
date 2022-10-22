package assignment02;

public class Configurator {
	private ComputerConfigFactory factory;
	
	
	public Configurator(ComputerConfigFactory factoryIn) {
		factory = factoryIn;
	}

	String makeOrder() {

		System.out.println("Select CPU");
		String getCPUString = factory.nextLine();
		System.out.println( factory.createCPUOptions());

		System.out.println("Select GPU");
		String getGPUString = factory.nextLine();
		System.out.println( factory.createGraphicsCardOptions());

		System.out.println("Select Disk size");
		String getDiskString = factory.nextLine();
		System.out.println( factory.createDiskStorageOptions());

		System.out.println("Select PSU");
		String getPSUstring = factory.nextLine();
		System.out.println( factory.createPowerSupplyOptions());

		System.out.println("Select OS");
		String getOString = factory.nextLine();
		System.out.println( factory.createOpSysOptions());

		System.out.println("Select OS");
		String getRAMString = factory.nextLine();
		System.out.println( factory.createRamOptions());


		return CPUOptions.CPUOptionsHPEnvy + HPTest.getGPUString + HPTest.getDiskString + HPTest.getPSUstring +
		HPTest.getOString + HPTest.getRAMString;
		
		return "";
	}
}
// return CPUOptions.CPUOptionsHPEnvy() + GraphicsCardOptions.GraphicsCardOptionsHPEnvy() + DiskStorageOptions.DiskStorageOptionsHPEnvy() 
// + PowerSupplyOptions.PowerSupplyOptionsHPEnvy() + OpSysOptions.OpSysOptionsHPEnv() + 
// RamOptions.RamOptionsHPEnvy();
