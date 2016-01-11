/* interface du parcoureur de solutions */
public interface SolutionWalker {
	public boolean Terminated(); // la solution courante est complete

	public void NextPartialSolution(); // passe a UNE solution suivante

	public PartialSolution Current(); // la solution courante}
	/* classe abstraite du parcoureur de solution pour BinPacking */
}