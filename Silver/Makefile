SRC = 11057_dp.cpp

NAME = a.out

all : ${NAME}

${NAME} : ${SRC}
	c++ $^

debug : ${SRC}
	c++ -g3 $^
#-fsanitize=address 

clean :
	rm -rf a.out
re :
	${MAKE} clean
	${MAKE} all