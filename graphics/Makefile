#- MM scan source file and makes depends for user made h files
#mbouncingBall

TARGET = main
#SOURCES += $(wildcards *.cpp)
SOURCES = $(TARGET).cpp 
#shapes
SOURCES += implement/paddle.cpp implement/ball.cpp 
SOURCES += implement/window.cpp implement/imove.cpp implement/idraw.cpp implement/ievent.cpp implement/icollide.cpp
SOURCES += implement/brickNormal.cpp implement/brickExplode.cpp
SOURCES += implement/shapeContainer.cpp 
SOURCES += implement/fileInput.cpp implement/conversions.cpp implement/brickBase.cpp implement/calcs.cpp
SOURCES += implement/dirContent.cpp 
SOURCES += implement/game.cpp implement/text.cpp 

OBJECTS = $(SOURCES:.cpp=.o)
INC_DIR = ../include include/
#LIB_DIR = ../lib
# compiler and linker flags
CC		 =g++
#

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS = $(addprefix -I,$(INC_DIR))
CFLAGS   = -g -pedantic -ansi -Wall -Werror -DDEBUG
CXXFLAGS += $(CFLAGS) -std=c++03
LDFLAGS  = -g 
#LDFLAGS +=  $(addprefix -L,$(LIB_DIR))
	
.PHONY: all clean run

all:	$(TARGET) 

$(TARGET): $(OBJECTS)

include depends 

depends: $(SOURCES)
	$(CC) -MM $(CPPFLAGS) $^ > depends

clean:
	rm -f $(TARGET) $(OBJECTS) depends *.gch

run:
	./$(TARGET) -v
