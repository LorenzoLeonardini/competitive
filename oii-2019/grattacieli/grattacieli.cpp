#include <vector>

using namespace std;

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    while(true) {
		bool passed = true;
		for (int i = 0; i < M; i++) {
			if(H[A[i]] < H[B[i]] - H[C[i]]) {
				passed = false;
				H[B[i]] = H[A[i]] + H[C[i]];
			}
		}
		if (passed) break;
	}
	int res = 0;
	for(int i = 0; i < N; i++)
		res += H[i];
	return res;
}
