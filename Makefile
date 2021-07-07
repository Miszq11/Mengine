CXX_LINUX:= g++
CXX_WINDOWS:= x86_64-w64-mingw32-g++

sfml_win:= -lsfml-graphics -lsfml-system -lsfml-window -std=c++2a
sfml_win_include:= -ISFML/include
sfml_win_link := -LSFML/lib -lstdc++
dirs := src
objdir :=bin
objdirsrc :=bin/src
objdirdeps :=bin/deps
SRCS := $(shell find $(dirs) -name *.cpp)
#$(foreach dir, $(dirs),$(wildcard $(dir)/*.cpp))
deps:= $(foreach dir, $(dirs),$(wildcard $(dir)/*.hpp))
headers:= $(foreach dir, $(dirs),$(wildcard $(dir)/*.hpp))
objssrc:= $(addprefix $(objdir)/,$(SRCS:=.o))
#objsdeps:=$(addprefix $(objdirdeps)/,$($(SRCS:.hpp=.o): SRCS/%=%))

#SRCS := $(foreach dir, SRCS,$(wildcard $(dir)/*.cpp))

linux:
	@echo "linux nie istnieje... nara"
	@echo "kompiluj z windowsem bo inaczej wpierdol"

windows: bin/main.o
	@echo "compiling and linking with objects: $(objssrc)"
	$(CXX_WINDOWS) bin/main.o $(sfml_win_link) $(objssrc) $(sfml_win) -o windows_build.exe 

bin/main.o: $(objssrc)
	@echo "compiling main.o"
	$(CXX_WINDOWS) -c main.cpp $(sfml_win) $(sfml_win_include) -o bin/main.o

$(objdirsrc)/%.cpp.o: %.cpp
	echo $SRCS
	mkdir -p $(dir $@)
	$(CXX_WINDOWS) -c $< $(sfml_win_include) -o $@

#$(objssrc): 
#$(SRCS)
#	@echo $(SRCS)
#	@echo "compiling $<" $<
#	$(CXX_WINDOWS) -c $(foreach dir, $(dirs),$(wildcard $(dir)/*.hpp)) $(sfml_win_include) -o $@

clean:
	@echo "cleaning"
	@find ./bin -name "*.o" -type f -delete -print
	@echo "cleaning done"

bin/main.o: bin/SRCS/*.o

bin/SRCS/*.o:
