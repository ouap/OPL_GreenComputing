public interface PartialSolution {
	public boolean complete(); // solution est complete!

	public void Display(String method); // affichage}

	/* classe des solutions partielles pour BinPacking */
	public void addNextFit(int obj);

	public void addFirstFit(int obj);

	public void addBestFit(int obj);

}