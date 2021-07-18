CXX_LINUX:= g++
CXX_WINDOWS:= x86_64-w64-mingw32-g++-win32

sfml_win:= -lsfml-graphics -lsfml-system -lsfml-window -std=c++2a -lstdc++
sfml_include:= -ISFML/include
sfml_link := -LSFML/lib
static_flags:= -lstdc++  -lsfml-window-s -lsfml-graphics-s -lsfml-system-s -lstdc++ -DSFML_STATIC -static -lopengl32 -lwinmm -lgdi32 -lfreetype
CXX_VER = -std=c++2a
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
#some coloring stuff
ccgreen := $(shell tput -Txterm setaf 2)
ccyellow := $(shell tput -Txterm setaf 3)
ccpurple := $(shell tput -Txterm setaf 5)
ccreset := $(shell tput -Txterm sgr0)

windows_static: bin/main.o
#	$(ccred)
	@echo "${ccgreen}------------------------------------------------------------------------------------------------------------------------------------------------------------"
	@echo "compiling and linking with objects: ${ccreset}$(objssrc)${ccgreen}"
	@echo "------------------------------------------------------------------------------------------------------------------------------------------------------------${ccreset}"
	$(CXX_WINDOWS) bin/main.o $(objssrc) $(sfml_include) $(CXX_VER) $(static_flags) $(sfml_link) -Wall -o windows_build.exe
	@echo -n "${ccreset}"

windows: bin/main.o
	@echo "uzywaj targetu windows_static, albo po prostu \"make\" "
#	$(CXX_WINDOWS) bin/main.o $(sfml_link) $(objssrc) $(sfml_win) -o windows_build.exe 

bin/main.o: $(objssrc)
	@echo "${ccgreen}compiling main.o${ccyellow}"
	$(CXX_WINDOWS) -c main.cpp $(sfml_include) $(CXX_VER) $(sfml_link) $(static_flags) -Wall -o bin/main.o
	@echo -n "${ccreset}"
bin/%.o : %.cpp
	@echo -n "${ccgreen}"
	$(CXX_WINDOWS) -c $< $(sfml_include) $(CXX_VER) $(sfml_link) $(static_flags) -Wall -o $@
	@echo -n "${ccreset}"
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
