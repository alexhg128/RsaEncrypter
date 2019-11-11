#include <vector>
#include <string>

namespace RSA
{
    
    long long gcd(long long x, long long y);
    long long xgcd(long long x, long long y, long long &c1, long long &c2);
    long long recursive_xgcd(long long x, long long y, long long &c1, long long &c2);
    std::vector<long long> xgcd2(long long a, long long b);
    bool is_prime(long long x);
    long long mod_pow(long long base, long long exp, long long mod);
    std::vector<std::string> split(const std::string& s, char delimiter);
    long long digits(long long number);
    long long brute_force_inverse(long long x, long long y);
    long long inverse(long long a, long long n);
    long long inverse2(long long A, long long M);

}