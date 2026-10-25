CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g -MMD -MP
TARGET   := store_app

SRCS := main.cpp address.cpp credit_card.cpp person.cpp \
        product.cpp store.cpp transaction.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)

.PHONY: all run clean
