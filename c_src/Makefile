include env.mk

SOURCES = $(wildcard *.c)
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

CFLAGS += -I../priv/astrolog/include/
LDFLAGS += -L../priv/astrolog/lib/
LDLIBS += -lastro -lm

COMPILE_C = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE_CPP = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c

all: $(C_SRC_OUTPUT_FILE)

$(C_SRC_OUTPUT_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -shared $(LDLIBS) -o $(C_SRC_OUTPUT_FILE)

%.o: %.c
	$(COMPILE_C) $(OUTPUT_OPTION) $<

%.o: %.cc
	$(COMPILE_CPP) $(OUTPUT_OPTION) $<

%.o: %.C
	$(COMPILE_CPP) $(OUTPUT_OPTION) $<

%.o: %.cpp
	$(COMPILE_CPP) $(OUTPUT_OPTION) $<

clean: clean-c_src

clean-c_src:
	rm -f $(C_SRC_OUTPUT_FILE) $(OBJECTS)
