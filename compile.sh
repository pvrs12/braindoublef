if [ $# -gt 0 ] 
then
	DEBUG=-DDEBUG=0
fi

FLAGS=$DEBUG

g++ $FLAGS -std=c++11 -oexe -g -Wall bdf.cpp 
