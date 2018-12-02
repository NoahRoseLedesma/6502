# the build target executable:
TARGET := emulator
SRCS := src/*.c

all: $(TARGET)
$(TARGET):
	clang $(SRCS) -o $(TARGET)

clean:
	$(RM) $(TARGET)