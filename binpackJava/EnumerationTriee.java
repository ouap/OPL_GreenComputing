import java.util.Arrays;
import java.util.Collections;

/* classe d’enumeration triee selon les poids décroissants */
class EnumerationTriee implements EnumerationObjets {

	Integer obj[];
	int iterator;
	int length;

	public EnumerationTriee(Integer tab[], int nbObj) {
		obj = tab;
		length = nbObj;
		iterator = 0;

		// Trier le tableau en ordre inverse
		Arrays.sort(obj, Collections.reverseOrder());

	}

	@Override
	public boolean hasMoreElements() {

		return iterator < length;
	}

	@Override
	public int NextElement() {
		int i = obj[iterator];
		iterator++;
		return i;
	}

	@Override
	public int sum() {
		int sum = 0;
		for (int i = 0; i < length; i++) {
			sum += obj[i];
		}
		return sum;
	}

}
// on utilisera par exemple une implémentation de la classe Comparator de
// java.util