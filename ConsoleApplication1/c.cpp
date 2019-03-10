#include <iostream>
#include <queue>
using namespace std;
int main() {
	int level[30][30];
	int man[30][30], woman[30][30];
	
	int manresult[30];
	int womanresult[30];
	int n;
	cin >> n;
	if (n >= 2 && n <= 30) {
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> man[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> woman[i][j];
				level[i][woman[i][j] - 1] = n-j;
			}
		}
		
		
		queue<int>manqueue;
		for (int i = 1; i < n + 1; i++) {
			manqueue.push(i);
		}
		for (int i = 0; i < 30; i++) {
			manresult[i] = 0;
			womanresult[i] = 0;
		}
		while (manqueue.empty()==false) {
			int a = manqueue.front();
			for (int i = 0; i < n; i++) {
				int b = man[a - 1][i];
				if (womanresult[b - 1]==0) {
					manresult[a - 1] = b;
					womanresult[b - 1] = a;
					
					manqueue.pop();
					break;
				}
				else {
					int c = womanresult[b - 1];
					if (level[b-1][a - 1] > level[b-1][c-1]) {
						
						manresult[a - 1] = b;
						manqueue.push(womanresult[b-1]);
						womanresult[b-1] = a;
						manqueue.pop();
						break;
					}
					
				}
			}
		}
		for (int i = 0; i < n-1; i++) {
			cout << manresult[i]<<" ";
		}
		cout << manresult[n - 1];
	}
}