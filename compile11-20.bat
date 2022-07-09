@echo off
cls

if exist "main.exe" (
    del "main.exe"
)

g++ -I src -o run.exe 11-20.cpp -mwindows -lmingw32 -lSDL2main -lSDL2

if not errorlevel 1 (
    "run.exe"
)
