import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//입력용
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//출력용
    public static void main(String[] args) throws IOException {
        boolean check[] = new boolean[256];
        String s = br.readLine();

        //char <- 1byte <- 8bit <- 256
        //
        for(int i = 0; i < s.length(); i++)
        {
            check[s.charAt(i)] = true;;// <-문자 => 숫자;
        }
        for(int i = 'A'; i <= 'Z'; i++)
            if(check[i])
                bw.write((char)i + "");
        br.close();
        bw.close(); 
    }
}