WebAssembly WebGL 2
===

This repository is NOT a project, it is more of a getting started / simple tech demo. This demonstrates Emscripten compiling code then outputting `wasm` to run in a WebAssembly capable web browser that supports WebGL 2. That said, no WebGL 2 specific code is currently in the repository.

# Compilation and Serving

- [Download or Compile the Toolchain](http://webassembly.org/getting-started/developers-guide/).
- Clone this directory wherever you want (`git clone "https://github.com/HarryLovesCode/WebAssembly-WebGL-2"`)
- `cd` to the root of the newly cloned directory
- Use the makefile to either build, clean up, or make a distribution version (build directory only) of the repo
    - Build: `make`
    - Clean: `make clean`
    - Build, but remove objects leaving the `build` dir: `make dist`
- You can then use `python -m SimpleHTTPServer 8080` and open your browser to `localhost:8080`.
