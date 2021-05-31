import java.io.*;
import java.util.*;


class Printer implements Comparable<Printer>
{
    //en : 문서의 출력이 완료되는 시간
    //ind : 프린터 번호
    long en;
    int ind;
    Printer(long en, int ind)
    {
        this.en = en;
        this.ind = ind;
    }
    @Override
    public int compareTo(Printer o) {
        //출력이 빨리 완료되는 순
        if(en < o.en) return -1;
        if(en > o.en) return 1;
        //프린터 번호가 빠른 순
        if(ind < o.ind) return -1;
        if(ind > o.ind) return 1;
        return 0;
    }

}

class Doc implements Comparable<Doc>
{
    //s : 출력을 요청한 시간
    //cost : 해당 문서를 출력하는데 필요한 시간
    //ind : 문서 번호(sort시 문서가 섞이므로 본래 번호를 기록해야 함)
    long s;
    long cost;
    int ind;
    Doc(long s, long cost, int ind)
    {
        this.s = s;
        this.cost = cost;
        this.ind = ind;
    }
    @Override
    public int compareTo(Doc right) {
        // 출력 요청이 빠른 순
        if(s < right.s) return -1;
        if(s > right.s) return 1;
        if(cost < right.cost) return -1;
        if(cost > right.cost) return 1;
        // 문서 번호가 빠른 순
        if(ind < right.ind) return -1;
        if(ind > right.ind) return 1;
        return 0;
    }
}

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        //입력 처리
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        //doc : 각 문서(정렬하여 섞이에 됩니다.)
        Doc[] doc = new Doc[n];
        //doc_print : 각 문서가 출력될 프린터 번호
        int[] doc_print = new int[n];

        //문서 입력
        for(int i = 0; i < n; i++)
        {
            st = new StringTokenizer(br.readLine());
            long s = Long.parseLong(st.nextToken());
            long cost = Long.parseLong(st.nextToken());
            doc[i] = new Doc(s, cost, i);
        }

        //출력을 요청한 순서대로 문서를 정렬
        Arrays.sort(doc);//NlogN

        //출력이 빨리 완료될 프린터를 찾기 위한 PriorityQueue 세팅
        PriorityQueue<Printer> pq = new PriorityQueue<>();
        for(int i = 1; i <= m; i++)
        {
            pq.add(new Printer((long)0, i));//MlogM
        }

        //요청이 빠른 문서부터 확인하여 프린터 배정
        //배정되는 프린터는 출력이 빨리 완료되는 프린터로
        long ans = 0;
        for(int i = 0; i < n; i++)
        {
            //now : 출력이 가장 빨리 완료되는 프린터
            Printer now = pq.poll();//NlogM
            long now_en = now.en;

            if(now.en <= doc[i].s)
            //현재 출력중인 문서가 완료된 이후 이번 문서의 출력 요청이 들어온 경우
            {
                //출력요청 이후부터 시간 계산
                ans += doc[i].cost;
                now_en = doc[i].s + doc[i].cost;
            }
            else
            //현재 출력중인 문서가 완료되기 이전에 이번 문서의 출력 요청이 들어온 경우
            {
                //현재 출력중인 문서가 완료된 이후부터 시간 계산
                ans += (now.en - doc[i].s) + doc[i].cost;
                now_en = now.en + doc[i].cost;
            }
            //해당 프린터는 이후에 또 쓸 수 있으므로 PriorityQueue에 새로 등록
            pq.add(new Printer(now_en, now.ind));//NlogM
            //이번 문서에 사용한 프린터 번호를 기록
            doc_print[doc[i].ind] = now.ind;
        }

        //각 문서별 기록된 프린터 번호를 출력
        for(int i = 0; i < n; i++)
        {
            bw.write(doc_print[i] + "\n");
        }
        bw.close();
        br.close();
    }
}