import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//입력용
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//출력용
    static int check[] = new int[10000]; // 0 : 등록 안됨, 1 : 등록완료 출입하지 않음, 2 : 등록완료 출입함
    static String reg_name[] = new String[10000];
    public static void sol1(int num, String name) throws IOException 
    {
        if(check[num] == 0)
        {
            check[num] = 1;
            reg_name[num] = name;
            bw.write(num + " OK\n");
        }
        else
        {
            bw.write(num + " ERROR\n");
        }
    }
    public static void sol2(int num) throws IOException 
    {
        if(check[num] == 1)
        {
            check[num] = 2;
            bw.write(num + " " + reg_name[num] +" ENTER\n");
        }
        else if(check[num] == 2)
        {
            check[num] = 1;
            bw.write(num + " " + reg_name[num] +" EXIT\n");
        }
        else
        {
            bw.write(num + " ERROR\n");
        }
    }
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            if(type == 1) 
                {
                int num = Integer.parseInt(st.nextToken());
                String name = st.nextToken();
                sol1(num, name);
                }
            else if(type == 2) 
            {
                int num = Integer.parseInt(st.nextToken());

                sol2(num);
            }
        }
        br.close();
        bw.close(); 
    }
}