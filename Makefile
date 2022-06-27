
SRCS := $(shell find src -maxdepth 1 -name "*.c")
INCS := $(shell find include -maxdepth 1 -name "*.h")
DEPS := $(INCS) $(SRCS)
CFLAGS := -O1 -std=gnu11 -Wall -Werror -Wno-unused-result -Wno-unused-value -Wno-unused-variable

.PHONY clean

run:
	gcc $(CFLAGS) $(SRCS) -o build/sator

clean:
	rm build/*
