#include <iostream>
#include <cmath>

using namespace std;

typedef long long large_integer;

large_integer prod2(large_integer u, large_integer v) {
    // 기저 사례 (Base Case)
    if (u == 0 || v == 0) return 0;

    int n = max((int)log10(u) + 1, (int)log10(v) + 1);
    
    if (n <= 2) return u * v; // 작은 숫자는 직접 곱셈 수행

    int m = n / 2;
    large_integer power = pow(10, m);

    // u와 v를 두 부분으로 나누기
    large_integer x = u / power;
    large_integer y = u % power;
    large_integer w = v / power;
    large_integer z = v % power;

    // 재귀적으로 부분 곱셈 수행
    large_integer r = prod2(x + y, w + z);
    large_integer p = prod2(x, w);
    large_integer q = prod2(y, z);

    // Karatsuba 병합 공식 적용
    return p * pow(10, 2 * m) + (r - p - q) * power + q;
}

int main() {
    large_integer num1 = 123456, num2 = 44002;

    cout << "곱셈 결과: " << prod2(num1, num2) << endl;

    return 0;
}