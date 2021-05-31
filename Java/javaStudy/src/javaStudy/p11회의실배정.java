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
        int n = Integer.parseInt(br.readLine());
        Node node[] = new Node[n];
        for(int i = 0; i < n; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            node[i] = new Node(s, e);
        }
        Arrays.sort(node);
        int de = 1;
        int cnt = 0;
        int e = 0; // <- 앞의 회의가 끝난 시간
        for(int i = 0; i < n; i++)
        {
            if(node[i].s >= e)
            {
                cnt++;
                e = node[i].e;
            }
        }

        bw.write(cnt + "");

        br.close();
        bw.close();
    }
}
