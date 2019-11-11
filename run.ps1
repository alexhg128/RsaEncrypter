$c = cmake -version

if($?)
{
    if(Test-Path obj/CMakeHash -PathType Leaf)
    {
        $hash = Get-Content -Path obj/CMakeHash
        if($hash -eq (Get-FileHash -Path ./CMakeLists.txt).Hash)
        {
            mingw32-make
            Write-Host ""
            Write-Host "========== RSA ENCRYPTER ==========" -ForegroundColor Blue
            Write-Host ""
            bin/RsaEncrypter
            Write-Host ""
        }
        else 
        {
            cmake .
            mingw32-make
            Write-Host ""
            Write-Host "========== RSA ENCRYPTER ==========" -ForegroundColor Blue
            Write-Host ""
            bin/RsaEncrypter
            Write-Host ""
            Set-Content -Path obj/CMakeHash -Value (Get-FileHash -Path ./CMakeLists.txt).Hash
        }
    }
    else 
    {
        if(-Not (Test-Path obj/CMakeStatus))
        {
            cmake -G "MinGW Makefiles" .
            if(-Not (Test-Path obj/)) 
            {
                $o = mkdir obj
            }
            Set-Content -Path obj/CMakeStatus -Value "GOOD"
        }
        cmake .
        mingw32-make
        Write-Host ""
        Write-Host "========== RSA ENCRYPTER ==========" -ForegroundColor Blue
        Write-Host ""
        bin/RsaEncrypter
        Write-Host ""
        if(-Not (Test-Path obj/)) 
        {
            $oo = mkdir obj
        }
        Set-Content -Path obj/CMakeHash -Value (Get-FileHash -Path ./CMakeLists.txt).Hash
    }
    
}
else 
{
    g++ src/encryption/hashart.cpp src/encryption/rsa.cpp src/app/app.cpp src/main.cpp -o bin/RsaEncrypter
    bin/RsaEncrypter
}
