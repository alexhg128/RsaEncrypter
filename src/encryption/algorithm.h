#include <vector>
#include <string>

namespace RSA
{
    
    int gcd(int x, int y);
    int xgcd(int x, int y, int &c1, int &c2);
    int recursive_xgcd(int x, int y, int &c1, int &c2);
    bool is_prime(long x);
    long long mod_pow(long long base, long long exp, long long mod);
    std::vector<std::string> split(const std::string& s, char delimiter);
    int digits(long long number);

}