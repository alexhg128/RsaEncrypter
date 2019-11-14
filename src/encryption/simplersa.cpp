#include "simplersa.h"

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "algorithm.h"

RSA::KeyPair RSA::generate_simple_keypair(int x, int y)
{
    long long n = x * y;
    long long p = (x - 1) * (y - 1);
    long long e = p / 4;
    while (!RSA::is_prime(e))
    {
        e--;
    }
    while(RSA::gcd(p, e) != 1)
    {
        e++;
        if(e == p -1)
        {
            break;
        }
    }
    long long w, t;
    long long d;
    d = RSA::inverse2(e, p);
    std::cout << n << " " << p << " " << e << " " << w << " " << t << std::endl;
    RSA::KeyPair key = RSA::KeyPair();
    key.public_key = std::to_string(n) + "." + std::to_string(e);
    key.private_key = std::to_string(n) + "." + std::to_string(d);
    return key;
}

std::string RSA::encrypt_simple(std::string key, std::string msg)
{
    std::vector<std::string> components = RSA::split(key, '.');
    if(components.size() != 2)
    {
        return "";
    }
    long long n = stoll(components[0]);
    long long e = stoll(components[1]);
    long long digits = RSA::digits(n);
    long long c = digits - 1;
    c /= 3;
    int j = 1;
    std::string encrypted = "";
    std::string encrypted_d = "";
    std::string s = "";
    for(int i = 0; i < msg.size(); i++)
    {
        
        int ch = msg[i];
        if(ch < 10)
        {   
            s += "00" + std::to_string(ch);
        }
        else if(ch < 100)
        {
            s += "0" + std::to_string(ch);
        }
        else
        {
            s += std::to_string(ch);
        }        
        j++;
        if(j > c)
        {
            j = 1;
            long long nu = stoll(s);
            long long cipher = RSA::mod_pow(nu, e, n);
            
            std::stringstream stream;
            stream << std::hex << cipher;
            std::string p_encrypted = stream.str();
            long long h_s = p_encrypted.size();
            for (int k = 0; k < digits - h_s; k++)
            {
                p_encrypted += "0" + p_encrypted;
            }
            encrypted += p_encrypted;
            std::string p_encrypted_d = std::to_string(cipher);
            
            long long d_s = p_encrypted_d.size();
            for (int k = 0; k < digits - d_s; k++)
            {
                p_encrypted_d = "0" + p_encrypted_d;
            }
            
            encrypted_d += p_encrypted_d;
            s = "";
        }
    }
    return encrypted_d;
}

std::string RSA::decrypt_simple(std::string key, std::string msg)
{
    std::vector<std::string> components = RSA::split(key, '.');
    if(components.size() != 2)
    {
        return "";
    }
    long long n = stoll(components[0]);
    long long d = stoll(components[1]);
    long long digits = RSA::digits(n);
    long long c = digits - 1;
    c /= 3;
    int j = 1;
    std::vector<std::string> com;
    std::vector<std::string> p_components;
    std::string decrypted = "";
    
    std::string s = "";
    for(int i = 0; i < msg.size(); i++)
    {
        s += msg[i];
        j++;
        if(j > digits)
        {
            j = 1;
            com.push_back(s);
            s = "";
        }
    }
    for(std::string s: com)
    {
        
        long long x = stoll(s);
        long long y = mod_pow(x, d, n);
        std::string pro = std::to_string(y);
        while (pro.size() < c * 3)
        {
            pro = "0" + pro;
        }
        
        for(int i = 0; i < pro.size(); i += 3)
        {
            std::string sub = pro.substr(i, 3);
            char ch = std::stoi(sub);
            decrypted += ch;
        }
    }
    return decrypted;
}