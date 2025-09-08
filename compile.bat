@echo off
REM Launch MSYS2 UCRT64 shell and run compile command

C:\msys64\msys2_shell.cmd -ucrt64 -defterm -no-start -here -c ^
"g++ *.cpp `pkg-config --cflags --libs gtk4` -lsqlite3 -o tracker.exe"



