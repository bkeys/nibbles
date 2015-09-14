GLLIBS    = -lGL -lglut -lGLU
CFLAGS    = -std=c99 -O3 -Wall -pedantic -Werror
PRJ       = snake
CC        = gcc
OBJDIR    = obj/
SRCDIR    = src/
OBJFILES  = $(OBJDIR)main.o $(OBJDIR)glut_func.o $(OBJDIR)arena.o

$(PRJ) : $(OBJFILES)
	$(CC) -o bin/$(PRJ) $(OBJFILES) $(GLLIBS) $(CFLAGS)

$(OBJDIR)main.o: $(SRCDIR)main.c $(SRCDIR)arena.h $(SRCDIR)glut_func.h
	$(CC) -o $(OBJDIR)main.o -c $(SRCDIR)main.c $(GLLIBS) $(CFLAGS)

$(OBJDIR)arena.o: $(SRCDIR)arena.c $(SRCDIR)arena.h
	$(CC) -o $(OBJDIR)arena.o -c $(SRCDIR)arena.c $(GLLIBS) $(CFLAGS)

$(OBJDIR)glut_func.o: $(SRCDIR)glut_func.c $(SRCDIR)glut_func.h $(SRCDIR)arena.h
	$(CC) -o $(OBJDIR)glut_func.o -c $(SRCDIR)glut_func.c $(GLLIBS) $(CFLAGS)

clean :
	rm $(OBJDIR)*.o bin/$(PRJ).exe
