hepsi: derle calis

derle:
	gcc -I ./include/ -o ./lib/Kisiler.o -c ./src/Kisiler.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c
	gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c
	gcc -I ./include/ -o ./bin/Program ./lib/Kisiler.o ./lib/Oyun.o ./lib/Dosya.o ./src/Test.c

calis:
	./bin/Program	
