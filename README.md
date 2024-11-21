# task62
contact_list62.h - файл, в котором определены структуры и функции.
contact_list62.c - файл, в котором реализованы функции для работы с двусвязным списком.
необходимо скомпилировать contact_list62.c в статическую библиотеку.
gcc -c -DBUILD_DLL contact_list62.c -o contact_list62.o - компиляция в объектный файл
gcc -shared -o contact_list62.dll contact_list62.o - создание динамической библиотеки
task62.c - файл, который использует библиотеку.
gcc task62.c -o task62 -L. -lcontact_list62 - компилируем основной файл
./task62 - запуск программы
