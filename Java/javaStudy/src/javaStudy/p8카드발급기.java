import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//입력용
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//출력용

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        for(int test_case = 1; test_case <= t; test_case++)
        {
            int n = Integer.parseInt(br.readLine());
            int height[] = new int[1000000];
            int temp[] = new int[1000000];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0 ; i < n; i++)
            {
                int now = Integer.parseInt(st.nextToken());
                temp[i] = now;
            }
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++)
            {
                int rank = Integer.parseInt(st.nextToken());
                height[rank] = temp[i];
            }
            boolean check = true;
            for(int rank = 1; rank < n; rank++)
            {
                if(height[rank] < height[rank + 1])
                {
                    check = false;
                }
            }
            if(check)
                bw.write("YES\n");
            else
                bw.write("NO\n");
        }
        br.close();
        bw.close(); 
    }
}