CXX= c++
ROOTPATH= $$HOME/Software/FESolver
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
	$(CXX) $(CXXFLAGS) -o $@ $^ 

$(OBJS): $(OPATH)/%.o : %.cpp interactive_init.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@

#$(OPATH)/interactive_init.o: interactive_init.cpp interactive_init.h 
#	$(CXX) $(CPPFLAGS) -c $< -o $@

clean: 
	rm -f $(SRCPATH)/*.o  $(OPATH)/*.o solver
