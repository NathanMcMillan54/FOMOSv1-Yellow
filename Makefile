all: calculator.c darkTheme.c FOMOS.c FOMOSUI.c lightTheme.c restart.c settings.c shutdown.c
	gcc `pkg-config --cflags gtk+-3.0` -o FOMOSUI.o FOMOSUI.c `pkg-config --libs gtk+-3.0`
	gcc `pkg-config --cflags gtk+-3.0` -o settings.o settings.c `pkg-config --libs gtk+-3.0`
	gcc `pkg-config --cflags gtk+-3.0` -o calculator.o calculator.c `pkg-config --libs gtk+-3.0` -lm
	gcc -Wall FOMOS.c -o FOMOS.o
	gcc -Wall shutdown.c -o shutdown.o
	gcc -Wall restart.c -o restart.o
	gcc -Wall darkTheme.c -o darkTheme.o
	gcc -Wall lightTheme.c -o lightTheme.o

clean:
	@rm -rf *.o
