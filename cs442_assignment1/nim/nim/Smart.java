package nim;
import java.util.*;
import java.util.Random;

public class Smart implements Play{
	private Random random = new Random();
	@Override
	public int takeTurn(int currentState) {
		int p = 1;
		int n = currentState;
		if(n == 1){
			return 1;
		}
		 if(n > 1){
			while(p <= n + 1){
				p = p * 2;
				if(2 * p > n + 1){
					if((p - 1) == n){
						int retVal = this.random.nextInt(1,n / 2 + 1);
						return retVal;
					}
					else if((p - 1) < n){
						return (n - p + 1);
					}
				}
			}
		}

	return p;
	}
}
