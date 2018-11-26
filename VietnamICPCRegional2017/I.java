import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;
import java.util.List;
import java.util.ArrayList;

public class I {
    
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int N = Integer.parseInt(reader.nextLine());

        Set<String> unis = new HashSet<>();
        List<String> winners = new ArrayList<>();

        while (winners.size() < 12) {
            String[] next = reader.nextLine().split(" ");
            String uni = next[0];
            String team = next[1];

            if (unis.add(uni)) {
                winners.add(uni + " " + team);
            }
        }

        for (int i = 0; i < 12; i++) {
            System.out.println(winners.get(i));
        }
    }
}
