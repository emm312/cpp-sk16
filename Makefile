SOURCES = ${wildcard src/*.cpp src/*/*.cpp}
OBJS = ${SOURCES:.cpp=.o}

CXX = g++		# Change to clang++ if using clang

CFLAGS = -I./include -Wall -std=c++20 -g --static

sk-16: pre-build $(OBJS)
	$(CXX) $(CFLAGS) obj/*.o -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o obj/$(notdir $@)

clean:
	-rm -rf obj/

pre-build: clean
	-rm -rf sk-16.exe
	-mkdir obj
