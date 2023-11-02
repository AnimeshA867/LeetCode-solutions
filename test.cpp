#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int binary(int n)
{
    vector<char> temp;
    while (n != 0)
    {
        temp.push_back(n % 2);
        n /= 2;
    }
    return temp.size();
}
int complement(int n)
{
    int base = binary(n);
    return pow(2, base) - n - 1;
}

int oneComplement(int a, int b)
{
    int small = min(a, b);
    int big = max(a, b);
    int base = binary(big);
    small = complement(small);
    int sum = small + big;
    if (binary(sum) > base)
    {
        return (sum & complement(pow(2, binary(sum)))) + 1;
    }
    else
    {
        return complement(sum);
    }
}

int minFlips(int a, int b, int c)
{
    int sum = a + b;
    if (sum == c)
    {
        return 0;
    }
    else
    {
        return oneComplement(c, complement(sum));
    }
}

int main()
{
    int c = 5;
    int temp = c << 1;
    cout << temp << endl;
    cout << minFlips(8, 3, 5) << endl;

    return 0;
}
