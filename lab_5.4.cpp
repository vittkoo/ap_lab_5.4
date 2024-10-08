#include <iostream>
#include <cmath>

using namespace std;

double S0(const int N) 
{
    double s = 0;
    for (int k = 1; k <= N; k++)
        s += 1.0 / pow((2 * k + 1), 2);
    return s;
}

double S1(const int N, const int k) 
{
    if (k > N)
        return 0;
    else
        return 1.0 / pow((2 * k + 1), 2) + S1(N, k + 1);
}

double S2(const int N, const int k) 
{
    if (k < 1)
        return 0;
    else
        return 1.0 / pow((2 * k + 1), 2) + S2(N, k - 1);
}

double S3(const int N, const int k, double t) 
{
    t += 1.0 / pow((2 * k + 1), 2);
    if (k >= N)
        return t;
    else
        return S3(N, k + 1, t);
}


double S4(const int N, const int k, double t) 
{
    t += 1.0 / pow((2 * k + 1), 2);
    if (k <= 1)
        return t;
    else
        return S4(N, k - 1, t);
}

int main() {
    int N;
    cout << "N = "; cin >> N;

    cout << "(iter)        S0 = " << S0(N)       << endl;
    cout << "(rec up ++)   S1 = " << S1(N, 1)    << endl;
    cout << "(rec up --)   S2 = " << S2(N, N)    << endl;
    cout << "(rec down ++) S3 = " << S3(N, 1, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, N, 0) << endl;

    return 0;
}
