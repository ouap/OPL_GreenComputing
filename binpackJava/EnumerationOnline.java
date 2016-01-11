
/* classe d’enumeration online */
public class EnumerationOnline implements EnumerationObjets {
	Integer obj[];
	int iterator;
	int length;

	public EnumerationOnline(Integer tab[], int nbObj) {
		obj = tab;
		length = nbObj;
		iterator = 0;

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
