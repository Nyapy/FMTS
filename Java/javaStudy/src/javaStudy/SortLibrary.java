import java.io.*;
import java.util.*;

class Node implements Comparable<Node>
{
    int num;
    char ch;
    Node(int num, char ch)
    {
        this.num = num;
        this.ch = ch;
    }

    @Override
    public int compareTo(Node right) {
        if(num % 2 == 0 && right.num % 2 != 0) return -1;
        if(num % 2 != 0 && right.num % 2 == 0) return 1;
        if(num < right.num) return -1;
        if(num > right.num) return 1;
        if(ch < right.ch) return -1;
        if(ch > right.ch) return 1;
        // TODO Auto-generated method stub
        return 0;
    }

}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        Integer arr[] = new Integer[n];
        Node node[] = new Node[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++)
            node[i] = new Node(arr[i], st.nextToken().charAt(0));

        Arrays.sort(arr);
        for(int i = 0; i < n; i++)
            bw.write(arr[i] + " ");
        bw.write("\n");
        //type 1

        Arrays.sort(arr, Collections.reverseOrder());
        for(int i = 0; i < n; i++)
            bw.write(arr[i] + " ");
        bw.write("\n");
        //type 2

        Arrays.sort(node);
        for(int i = 0; i < n; i++)
            bw.write(node[i].num + " ");
        bw.write("\n");
        for(int i = 0; i < n; i++)
            bw.write(node[i].ch + " ");
        bw.write("\n");



        br.close();
        bw.close();
    }
}
