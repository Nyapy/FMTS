import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int s, e;

    Node(int s, int e) {
        this.s = s;
        this.e = e;
    }

    @Override
    public int compareTo(Node right) {
        if (e < right.e)
            return -1;
        if (e > right.e)
            return 1;
        if (s < right.s)
            return -1;
        if (s > right.s)
            return 1;
        // TODO Auto-generated method stub
        return 0;
    }

}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq_min = new PriorityQueue<>();
        PriorityQueue<Integer> pq_max = new PriorityQueue<>(Collections.reverseOrder());
        pq_min.add(500);
        for(int i = 0; i < n; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pq_min.add(a);
            pq_max.add(b);
            if(pq_min.peek() < pq_max.peek())
            {
                pq_min.add(pq_max.poll());
                pq_max.add(pq_min.poll());
            }
            bw.write(pq_min.peek() + "\n");
        }
        br.close();
        bw.close();
    }
}