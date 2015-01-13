CC = emcc

SRCS = main.c
FILES = $(addprefix src/, $(SRCS))			# Add 'src/' to each source
OBJS = $(FILES:.c=.o)						# Modify file extensions of FILES

EOPT = USE_GLFW=3 LEGACY_GL_EMULATION=1 	# Emscripten specific options
EOPTS = $(addprefix -s $(EMPTY), $(EOPT)) 	# Add '-s ' to each option

# Builds necessary files
build: $(OBJS)
		mkdir build
		$(CC) $(FILES) -O2 $(EOPTS) -o build/index.html

dist: build
		rm $(OBJS)

# Cleans up object files and build directory
clean:
		rm -rf build
		rm $(OBJS)