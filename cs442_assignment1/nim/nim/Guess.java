package nim;

import java.util.Random;

public class Guess implements Play {
	private Random random = new Random();
	@Override
	public int takeTurn(int currentState) {
		int retVal = 1;
		if (currentState > 1) { 
			retVal = 1 + random.nextInt(currentState/2);
		}
		return retVal;
	}

}
