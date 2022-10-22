package assignment02;

public abstract class ComputerConfigFactory {
	abstract DefaultConfig createDefaultConfig();
	abstract CPUOptions createCPUOptions();
	abstract OpSysOptions createOpSysOptions();
	abstract RamOptions createRamOptions();
	abstract DiskStorageOptions createDiskStorageOptions();
	abstract GraphicsCardOptions createGraphicsCardOptions();
	abstract PowerSupplyOptions createPowerSupplyOptions();
}
