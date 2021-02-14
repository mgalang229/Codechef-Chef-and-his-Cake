#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>> v(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
			}
		}
		// test two different type of sequences
		// in this sequence, it starts with G,R,G,R,... 
		int cake1 = 0;
		// set boolean variable to false to start with the G,R,G,R,... sequence
		bool ok = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!ok) {
					// this row will produce G,R,G,R,...
					if (j % 2 == 0) {
						if (v[i][j] == 'R') {
							cake1 += 5;
						}
					} else {
           	if (v[i][j] == 'G') {
           		cake1 += 3;
           	}
          }
				} else {
					// this row will produce R,G,R,G,...
					if (j % 2 == 0) {
						if (v[i][j] == 'G') {
							cake1 += 3;
						}
					} else {
           	if (v[i][j] == 'R') {
           		cake1 += 5;
           	}
          }
				}
			}
			// change boolean value to produce different rows
			ok = ok ^ true;
		}
		int cake2 = 0;
		// set the boolean variable to true to start with the  R,G,R,G,.. sequence
		ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!ok) {
					// this row will produce G,R,G,R,...
					if (j % 2 == 0) {
						if (v[i][j] == 'R') {
							cake2 += 5;
						}
					} else {
           	if (v[i][j] == 'G') {
           		cake2 += 3;
           	}
          }
				} else {
					// this row will produce R,G,R,G,...
					if (j % 2 == 0) {
						if (v[i][j] == 'G') {
							cake2 += 3;
						}
					} else {
           	if (v[i][j] == 'R') {
           		cake2 += 5;
           	}
          }
				}
			}
			// change boolean value to produce different rows
			ok = ok ^ true;
		}
		// get the minimum value between the cakes
		cout << min(cake1, cake2) << '\n';
	}
	return 0;
}
