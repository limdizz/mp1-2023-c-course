int Pow(int a, long long b, int c) {
    long long result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
        result %= c;
    }
    return result % c;
}
