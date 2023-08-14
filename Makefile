ASAN    := -fsanitize=address -fsanitize=undefined
CC      := clang 
DEBUGGER:= lldb
CFLAGS  :=  -g $(ASAN) -Wall -Wextra -Werror -pedantic -Wshadow -Wno-unused-parameter -Wno-error=unused-variable 
BIN     :=  main
LIBS    := 
LDFLAGS := $(LIBS) $(ASAN) 
OBJPATH := obj

ifndef VERBOSE
.SILENT:
endif

cfiles:=$(shell /usr/bin/ls src | /usr/bin/grep -F ".c")
objfiles:=$(cfiles:%.c=obj/%.o)

.PHONY: clean run all debug release testcode

all:CFLAGS:=$(CFLAGS) -DDEBUG
all:$(OBJPATH) run testcode
run:$(BIN)
	./$(BIN)
test:test.c
	 $(CC) $(CFLAGS) $(objfiles) test.c -o test 
testcode:test
	./test
	

release: CFLAGS:=$(CFLAGS) -O2
release: clean
release: $(BIN) testcode

debug: CFLAGS:=$(CFLAGS) -DDEBUG
debug: clean
debug: $(BIN) testcode
debug:
	$(DEBUGGER) $(BIN)

$(OBJPATH):
	mkdir $(OBJPATH)

$(OBJPATH)/%.o:src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):$(objfiles) test
	$(CC) $(objfiles) $(LDFLAGS) -o $@

clean:
	rm -f $(OBJPATH)/*.o
	rm -f ./test

