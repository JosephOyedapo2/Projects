package assignment02;

public class HPEnvyConfigFactory extends ComputerConfigFactory {
	DefaultConfig createDefaultConfig() {
		return new HPEnvyConfig("HP ENVY Desktop TE02-0250xt PC", 1299.99, "TE02-0250xt");
	}
	CPUOptions createCPUOptions() {
		return new CPUOptionsHPEnvy(
				new Option("Intel(TM) Core(TM) i5-12400 W/Air Cooler "
						+ "\n\t(2.5 GHz up to 4.4 GHz, 18 MB L3 cache, 6 cores)", 0.0, "ICi512400"),
				new Option("Intel(TM) Core(TM) i7-12700 W/Air Cooler"
						+ "\n\t(2.1 GHz up to 4.9 GHz, 25 MB L3 cache, 12 cores)", 160.0, "ICi712700"));
	}
	OpSysOptions createOpSysOptions() {
		new Option("Windows 11 Home", 0.0, "MSW11H"),
		new Option("Windows 11 Pro", 70.0, "MSW11P")
	}
	RamOptions createRamOptions() {
		new Option("8 GB DDR4-3200 MHz RAM (1 x 8 GB)", -780.0, "DDRram8gb"), 
		new Option("16 GB DDR4-3200 MHz RAM (2 x 8 GB)", -710.0, "DDRram16gb"), 
		new Option("32 GB DDR4-3200 MHz RAM (2 x 16 GB)", -580.0, "DDRram32gb"), 
		new Option("128 GB DDR4-3200 MHz RAM (4 x 32 GB)", 0.0, "DDRram128gb")
	}
	DiskStorageOptions createDiskStorageOptions() {
		new Option("256 GB PCIe(TM) NVMe(TM) M.2 SSD", 0.0,"SSD256"),
		new Option("512 GB PCIe(TM) NVMe(TM) M.2 SSD", 60.0,"SSD512"),
		new Option("1 TB PCIe(TM) NVMe(TM) M.2 SSD", 170.0,"SSD1000")
	}
	GraphicsCardOptions createGraphicsCardOptions() {
		return new GraphicsCardOptionsHPEnvy (
				new Option("NVIDIA(TM) GeForce RTX(TM) 3050 "
						+ "\n\t(8 GB GDDR6 dedicated)", 0.0, "NVID3050"),
				new Option("NVIDIA(TM) GeForce RTX(TM) 3060 "
						+ "\n\t(12 GB GDDR6 dedicated) with LHR, Display Connectors: HDMI*1, DP*3", 60.0, "NVID3060"),
				new Option("AMD Radeon(TM) RX 6600XT Graphics "
						+ "\n\t(8 GB GDDR6 dedicated), Display Connectors: DP*3, HDMI*1", 170.0, "AMD6600"),
				new Option("NVIDIA(TM) GeForce RTX(TM) 3060 Ti "
						+ "\n\t(8 GB GDDR6 dedicated) with LHR, Display Connectors: DP*3, HDMI*1", 170.0, "NVIDTi3060LHR"),
				new Option("NVIDIA(TM) GeForce RTX(TM) 3070 "
						+ "\n\t(8 GB GDDR6 dedicated) with LHR, Display Connectors: DP*3, HDMI*1", 270.0, "NVID3070LHR"),
				new Option("AMD Radeon(TM) RX 6700XT Graphics "
						+ "\n\t(12 GB GDDR6 dedicated), Display Connectors: DP*3, HDMI*1", 270.0, "AMD6700"),
				new Option("NVIDIA(TM) GeForce RTX(TM) 3070 Ti "
						+ "\n\t(8 GB GDDR6X dedicated) with LHR, Display Connectors: HDMI*1, DP*3", 420.0, "NVIDTi3070LHR"),
				new Option("NVIDIA(TM) GeForce RTX(TM) 3080 "
						+ "\n\t(10 GB GDDR6X dedicated) with LHR, Display Connectors: HDMI*1, DP*3", 520.0, "NVID3080LHR"),
				new Option("NVIDIA(TM) GeForce RTX(TM) 3080 Ti "
						+ "\n\t(12 GB GDDR6X dedicated), Display Connectors: HDMI*1, DP*3", 950.0, "NVIDTi3080LHR"));
	}		

	PowerSupplyOptions createPowerSupplyOptions() {
		new Option("600 W 80 Plus Gold certified ATX power supply", 0.0, "600W80"),
		new Option("800 W 80 Plus Gold certified ATX power supply", 30.0, "800W80")
	}
	
	/*
	 Data pulled on 9/25/2022 -- the part number ids are fictional
	 https://www.hp.com/us-en/shop/ConfigureView?langId=-1&storeId=10151&catalogId=10051&catEntryId=3074457345620235322&urlLangId=&quantity=1
	 */
}
