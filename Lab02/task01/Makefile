CXX = g++
CXXFLAGS = -Wall -std=c++11

# Object files
OBJ = school.o teacher.o coure.o main.o

all: program

program: $(OBJ)
	$(CXX) $(CXXFLAGS) -o program $(OBJ)

school.o: school.cpp school.h
	$(CXX) $(CXXFLAGS) -c school.cpp

teacher.o: teacher.cpp teacher.h
	$(CXX) $(CXXFLAGS) -c Teacher.cpp

course.o: course.cpp course.h
	$(CXX) $(CXXFLAGS) -c Course.cpp

main.o: main.cpp school.h teacher.h course.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o program


