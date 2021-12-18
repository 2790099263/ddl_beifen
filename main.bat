chcp 65001
gcc -c user.c
gcc -c user.h
gcc -c color.c
gcc -c color.h
gcc -c client.c
gcc -c client.h
gcc -c ddl.c
gcc -c ddl.h
gcc main.c -o main.exe client.c cli_user.c color.c ddl.c -lwsock32
cls
set /p IP=please enter your target ip:
main.exe %IP%
pause 