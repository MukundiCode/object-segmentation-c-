findcomp.exe: PGMimageProcessor.o PGMimageProcessorDriver.o
	g++ PGMimageProcessor.o PGMimageProcessorDriver.o -o findcomp.exe -std=c++2a
    
PGMimageProcessor.o: PGMimageProcessor.cpp
	g++ -c PGMimageProcessor.cpp -o PGMimageProcessor.o -std=c++2a
  
PGMimageProcessorDriver.o: PGMimageProcessorDriver.cpp
	g++ -c PGMimageProcessorDriver.cpp -o PGMimageProcessorDriver.o -std=c++2a
  
clean:
	rm *.o findcomp.exe
