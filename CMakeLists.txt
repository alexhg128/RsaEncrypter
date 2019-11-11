cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 11)
project (RsaEncrypter)
add_executable  (   
                    bin/RsaEncrypter 
                    src/main.cpp 
                    src/app/app.cpp
                    src/encryption/rsa.cpp
                    src/encryption/hashart.cpp
                    src/encryption/algorithm.cpp
                    src/encryption/key.cpp
                    src/encryption/simplersa.cpp
                )