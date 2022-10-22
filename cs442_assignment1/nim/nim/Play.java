package nim;
@FunctionalInterface
interface Play {
	int takeTurn(int currentState);
	Play FRUGAL = new Frugal();
	Play GREEDY = new Greedy();
	Play GUESS = new Guess();
	Play SMART = new Smart();
}
