all: tempconvert

tempconvert:
	gcc tempconvert.c -o tempconvert
clean:
	rm tempconvert
