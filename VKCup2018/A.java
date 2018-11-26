import java.util.PriorityQueue;
import java.util.HashSet;
import java.util.Scanner;
import java.io.*;

public class A {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        long l, r;
        l = reader.nextInt();
        r = reader.nextInt();

        PriorityQueue<Long> q = new PriorityQueue<>();
        HashSet<Long> visited = new HashSet<>();
        int count = 0;

        q.add(1L);
        while (q.size() > 0) {
            long curr = q.poll();
            if (curr <= r && !visited.contains(curr)) {
                if (curr >= l) {
                    count++;
                }
                q.add(curr * 2);
                q.add(curr * 3);
                visited.add(curr);
            }
        }
        System.out.println(count);
    }
}
