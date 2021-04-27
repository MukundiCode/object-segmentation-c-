findcomp.exe: pixel.o PGMimageProcessor.o PGMimageProcessorDriver.o ConnectedComponent.o
	g++ pixel.o ConnectedComponent.o PGMimageProcessor.o PGMimageProcessorDriver.o -o findcomp.exe -std=c++2a
 
#tests.exe: pixel.o PGMimageProcessor.o PGMimageProcessorDriver.o ConnectedComponent.o unit_tests.o
#	g++ pixel.o ConnectedComponent.o PGMimageProcessor.o PGMimageProcessorDriver.o unit_tests.o -o tests.exe -std=c++2a

pixel.o: pixel.cpp
	g++ -c pixel.cpp -o pixel.o -std=c++2a
     
PGMimageProcessor.o: PGMimageProcessor.cpp
	g++ -c PGMimageProcessor.cpp -o PGMimageProcessor.o -std=c++2a
  
PGMimageProcessorDriver.o: PGMimageProcessorDriver.cpp
	g++ -c PGMimageProcessorDriver.cpp -o PGMimageProcessorDriver.o -std=c++2a
 
ConnectedComponent.o: ConnectedComponent.cpp
	g++ -c ConnectedComponent.cpp -o ConnectedComponent.o -std=c++2a
 
unit_tests.o: unit_tests.cpp
	g++ -c unit_tests.cpp -o unit_tests.o -std=c++2a
  
clean:
	rm *.o findcomp.exe
