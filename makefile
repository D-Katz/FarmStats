fp:	Control.o main.o Report1.o Report2.o Report3.o ReportGenerator.o Record.o View.o
	g++ -o fp Control.o main.o Report1.o Report2.o Report3.o ReportGenerator.o Record.o View.o

Control.o: Control.h
	g++ -c Control.cc
	
main.o:	main.cc
	g++ -c main.cc

Report1.o: Report1.h
	g++ -c Report1.cc 

Report2.o: Report2.h
	g++ -c Report2.cc 

Report3.o: Report3.h
	g++ -c Report3.cc 

ReportGenerator.o: ReportGenerator.h
	g++ -c ReportGenerator.cc 

Record.o: Record.h
	g++ -c Record.cc

View.o:View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o fp

