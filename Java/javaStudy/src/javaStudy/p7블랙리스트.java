import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//입력용
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//출력용

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int arow = Integer.parseInt(st.nextToken());
        int acol = Integer.parseInt(st.nextToken());
        int alist[] = new int[100001];
        boolean[] check = new boolean[100001];
        for(int i = 0; i < arow; i++)
        {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < acol; j++)
            {
                int temp = Integer.parseInt(st.nextToken());
                alist[temp]++;
            }
        }
        st = new StringTokenizer(br.readLine());
        int brow = Integer.parseInt(st.nextToken());
        int bcol = Integer.parseInt(st.nextToken());
        int ans = 0;
        for(int i = 0; i < brow; i++)
        {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < bcol; j++)
            {
                int temp = Integer.parseInt(st.nextToken());
                if(!check[temp])
                {
                    ans += alist[temp];
                    check[temp] = true;
                }
            }
        }
        bw.write(ans + "\n" + (arow*acol - ans));
        br.close();
        bw.close(); 
    }
}