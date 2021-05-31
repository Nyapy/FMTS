import java.io.*;
import java.util.*;
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int[] nArr = { 0, 1004, 1680, 9941, 3367, 3261, 2976, 4889, 1234, 6461, 7329, 5518 };
        ArrayList<ArrayList<Integer>> alist = new ArrayList<>();
        for (int i = 0; i <= 11; i++)
            alist.add(new ArrayList<Integer>());
        alist.get(1).add(2);
        alist.get(1).add(3);
        alist.get(2).add(4);
        alist.get(2).add(5);
        alist.get(3).add(6);
        alist.get(3).add(7);
        alist.get(5).add(8);
        alist.get(5).add(9);
        alist.get(6).add(10);
        alist.get(6).add(11);
        // 5번을 자식으로 갖는 번호
        int now = Integer.parseInt(br.readLine());
        int index = 0;
        for (int i = 1; i <= 11; i++)
            if (nArr[i] == now)
                index = i;
        if (index == 0) {
            bw.write("no person");
        } else {
            boolean check = false;
            for (int from = 1; from <= 6; from++) {
                for (int i = 0; i < alist.get(from).size(); i++) {
                    if (alist.get(from).get(i) == index) {
                        bw.write(nArr[from] + "\n");
                        if (i == 0) {
                            bw.write(nArr[alist.get(from).get(1)] + "\n");
                        } else {
                            bw.write(nArr[alist.get(from).get(0)] + "\n");
                        }
                        check = true;
                    }
                }
            }
            if (!check) {
                bw.write("no boss\n");
                bw.write("no company\n");
            }

            if (alist.get(index).size() == 0)
                bw.write("no junior\n");
            else {
                for (int i = 0; i < alist.get(index).size(); i++) {
                    bw.write(nArr[alist.get(index).get(i)] + " ");
                }
            }

        }
        bw.close();
        br.close();
    }
}