import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Sort {

	public static void main(String[] args) throws IOException {
		List<Path> result = null;
		System.out.println(args[0]);
		try (Stream<Path> paths = Files.walk(Paths.get(args[0]))) {
			result = paths.filter(s -> !s.toFile().isDirectory() && s.toFile().getName().startsWith("data_")).collect(Collectors.toList());
		} catch (IOException e) {
			e.printStackTrace();
		}
		for (Path file : result) {

			List<Integer> linesInt = new ArrayList<Integer>();
			System.out.println(file.toString());
			List<String> lines = Files.readAllLines(file);

			String nbObj = lines.get(0);
			String capacite = lines.get(1);
			lines.remove(0);
			lines.remove(1);

			for(String s : lines) {
				linesInt.add(Integer.valueOf(s));
			}

			Collections.sort(linesInt, Collections.reverseOrder());
			linesInt.add(0, Integer.parseInt(capacite));
			linesInt.add(0, Integer.parseInt(nbObj));
			List<String> sortedList = linesInt.stream().map(s-> s.toString()).collect(Collectors.toList());

			Files.write(file, sortedList);
		}

	}

}
