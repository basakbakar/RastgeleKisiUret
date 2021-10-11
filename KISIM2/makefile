hepsi: derle calistir
derle:
	gcc -I ./include/ -o ./lib/Rastgele.o -c ./src/Rastgele.c
	gcc -I ./include/ -o ./lib/TCkimlik.o -c ./src/TCkimlik.c
	gcc -I ./include/ -o ./lib/IMEINo.o -c ./src/IMEINo.c
	gcc -I ./include/ -o ./lib/Telefon.o -c ./src/Telefon.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/RastgeleKisi.o -c ./src/RastgeleKisi.c
	gcc -I ./include/ -o ./bin/Test ./lib/Rastgele.o ./lib/TCkimlik.o ./lib/IMEINo.o ./lib/Telefon.o ./lib/Kisi.o ./lib/RastgeleKisi.o ./src/Test.c
calistir:
	./bin/Test