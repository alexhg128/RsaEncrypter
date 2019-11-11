#include "algorithm.h"

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>

int RSA::gcd(int x, int y)
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

int RSA::recursive_xgcd(int x, int y, int &c1, int &c2)
{
    if(x == 0)
    {
        c1 = 0;
        c2 = 1;
        return y;
    }
    int a, b;
    int g = RSA::xgcd(y % x, x, a, b);
    c1 = b - (y / x) * a;
    c2 = a;
    return g;
}

int RSA::xgcd(int x, int y, int &c1, int &c2)
{
    int a = 0;
    int b = 1;
    int c = 1;
    int d = 0;
    while(y != 0)
    {
        int q = x / y;
        int temp1 = x % y;
        x = y;
        y = temp1;
        int temp2 = a;
        a = c - q * a;
        c = temp2;
        int temp3 = b;
        b = d - q * b;
        d = temp3;
    }
    c1 = c;
    c2 = d;
    return x;
}

bool RSA::is_prime(long x)
{
    if (x <= 1)
    {
        return false; 
    } 
    for (int i = 2; i < x; i++)
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

int RSA::digits(long long number)
{
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}