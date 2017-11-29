animalbin: driver.o pr5.o
	gcc -o animalbin driver.o pr5.o
driver.o: driver.c
	gcc -c -std=gnu90 driver.c
pr5.o: pr5.c
	gcc -c -std=gnu90 pr5.c
