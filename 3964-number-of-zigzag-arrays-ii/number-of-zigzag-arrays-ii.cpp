class Solution {
    const int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;

    Matrix multiply(const Matrix& A, const Matrix& B, int m) {
        Matrix C(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (A[i][k] == 0) continue; 
                for (int j = 0; j < m; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix A, long long p, int m) {
        Matrix res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) res[i][i] = 1; 
        
        while (p > 0) {
            if (p % 2 == 1) res = multiply(res, A, m);
            A = multiply(A, A, m);
            p /= 2;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        Matrix U(m, vector<long long>(m, 0));
        Matrix L(m, vector<long long>(m, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                U[i][j] = 1;
            }
            for (int j = 0; j < i; j++) {
                L[i][j] = 1;
            }
        }
        
        int k = n - 1; 
        Matrix UL = multiply(U, L, m);
        Matrix P = power(UL, k / 2, m);
        
        if (k % 2 != 0) {
            P = multiply(L, P, m);
        }
        
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                sum = (sum + P[i][j]) % MOD;
            }
        }
        
        return (sum * 2) % MOD;
    }
};