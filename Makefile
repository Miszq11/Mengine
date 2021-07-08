CXX_LINUX:= g++
CXX_WINDOWS:= x86_64-w64-mingw32-g++-win32

sfml_win:= -lsfml-graphics -lsfml-system -lsfml-window -std=c++2a -lstdc++
sfml_include:= -I/mnt/c/SFML64/include
sfml_link := -L/mnt/c/SFML64/lib
static_flags:= -lstdc++  -lsfml-window-s -lsfml-graphics-s -lsfml-system-s -lstdc++ -DSFML_STATIC -static -lopengl32 -lwinmm -lgdi32 -lfreetype
#-lsfml-window-s -lsfml-graphics-s -lsfml-system-s -lstdc++ -DSFML_STATIC -static -lopengl32 -lwinmm -lgdi32 -lfreetype
CXXFLAGS += -std=c++2a
dirs := src
objdir :=bin
# ^ not used
objdirsrc :=bin
objdirdeps :=bin/deps
# ^ not used
SOURCES := $(shell find $(dirs) -type f -name "*.cpp")
VPATH := $(shell find ./src -type d)
#$(foreach dir, $(dirs),$(wildcard $(dir)/*.cpp))
deps:= $(foreach dir, $(dirs),$(wildcard $(dir)/*.hpp))
# ^ not used
headers:= $(foreach dir, $(dirs),$(wildcard $(dir)/*.hpp))
# ^ not used
objtemp := $(notdir $(SOURCES))
objssrc:= $(objtemp:%.cpp=$(objdirsrc)/%.o)

tmptmp := $(objssrc:%=./%)
windows_static: bin/main.o
	@echo "compiling and linking with objects: $(objssrc)"
	$(CXX_WINDOWS) bin/main.o $(objssrc) $(sfml_include) $(static_flags) $(sfml_link) -Wall -v -o windows_build.exe

windows: bin/main.o
	@echo "uzywaj targetu windows_static, albo po prostu \"make\" "
#	$(CXX_WINDOWS) bin/main.o $(sfml_link) $(objssrc) $(sfml_win) -o windows_build.exe 

bin/main.o: $(objssrc)
	@echo "compiling main.o"
	$(CXX_WINDOWS) -c main.cpp $(sfml_include) $(sfml_link) $(static_flags) -Wall -o bin/main.o

bin/%.o : %.cpp
	$(CXX_WINDOWS) -c $< $(sfml_include) $(sfml_link) $(static_flags) -Wall -o $@

# $(shell find $(dirs) -name $(addsuffix ".cpp" , $(basename $(notdir $@))))
#$(objssrc): $(SOURCES)
#	@echo
#	@echo $(basename $(notdir $@))
#	@echo $(shell find $(dirs) -name $(addsuffix ".cpp" , $(basename $(notdir $@))))
#	$(CXX_WINDOWS) -c $(shell find $(dirs) -name $(addsuffix ".cpp" , $(basename $(notdir $@)))) $(sfml_include) -static -o $@

linux:
	@echo "linux nie istnieje... nara"
	@echo "kompiluj z windowsem bo inaczej wpierdol"
	
#$(objssrc): 
#$(SOURCES)
#	@echo $(SOURCES)
#	@echo "compiling $<" $<
#	$(CXX_WINDOWS) -c $(foreach dir, $(dirs),$(wildcard $(dir)/*.hpp)) $(sfml_include) -o $@

clean:
	@echo "cleaning"
	@echo $(SOURCES)
	@echo $(objssrc)
	@echo $(objtemp)
	@find ./bin -name "*.o" -type f -delete -print
	@echo "cleaning done"
