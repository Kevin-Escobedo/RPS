CC=g++
WC=x86_64-w64-mingw32-g++

CFLAGS=-std=c++17 -Wpedantic -Wall -Werror -Wextra -Weffc++ -Wzero-as-null-pointer-constant
LIBS=-static-libgcc -static-libstdc++
OPTIMIZE=-O2

FILES=RPS.h RPS.cpp main.cpp
TARGET=RPS

all: ${TARGET} ${TARGET}.exe
${TARGET}: ${FILES}
	${CC} ${CFLAGS} ${OPTIMIZE} ${FILES} -o ${TARGET}

${TARGET}.exe: ${FILES}
	${WC} ${CFLAGS} ${OPTIMIZE} ${LIBS} ${FILES} -o ${TARGET}.exe

run: ${TARGET}
	valgrind ./${TARGET}

clean:
	/bin/rm -f ${TARGET}
	/bin/rm -f ${TARGET}.exe
