# Wedit Makefile for project ordena1
SRCDIR=c:\renato\sources\estdados
CFLAGS=-Ic:\lcc\include  -g2 
CC=c:\lcc\bin\lcc.exe
LINKER=c:\lcc\bin\lcclnk.exe
OBJS=\
	ordena1.obj

LIBS=

ordena1.exe:	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\ordena1.exe $(OBJS) $(LIBS)

# Build ordena1.c
ORDENA1_C=\

ordena1.obj: $(ORDENA1_C) $(SRCDIR)\ordena1.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\ordena1.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\ordena1.exe $(OBJS) $(LIBS)

