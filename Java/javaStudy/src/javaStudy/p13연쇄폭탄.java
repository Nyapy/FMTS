import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int when, r, c;

    Node(int when, int r, int c) {
        this.when = when;
        this.r = r;
        this.c = c;
    }

    @Override
    public int compareTo(Node right) {
        if(when < right.when) return -1;
        if(when > right.when) return 1;
        // TODO Auto-generated method stub
        return 0;
    }

}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int MAP[][] = new int[n][n];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i = 0; i < n; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++)
            {
                MAP[i][j] = Integer.parseInt(st.nextToken());
                pq.add(new Node(MAP[i][j], i, j));
            }
        }
        boolean check[][] = new boolean[n][n];
        // 0 : 위, 1번 : 아래, 2 : 왼쪽, 3 : 오른쪽
        int dr[] = {-1,1, 0,0, 0, 1, -1, -1,  1};
        int dc[] = { 0,0,-1,1, 0, 1,  1, -1, -1};
        int ans = 0;
        while(!pq.isEmpty())
        {
            Node now = pq.poll();
            int now_r = now.r;
            int now_c = now.c;
            if(check[now_r][now_c] == true)
                continue;
            ans = now.when;
            int next_r , next_c;
            for (int i = 0; i < 5; i++) {
                next_r = now_r + dr[i];
                next_c = now_c + dc[i];
                if(next_r < 0 || next_c < 0 || next_r >= n || next_c >=n)
                    continue;
                check[next_r][next_c] = true;
            }
        }
        bw.write(ans + "초");

        br.close();
        bw.close();
    }
}


