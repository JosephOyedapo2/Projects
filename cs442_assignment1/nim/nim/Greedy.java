package nim;

public class Greedy implements Play {

	@Override
	public int takeTurn(int currentState) {
		int retVal = 1;
		if (currentState > 1) { 
			retVal = currentState/2;
		}
		return retVal;
	}

}
