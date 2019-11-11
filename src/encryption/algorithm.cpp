#include "algorithm.h"

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <utility>
#include <exception>
#include <tuple>

long long RSA::gcd(long long x, long long y)
{
    while (x != y)
    {
        if(x > y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
    }
    return x;    
}

long long RSA::recursive_xgcd(long long x, long long y, long long &c1, long long &c2)
{
    if(x == 0)
    {
        c1 = 0;
        c2 = 1;
        return y;
    }
    long long a, b;
    long long g = RSA::xgcd(y % x, x, a, b);
    c1 = b - (y / x) * a;
    c2 = a;
    return g;
}

long long RSA::xgcd(long long x, long long y, long long &c1, long long &c2)
{
    long long a = 0;
    long long b = 1;
    long long c = 1;
    long long d = 0;
    while(y != 0)
    {
        long long q = x / y;
        long long temp1 = x % y;
        x = y;
        y = temp1;
        long long temp2 = a;
        a = c - q * a;
        c = temp2;
        long long temp3 = b;
        b = d - q * b;
        d = temp3;
    }
    c1 = c;
    c2 = d;
    return x;
}

std::vector<long long> RSA::xgcd2(long long a, long long b)
{
    long long s = 0; long long old_s = 1;
    long long t = 1; long long old_t = 0;
    long long r = b; long long old_r = a;

    while(r != 0) {
        long long quotient = old_r/r;
        // We are overriding the value of r, before that we store it's current
        // value in temp variable, later we assign it to old_r
        long long temp = r;
        r = old_r - quotient*r;
        old_r = temp;

        // We treat s and t in the same manner we treated r
        temp = s;
        s = old_s - quotient*s;
        old_s = temp;

        temp = t;
        t = old_t - quotient*t;
        old_t = temp;
    }
    std::vector<long long> result;
    result.push_back(old_r);
    result.push_back(old_s);
    result.push_back(old_t);
    return result;
}

bool RSA::is_prime(long long x)
{
    if (x <= 1)
    {
        return false; 
    } 
    for (long long i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return false; 
        } 
    }
    return true; 
}

long long RSA::mod_pow(long long base, long long exp, long long mod)
{
    long res = 1;
    base = base % mod;
    while(exp > 0)
    {
        if(exp & 1)
        {
            res = (res * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

std::vector<std::string> RSA::split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

long long RSA::digits(long long number)
{
    long long digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

long long RSA::brute_force_inverse(long long x, long long y)
{
    for(int i = 1; i < y; i++)
    {
        if((i * x) % y == 1)
        {
            return i;
        }
    }
    return 0;    
}

long long RSA::inverse(long long a, long long n)
{
    long long t = 0, newt = 1;
    long long r = n, newr = a;  
    while (newr != 0) {
        auto quotient = r /newr;
        std::tie(t, newt) = std::make_tuple(newt, t- quotient * newt);
        std::tie(r, newr) = std::make_tuple(newr, r - quotient * newr);
    }
    if (r > 1)
        throw std::runtime_error("a is not invertible");
    if (t < 0)
        t += n;
    return t;
}

long long RSA::inverse2(long long A, long long M)
{
    std::vector<long long> v = xgcd2(A, M);
    long long gcd = v[0];
    long long x = v[1];
    long long y = v[2];
    if(x < 0) {
        x += M;
    }
    
    return x;
}