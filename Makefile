EXE = Navigator
LIB = s21_graph.a

SOURCES = 	./s21_graph/Graph.cpp						\
          	./s21_graph/Graph2.cpp						\
			./s21_graph/Graph3.cpp						\
		  	./s21_graph_algorithms/GraphAlgorihms1.cpp	\
			./s21_graph_algorithms/GraphAlgorihms2.cpp	\
			./s21_graph_algorithms/GraphAlgorihms3.cpp	\
			./s21_graph_algorithms/GraphAlgorihms4.cpp	\
			./s21_graph_algorithms/GraphAlgorihms5.cpp	\
			./s21_graph_algorithms/GraphAlgorihms6.cpp	\
			./UI/main.cpp



BUILD_DIR = obj
HDR  = ./includes/s21_graph_algorithms.h
OBJS = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))
UNAME_S := $(shell uname -s)


CXXFLAGS = -std=c++17 -Iincludes
CXXFLAGS += -g -Wall -Wformat 
LIBS =



$(BUILD_DIR)/%.o:%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


$(BUILD_DIR)/%.o:./s21_graph/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


$(BUILD_DIR)/%.o:./s21_graph_algorithms/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


$(BUILD_DIR)/%.o:./UI/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<



all: $(EXE)
	@echo Build complete

$(EXE): $(OBJS) $(HDR)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -rf $(BUILD_DIR)

re: clean all

dvi:
		doxygen Doxyfile && open ./html/index.html

dist:
	@echo "No dist target for this project"

tests:
	@echo "No tests target for this project. Define how to run your tests."

leaks:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXE)