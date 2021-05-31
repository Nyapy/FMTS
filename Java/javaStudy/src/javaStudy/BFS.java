import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        ArrayList<ArrayList<Integer>> alist= new ArrayList<>();
        for(int i = 0; i <= 11; i++)
            alist.add(new ArrayList<Integer>());
        alist.get(1).add(2);
        alist.get(1).add(3);
        alist.get(1).add(10);
        alist.get(2).add(1);
        alist.get(3).add(1);
        alist.get(10).add(1);


        alist.get(4).add(2);
        alist.get(8).add(2);
        alist.get(2).add(4);
        alist.get(2).add(8);
        alist.get(8).add(4);
        alist.get(4).add(8);

        alist.get(10).add(9);
        alist.get(9).add(10);


        alist.get(10).add(6);
        alist.get(6).add(10);

        alist.get(5).add(6);
        alist.get(6).add(5);

        alist.get(3).add(6);
        alist.get(6).add(3);

        alist.get(3).add(7);
        alist.get(7).add(3);

        int check[] = new int[11];
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        check[1] = 1;
        while (!q.isEmpty()) {
            int now = q.poll();
            bw.write(now + " " + check[now] + "\n");
            for(int i = 0; i < alist.get(now).size(); i++)
            {
                int next = alist.get(now).get(i);
                if(check[next] >= 1) continue;
                q.add(next);
                check[next] = check[now] + 1;
            }

            /*
            for (int i = 1; i <= 10; i++) {
                if (MAP[now][i] == 1) {
                    if(check[i] != 0)
                        continue;
                    q.add(i);
                    check[i] = check[now] + 1;
                }
            }*/
        }

        bw.close();
        br.close();
    }
}
