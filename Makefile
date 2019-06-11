CC=clang
CLANG_CFLAGS=-nostdinc --sysroot "/usr/lib/musl" -isystem "/usr/lib/musl/include"
CLANG_LDFLAGS=-fuse-ld=musl-clang -nostdlibinc --sysroot "/usr/lib/musl" -L-user-start -L"/usr/lib/musl/lib" -L-user-end
CFLAGS=$(CLANG_CFLAGS) -c -Wall -O0 -g -std=c11
LDFLAGS=$(CLANG_LDFLAGS) -lm -lpthread -lc
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=rod

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXECUTABLE)
