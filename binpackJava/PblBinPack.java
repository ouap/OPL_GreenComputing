import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;


class Pbl {
	public Pbl(){} 
}



//le pb d’optimisation du BinPacking

public class PblBinPack extends Pbl{

	public int nbObj; //nb d’objets
	public Integer obj[]; //poids des objets
	public int capacite; //capacité d’un sac 


public PblBinPack(String fileName){

	List<String> lignes = new ArrayList<String>();

	fileName = fileName;	

	try{
		Scanner scanner = new Scanner(new File(fileName));
		int a =0;
		//System.out.println(scanner.hasNextLine());

		// on lit le fichier
		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			lignes.add(line);
		}

		scanner.close();
	}catch(Exception e){
		System.out.println("fail : " + e);
	}

	if(lignes.size()==0){
		System.out.println("Erreur, fichier illisible");
	}else{

		try{
			nbObj = Integer.parseInt((lignes.get(0).split(" "))[0]);
			
			capacite = Integer.parseInt((lignes.get(1).split(" "))[0]);
		
			obj= new Integer [nbObj];

			for(int i = 2; i <= (nbObj+1);i++){
				obj[i-2]=Integer.parseInt((lignes.get(i).split(" "))[0]);
			}

			System.out.println("nbObj = "+ nbObj+", Capacité = "+capacite+".");

		}catch(NumberFormatException e){
		    			System.out.println("Error : "+e.getMessage()+" Attention syntax fichier incorrect");
	      		  	}
	}
}

}
