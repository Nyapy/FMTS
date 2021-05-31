import java.io.*;
import java.util.*;

class Node implements Comparable<Node>
{
    int s, e;
    Node(int s, int e)
    {
        this.s = s;
        this.e = e;
    }

    @Override
    public int compareTo(Node right) {
        if(e < right.e) return -1;
        if(e > right.e) return 1;
        if(s < right.s) return -1;
        if(s > right.s) return 1;
        // TODO Auto-generated method stub
        return 0;
    }

}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        PriorityQueue<Node> pq = new PriorityQueue<>(); // Min
        PriorityQueue<Node> pq1 = new PriorityQueue<>(Collections.reverseOrder()); // Max

        pq1.add(new Node(5,3));
        pq1.add(new Node(4,2));
        pq1.add(new Node(1,4)); // pq에 데이터 삽입
        bw.write(pq1.poll().e + ""); // pq에서 가장 위에 있는 데이터를 반환 후 삭제
        pq1.peek(); // pq에서 가장 위에 있는 데이터를 반환

        int de = 1;
        br.close();
        bw.close();
    }
}
