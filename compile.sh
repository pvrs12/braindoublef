if [ $# -gt 0 ] 
then
	DEBUG=-DDEBUG=0
else
	DEBUG=-DDEBUG=1
fi

FLAGS=$DEBUG

g++ $FLAGS -std=c++11 -obdf -g -Wall bdf.cpp 
