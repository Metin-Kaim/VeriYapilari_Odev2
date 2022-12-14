all: derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -c -I "./include" ./src/BagliAgac.cpp -o ./lib/BagliAgac.o
	g++ -c -I "./include" ./src/DHucreDugum.cpp -o ./lib/DHucreDugum.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/ODokuDugum.cpp -o ./lib/ODokuDugum.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/RadixSort.cpp -o ./lib/RadixSort.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/OSistemDugum.cpp -o ./lib/OSistemDugum.o
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -c -I "./include" ./src/SOrganDugum.cpp -o ./lib/SOrganDugum.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
bagla:
	g++ ./lib/Kontrol.o ./lib/Queue.o ./lib/RadixSort.o ./lib/Hucre.o ./lib/DHucreDugum.o ./lib/Doku.o ./lib/ODokuDugum.o ./lib/Organ.o ./lib/SOrganDugum.o ./lib/Sistem.o ./lib/OSistemDugum.o ./lib/Organizma.o ./lib/BagliAgac.o ./lib/Dugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program
