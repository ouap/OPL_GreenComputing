/*
 * classe du parcoureur de solution pour bin_packing selon un critère glouton XX
 * et avec choix de l’énumération
 */
public class SolutionWalkerBinPackXX extends SolutionWalkerBinPack {

	public SolutionWalkerBinPackXX(PblBinPack pbl, EnumerationObjets en) {
		ps = new PartialSolutionBinPack(pbl, en);
		e = en;
	}

	@Override
	public void NextPartialSolution() {
		if (!Terminated()) {

			int i = e.NextElement();

			ps.addNextFit(i);
			ps.addFirstFit(i);
			ps.addBestFit(i);
		} else {
			System.out.println("No more object.");
		}

	}

	@Override
	public boolean Terminated() {

		return ps.complete();
	}

	@Override
	public PartialSolution Current() {

		return ps;

	}

	public void run() {

		while (!Terminated()) {
			NextPartialSolution();

		}

		Current().Display();

	}

	public static void main(String args[]) {

		PblBinPack pb;
		EnumerationObjets enuma;
		SolutionWalkerBinPackXX sol;

		if (args.length < 1) {

			System.out.print("Il manque le nom de fichier");

		} else {

			pb = new PblBinPack(args[0]);

			if (args.length < 2) {

				enuma = new EnumerationOnline(pb.obj, pb.nbObj);
				sol = new SolutionWalkerBinPackXX(pb, enuma);
				sol.run();

			} else {
				if (args[1].equals("-on")) {
					enuma = new EnumerationOnline(pb.obj, pb.nbObj);
					sol = new SolutionWalkerBinPackXX(pb, enuma);
					sol.run();
				}
				if (args[1].equals("-off")) {
					enuma = new EnumerationTriee(pb.obj, pb.nbObj);
					sol = new SolutionWalkerBinPackXX(pb, enuma);
					sol.run();
				} else {

					System.out.print("Argument invalide");
				}
			}

		}

	}

}
