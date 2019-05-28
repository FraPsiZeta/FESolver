CXX= c++
ROOTPATH= $(CURDIR)
CPPFLAGS= --std=c++14 -I $(ROOTPATH)/Eigen/ \
	              -I $(ROOTPATH)/include
CXXFLAGS= -Wall
OPATH= $(ROOTPATH)/obj
SRCPATH= $(ROOTPATH)/src
SRCS= $(wildcard ./src/*.cpp)
OBJS= $(addprefix $(OPATH)/,$(notdir $(patsubst %.cpp, %.o,$(SRCS))))

vpath %.h include
vpath %.cpp src
vpath %.o obj

solver: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ \

$(OBJS): $(OPATH)/%.o : %.cpp interactive_init.h 
	@if [ ! -d $(OPATH) ]; then \
		mkdir -p $(OPATH); \
	fi	
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean: 
	rm -f $(SRCPATH)/*.o  $(OPATH)/*.o solver
