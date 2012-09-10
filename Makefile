CC = gcc
EXEC = yuvconverter
SOURCES =  	yuvconverter.c inittab.c\
		   	yuv420planarto420planar.c yuv420planarto422planar.c yuv420planarto422packed.c\
			yuv420planarto444planar.c yuv420planarto444packed.c yuv420planartorgb.c\
			yuv422planarto420planar.c yuv422packedto420planar.c\
			yuv444planarto420planar.c yuv444packedto420planar.c\
			rgbto420planar.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wno-deprecated -g


all	: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *~ *.o $(EXEC)




