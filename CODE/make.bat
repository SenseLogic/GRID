del grid.asm
del grid.int
del grid.lbl
del grid.map
del grid.prg
rem ..\TOOL\OSCAR64\bin\oscar64 -tm=c64 -n -o=grid.prg main.c
..\TOOL\OSCAR64\bin\oscar64 -tm=c64 -n -O2 -o=grid.prg main.c
