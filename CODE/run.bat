del grid.prg
..\TOOL\CC65\bin\cl65 -t c64 -g -Oirs -Cl main.c -o grid.prg
if exist grid.prg ..\TOOL\VICE\bin\x64sc.exe -autostart "grid.prg"
