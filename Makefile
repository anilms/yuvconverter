CC = gcc
EXEC = yuvconverter
SOURCES =  	yuvconverter.cpp inittab.cpp\
		   	yuv420planarto420planar.cpp yuv420planarto422planar.cpp yuv420planarto422packed.cpp\
			yuv420planarto444planar.cpp yuv420planarto444packed.cpp yuv420planartorgb.cpp\
			yuv422planarto420planar.cpp yuv422packedto420planar.cpp\
			yuv444planarto420planar.cpp yuv444packedto420planar.cpp\
			rgbto420planar.cpp
OBJECTS = $(SOURCES:.cpp=.o)
CFLAGS = -Wno-deprecated -g


all	: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

%.o : %.cpp Makefile
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *~ *.o $(EXEC)




