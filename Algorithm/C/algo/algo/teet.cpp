//#include <stdio.h>
//
//#define MAX (20 + 5)
//
//#define RAINBOW (0)
//#define BLACK (-1)
//#define EMPTY (-2)
//
//int N, M;
//int MAP[MAX][MAX];
//
//typedef struct st1
//{
//	int r;
//	int c;
//}RC;
//
//typedef struct st2
//{
//	int normal;
//	int rainbow;
//	int minR;
//	int minC;
//}BLOCK_INFO;
//
//void input()
//{
//	scanf("%d %d\n", &N, &M);
//	for (int r = 0; r <= N + 1; r++)
//		for (int c = 0; c <= N + 1; c++)
//			MAP[r][c] = BLACK;
//
//	for (int r = 1; r <= N; r++)
//		for (int c = 1; c <= N; c++)
//			scanf("%d", &MAP[r][c]);
//}
//
//void output()
//{
//	for (int r = 1; r <= N; r++)
//	{
//		for (int c = 1; c <= N; c++)
//		{
//			if (MAP[r][c] == EMPTY) printf("   ");
//			else printf("%2d ", MAP[r][c]);
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//}
//
//void rotate(int MAP[MAX][MAX])
//{
//	int tmpMAP[MAX][MAX] = { 0 };
//
//	for (int r = 1; r <= N; r++)
//		for (int c = 1; c <= N; c++)
//			tmpMAP[r][c] = MAP[r][c];
//
//	for (int r = 1; r <= N; r++)
//		for (int c = 1; c <= N; c++)
//			MAP[r][c] = tmpMAP[c][N - r + 1];
//}
//
//void blockDownColumn(int map[MAX][MAX], int col)
//{
//	for (int r = N; r >= 1; r--)
//	{
//		if (map[r][col] == BLACK || map[r][col] == EMPTY) continue;
//
//		int start_row = r;
//		while (1)
//		{
//			if (map[start_row + 1][col] != EMPTY) break;
//
//			if (map[start_row + 1][col] == EMPTY)
//			{
//				int tmp = map[start_row][col];
//				map[start_row][col] = map[start_row + 1][col];
//				map[start_row + 1][col] = tmp;
//			}
//
//			start_row++;
//		}
//	}
//}
//
//void blockDown(int map[MAX][MAX])
//{
//	for (int col = 1; col <= N; col++) blockDownColumn(map, col);
//}
//
///* 순서대로 왼쪽, 위, 오른쪽, 아래 */
//int dr[] = { 0, -1, 0, 1 };
//int dc[] = { -1, 0, 1, 0 };
//
//BLOCK_INFO BFS(int r, int c, int visit[MAX][MAX], int map[MAX][MAX])
//{
//	BLOCK_INFO blockInfo = { 0 };
//	RC queue[MAX * MAX] = { 0 };
//	int rp, wp, block;
//
//	blockInfo.normal++; /* 최소 하나의 블럭이 존재 */
//	blockInfo.minR = r;
//	blockInfo.minC = c;
//
//	rp = wp = 0;
//
//	block = map[r][c];
//
//	queue[wp].r = r;
//	queue[wp++].c = c;
//
//	visit[r][c] = 1;
//
//	while (wp > rp)
//	{
//		RC out = queue[rp++];
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nr, nc;
//
//			nr = out.r + dr[dir];
//			nc = out.c + dc[dir];
//
//			if (map[nr][nc] == BLACK || visit[nr][nc] == 1) continue;
//
//			if (map[nr][nc] == block || map[nr][nc] == RAINBOW)
//			{
//				visit[nr][nc] = 1;
//
//				queue[wp].r = nr;
//				queue[wp++].c = nc;
//				blockInfo.normal++;
//
//				if (map[nr][nc] == RAINBOW) blockInfo.rainbow++;
//
//				if (map[nr][nc] == block)
//				{
//					if ((nr < blockInfo.minR)
//						|| (nr == blockInfo.minR && nc < blockInfo.minC))
//					{
//						blockInfo.minR = nr;
//						blockInfo.minC = nc;
//					}
//				}
//			}
//
//		}
//	}
//
//	return blockInfo;
//}
//
//void deleteBlock(int r, int c, int visit[MAX][MAX], int map[MAX][MAX])
//{
//	RC queue[MAX * MAX] = { 0 };
//	int rp, wp, block;
//
//	rp = wp = 0;
//
//	block = map[r][c];
//	map[r][c] = EMPTY;
//
//	queue[wp].r = r;
//	queue[wp++].c = c;
//
//	visit[r][c] = 1;
//
//	while (wp > rp)
//	{
//		RC out = queue[rp++];
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nr, nc;
//
//			nr = out.r + dr[dir];
//			nc = out.c + dc[dir];
//
//			if (map[nr][nc] == BLACK || visit[nr][nc] == 1) continue;
//
//			if (map[nr][nc] == block || map[nr][nc] == RAINBOW)
//			{
//				visit[nr][nc] = 1;
//
//				queue[wp].r = nr;
//				queue[wp++].c = nc;
//
//				map[nr][nc] = EMPTY;
//			}
//		}
//	}
//}
//
//int main()
//{
//	input();
//
//	int ans = 0;
//
//	while (1)
//	{
//		int maxBlock, maxRainbow, maxr, maxc;
//
//		maxBlock = maxRainbow = maxr = maxc = -1;
//		for (int r = 1; r <= N; r++)
//		{
//			for (int c = 1; c <= N; c++)
//			{
//				if (MAP[r][c] == BLACK || MAP[r][c] == RAINBOW || MAP[r][c] == EMPTY) continue;
//
//				int visit[MAX][MAX] = { 0 }; /* 매번 초기화 해야 한다. */
//				BLOCK_INFO tmp = BFS(r, c, visit, MAP);
//
//				if (tmp.normal <= 1) continue;
//
//				/* 크기가 가장 큰 블록의 판단 */
//				if ((maxBlock < tmp.normal)
//					|| (maxBlock == tmp.normal && maxRainbow < tmp.rainbow)
//					|| (maxBlock == tmp.normal && maxRainbow == tmp.rainbow && tmp.minR > maxr)
//					|| (maxBlock == tmp.normal && maxRainbow == tmp.rainbow && tmp.minR == maxr && tmp.minC > maxc))
//				{
//					maxBlock = tmp.normal;
//					maxRainbow = tmp.rainbow;
//					maxr = tmp.minR;
//					maxc = tmp.minC;
//				}
//			}
//		}
//
//		if (maxBlock == -1) break;
//
//		ans += (maxBlock * maxBlock);
//
//		int visit[MAX][MAX] = { 0 };
//		deleteBlock(maxr, maxc, visit, MAP);
//
//		blockDown(MAP);
//		rotate(MAP);
//		blockDown(MAP);
//		printf("%d\n", ans);
//	}
//
//	printf("%d\n", ans);
//
//	return 0;
//}