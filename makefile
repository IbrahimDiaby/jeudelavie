.PHONY : compile clean dist doc
CFLAGS = -g -Wall
OPATH = obj
BPATH = bin
SPATH = src

#For Ubuntu
#CPPFLAGS += -Iinclude -I/usr/include/cairo
#LDFLAGS += -lcairo -lm -lX11

#For Mac
CPPFLAGS += -Iinclude -I/usr/local/include/cairo -L /usr/local/lib/cairo/libcairo-trace.so
LDFLAGS += -lcairo -lm -lX11


vpath %.h include
vpath %.c src
vpath %.o obj

compile : main.o grille.o jeu.o io.o
	gcc $(CFLAGS) -o main $(OPATH)/*.o -o $(BPATH)/main -lm

%.o : %.c
	gcc $(CFLAGS) -c $< -I include -o $(OPATH)/$@
doc :
	doxygen

clean :
	rm -rf $(OPATH)/* $(BPATH)/* html

dist :
	tar -zcvf DiabyIbrahim-GoL-5.1.1.tar.xz src include grilles obj bin Makefile Doxyfile README
