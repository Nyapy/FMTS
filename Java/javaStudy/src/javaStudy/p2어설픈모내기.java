import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//입력용
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//출력용

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());

        for(int i = 0; i < row ;i++)
        {
            String temp = br.readLine();
            int cnt = 0;
            for(int j = 0; j < col; j++)
            {
                char ch = temp.charAt(j);
                cnt += ch - '0'; // 숫자인문자 -> 숫자
            }
            bw.write(cnt + "\n");
        }

        br.close();
        bw.close(); 
    }
}
