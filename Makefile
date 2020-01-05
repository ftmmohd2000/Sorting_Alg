output:main.o agen.o bSort.o selSort.o iSort.o mSort.o countSort.o qSort.o
	gcc main.o agen.o bSort.o selSort.o iSort.o mSort.o countSort.o qSort.o -o output

main.o: main.c
	gcc -c main.c

agen.o: agen.c agen.h
	gcc -c agen.c

bSort.o: bSort.c bSort.h
	gcc -c bSort.c

selSort.o: selSort.c selSort.h
	gcc -c selSort.c

iSort.o: iSort.c iSort.h
	gcc -c iSort.c iSort.h

mSort.o: mSort.c mSort.h
	gcc -c mSort.c

countSort.o: countSort.c countSort.h
	gcc -c countSort.c

qSort.o: qSort.c qSort.h
	gcc -c qSort.c qSort.h

clean:
	rm *.o 