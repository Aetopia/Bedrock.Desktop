@echo off
cd "%~dp0"
i686-w64-mingw32-gcc.exe -s -nostdlib WinMain.c -lKernel32 -lOle32 -mwindows -o Bedrock.Desktop.exe 
upx.exe --best --ultra-brute Bedrock.Desktop.exe>nul 2>&1