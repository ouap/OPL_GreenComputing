import java.util.ArrayList;
import java.util.List;

public class PartialSolutionBinPack implements PartialSolution {

	// Bin Pack
	PblBinPack pb;
	EnumerationObjets e;
	List<Integer> next, first, best;
	int[] currents = { 0, 0, 0 };
	// Poids max des sacs
	int max;

	public PartialSolutionBinPack(PblBinPack pb, EnumerationObjets e) {
		this.pb = pb;
		this.e = e;

		// BinPackPb
		next = new ArrayList<Integer>();
		first = new ArrayList<Integer>();
		best = new ArrayList<Integer>();

		max = pb.capacite;
	}

	@Override
	public boolean complete() {

		return !e.hasMoreElements();
	}// solution est complete!

	@Override
	public void Display() {
		System.out.println("BinPack :");
		System.out.println(" First  : " + first.size() + " sacs"
				+ "\n Next : " + next.size() + " sacs"
				+ "\n Best  : " + best.size() + " sacs");
	}

	/* FONCTION POUR BINPACK */

	@Override
	public void addNextFit(int obj) {
		if (next.size() == 0) {
			next.add(0);
			currents[0] = next.size() - 1;
		}

		if ((next.get(currents[0])) + obj > max) {
			next.add(0);
			currents[0] = next.size() - 1;

		}

		int tmp = next.get(currents[0]) + obj;
		next.remove(currents[0]);
		next.add(currents[0], tmp);

	}

	@Override
	public void addFirstFit(int obj) {

		boolean done = false;
		int bag = 0;

		if (first.size() == 0) {
			first.add(0);
			currents[1] = first.size() - 1;
		}

		if ((first.get(currents[1])) + obj > max) {

			for (int i = 0; i < first.size(); i++) {

				if ((first.get(i)) + obj <= max && !done) {
					done = true;
					bag = i;

				}

			}

			if (!done) {
				first.add(0);
				currents[1] = first.size() - 1;
			} else {
				currents[1] = bag;
			}

		}

		int tmp = first.get(currents[1]) + obj;
		first.remove(currents[1]);
		first.add(currents[1], tmp);
		currents[1] = first.size() - 1;

	}

	@Override
	public void addBestFit(int obj) {

		boolean done = false;
		int bag = 0;
		int gap = -1;

		if (best.size() == 0) {
			best.add(0);
			currents[2] = best.size() - 1;
		}

		if ((best.get(currents[2])) + obj > max) {

			for (int i = 0; i < best.size(); i++) {

				if ((best.get(i)) + obj <= max) {
					if (gap == -1) {
						done = true;
						gap = max - ((best.get(i)) + obj);
						bag = i;
					}

					if (gap > max - ((best.get(i)) + obj)) {

						gap = max - ((best.get(i)) + obj);
						bag = i;
					}

				}

			}

			if (!done) {
				best.add(0);
				currents[2] = best.size() - 1;
			} else {
				currents[2] = bag;
			}

		}

		int tmp = best.get(currents[2]) + obj;
		best.remove(currents[2]);
		best.add(currents[2], tmp);
		currents[2] = best.size() - 1;

	}

}
