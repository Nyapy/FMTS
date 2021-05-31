import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//입력용
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//출력용
    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        for(int test_case = 1; test_case <= t; test_case++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int sum = 0;
            //만약 w 가 5라면
            // 5개짜리 합을 구한 후에 사용을 다 하고, 맨 앞의 수를 제외
            // (맨 앞의 수를 제외한 나머지 4개의 합 + 새로운 숫자를 더 함)
            int num[] = new int[n];
            int ans = Integer.MIN_VALUE;
            int index = -1;
            for(int i = 0; i < n; i++)
            {
                num[i] = Integer.parseInt(st.nextToken());
                sum += num[i];
                if(i >= w - 1)
                {
                    if(ans < sum)
                    {
                        ans = sum;
                        index = i;
                    }
                    sum -= num[i - (w - 1)];
                }
            }
            bw.write("#" + test_case + " " + (index - (w - 1)) + " " + index + " " + ans + "\n");
        }
        br.close();
        bw.close(); 
    }
}