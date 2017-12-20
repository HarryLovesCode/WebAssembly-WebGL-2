CC = emcc
SRCS = main.c
FILES = $(addprefix src/, $(SRCS)) # Add 'src/' to each source
OBJS = $(FILES:.c=.o) # Modify file extensions of FILES
EOPT = USE_WEBGL2=1 FULL_ES3=1 USE_GLFW=3 # Emscripten specific options
EOPTS = $(addprefix -s $(EMPTY), $(EOPT))	# Add '-s ' to each option

# Builds necessary files
build: $(OBJS)
		-mkdir build
		$(CC) $(FILES) -O3 $(EOPTS) -o build/index.html

# Removes object files, but leaves build for serving
dist: build
		rm $(OBJS)

# Cleans up object files and build directory
clean:
		rm -rf build
		rm $(OBJS)
