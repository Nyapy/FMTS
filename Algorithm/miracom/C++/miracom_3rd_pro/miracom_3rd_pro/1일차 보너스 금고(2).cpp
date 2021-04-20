#include <iostream>

using namespace std;


int T, N, M, K, button[1001], ans;
int double_tab[400001];
int press2[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		//cout << "여기다 여기 " << double_tab[5];

		for (int i = 0; i < 400001; i++) {
			double_tab[i] = 0;
		}

		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) {
			cin >> button[i];
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				press2[(N * (i - 1)) + j] = (button[i] + button[j]) % M;
				if (press2[(N * (i - 1)) + j] < 0) {
					press2[(N * (i - 1)) + j] = press2[(N * (i - 1)) + j] + M;
				}
				//cout << i << " 누르고 " << j << " 눌러서 " << press2[(N * (i - 1)) + j] << "\n";
				double_tab[press2[(N * (i - 1)) + j]] ++;
			}
			}
		}
		ans = 0;
		int tab = 0;
		for (int i = 1; i <= N * N; i++) {
			tab = (M + K - press2[i]) % M;
			//cout << press2[i] << "일 때 " << tab << "더함" << double_tab[tab] << " \n";
			ans += double_tab[tab];
		}
		cout << '#' << tc << ' ' << ans << "\n";
	}
}
