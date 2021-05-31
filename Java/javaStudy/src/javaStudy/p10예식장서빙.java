import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        for(int test_case = 1; test_case <= t; test_case++)
        {
            int n, r;
            int food[] = new int [1000000 * 2];
            int cnt[] = new int[201];// index : 음식번호, value : 개수
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++)
            {
                food[i] = Integer.parseInt(st.nextToken());
                food[i + n] = food[i];//rotate 형태
            }
            boolean check = false;
            for(int i = 0; i < 2 * n; i++)
            {
                cnt[food[i]]++;//DAT 기록
                if(cnt[food[i]] >= 3)
                    check = true;
                //2r + 1개의 구성
                if(i >= 2*r)//0~2*r
                {
                    cnt[food[i - 2*r]]--; //sliding window 앞의것 빼고, 뒤에 더해주는 방식
                }
            }
            if(check)
                bw.write("#" + test_case + " NO\n");
            else
                bw.write("#" + test_case + " YES\n");
        }
        bw.close();
        br.close();
    }
}