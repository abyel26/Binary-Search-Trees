#at the command prompt
#make
#./RomeroFinal

#for use with c++ files
.SUFFIXES : .cpp

#Compile with g++
CC = g++

#use -g for gnu debugger and -std= for c++11 compiling
CXXFLAGS = -g -std=c++11


OBJS = main.o BSTActorActress.o BSTPictures.o 
TARGET = RomeroFinal


$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

#In order to get rid of all .o files create, at the command prompt
#make clean

clean:
	rm -f $(OBJS) $(TARGET) core

zipIt:
	zip -r $(TARGET).zip $ main.cpp $ ActorActress.h $ ActorActressNode.h $ actoractress.csv $ BSTActorActress.cpp * .h $ BSTPictures.cpp * .h $ Picture.h $ PictureNode.h $ pictures.csv $ makefile $ Readme.txt $ RomeroDesign.docx