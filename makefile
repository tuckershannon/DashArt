
CXX = g++


#CXXFLAGS += -O3
LDFLAGS =  `pkg-config opencv --cflags --libs`


OBJS = dash.o

SRCS = dash.cpp

#target: dependencies
#	rule to build
#

dash: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o dash

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
