//<pre><code>#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//long long check[400001];
//long long input[400001];
//vector<int> num;
//int n, m, k;
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	for (int test_case = 1; test_case <= t; test_case++)
//	{
//		num = vector<int>();
//		scanf("%d %d %d", &n, &m, &k);
//		for (int i = 0; i < m; i++)
//		{
//			input[i] = 0;
//			check[i] = 0;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			int temp = 0;
//			scanf("%d", &temp);
//			temp %= m;
//			if (temp < 0)
//				temp += m;
//			if (!input[temp])
//			{
//				num.push_back(temp);
//			}
//			input[temp]++;
//		}
//		int de = 1;
//		vector<int> v_num;
//		int num_size = num.size();
//		for (int i = 0; i < num_size; i++)
//		{
//			int temp = num[i] * 2;
//			if (temp >= m)
//				temp -= m;
//			if (!check[temp])
//				v_num.push_back(temp);
//			check[temp] += (input[num[i]] * input[num[i]]);
//			for (int j = i + 1; j < num_size; j++)
//			{
//				int temp = (num[i] + num[j]);
//				if (temp >= m)
//					temp -= m;
//				if (!check[temp])
//					v_num.push_back(temp);
//				check[temp] += (input[num[i]] * input[num[j]]) * 2;
//			}
//		}
//		int v_num_size = v_num.size();
//		long long ans = 0;
//		for (int i = 0; i < v_num_size; i++)
//		{
//			int temp = k - v_num[i];
//			if (temp < 0) temp += m;
//			if (check[temp])
//			{
//				ans += check[temp] * check[v_num[i]];
//			}
//		}
//		printf("#%d %lld\n", test_case, ans);
//	}
//}
//
//< / code>< / pre><pre><code>import java.io.*;
//import java.util.*;
//
//class Node
//{
//	int r, c;
//	Node(int r, int c)
//	{
//		this.r = r;
//		this.c = c;
//	}
//}
//
//public class Main {
//	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//	static int MAP[][];
//	static int check[][];
//	public static void main(String[] args) throws IOException {
//		int t = Integer.parseInt(br.readLine());
//		for (int test_case = 1; test_case & lt; = t; test_case++)
//		{
//			StringTokenizer st = new StringTokenizer(br.readLine());
//
//			int n = Integer.parseInt(st.nextToken());
//			int m = Integer.parseInt(st.nextToken());
//			int k = Integer.parseInt(st.nextToken());
//
//			int num[] = new int[400001];
//			int index = 0;
//			long cnt[] = new long[400001];
//			st = new StringTokenizer(br.readLine());
//			for (int i = 0; i & lt; n; i++)
//			{
//				int temp = Integer.parseInt(st.nextToken()) % m;
//				if (temp& lt; 0) temp += m;
//				if (cnt[temp] == 0) num[index++] = temp;
//				cnt[temp]++;
//			}
//
//			int hap_num[] = new int[800002];
//			int hap_index = 0;
//			long hap_cnt[] = new long[400001];
//
//			for (int i = 0; i & lt; index; i++)
//			{
//				for (int j = i; j & lt; index; j++)
//				{
//					int temp = (num[i] + num[j]);
//					if (temp& gt; = m) temp -= m;
//					if (hap_cnt[temp] == 0) hap_num[hap_index++] = temp;
//					if (i == j)
//						hap_cnt[temp] += cnt[num[i]] * cnt[num[j]];
//					else
//						hap_cnt[temp] += cnt[num[i]] * cnt[num[j]] * 2;
//				}
//			}
//			int de = 1;
//			long ans = 0;
//
//			for (int i = 0; i & lt; hap_index; i++)
//			{
//				int temp = k - hap_num[i];
//				if (temp& lt; 0) temp += m;
//				ans += hap_cnt[temp] * hap_cnt[hap_num[i]];
//			}
//			bw.write("#" + test_case + " " + ans + "\n");
//		}
//
//
//		br.close();
//		bw.close();
//	}
//}
//
//< / code>< / pre>