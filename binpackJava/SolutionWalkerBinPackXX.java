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
	public void NextPartialSolution(String method) {
		if (!Terminated()) {
			int i = e.NextElement();
			switch(method){
				case "first":
					ps.addFirstFit(i);
					break;
				case "next":
					ps.addNextFit(i);
					break;
				case "best":
					ps.addBestFit(i);
					break;
			}
			
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

	public void run(String method) {

		while (!Terminated()) {
			NextPartialSolution(method);

		}

		Current().Display(method);

	}

	public static void main(String args[]) {

		PblBinPack pb;
		EnumerationObjets enuma;
		SolutionWalkerBinPackXX sol;

		if (args.length < 2) {

			System.out.print("Il manque le nom de fichier et/ou la method de binPack \n");

		} else {

			pb = new PblBinPack(args[0]);

				enuma = new EnumerationOnline(pb.obj, pb.nbObj);
				sol = new SolutionWalkerBinPackXX(pb, enuma);
				sol.run(args[1]);

		}

	}


}
