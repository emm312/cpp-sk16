SOURCES = ${wildcard src/*.cpp src/*/*.cpp}
OBJS = ${SOURCES:.cpp=.o}

CXX = g++		# Change to clang++ if using clang

CFLAGS = -I./include -O2 -Wall -std=c++20 -g --static

sk-16: pre-build $(OBJS)
	$(CXX) $(CFLAGS) obj/*.o -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o obj/$(notdir $@)

clean:
	-rm -rf obj/

pre-build: clean
	-rm -rf hexagn
	-mkdir obj
