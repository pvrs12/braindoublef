if [ $# -gt 0 ] 
then
	DEBUG=-DDEBUG=0
else
	DEBUG=-DDEBUG=1
fi

FLAGS=$DEBUG
SRCDIR=src

g++ $FLAGS -std=c++11 -obdf -g -Wall -I$SRCDIR $SRCDIR/bdf.cpp
