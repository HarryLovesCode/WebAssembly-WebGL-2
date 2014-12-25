Emscripten GLFW3 Basic Program
==============================

Hello,

First off, let me preface this README by saying that the repository here is NOT a project. Instead, it is a small example of GLFW3 running in the web browser having been ported using Emscripten. You can find the tutorial page for GLFW3 [here](http://www.glfw.org/docs/latest/quick.html). 

Take note: this is written in the C language and it DOES NOT use modern OpenGL (programmable pipeline). Instead, it is using deprecated OpenGL just like the small "Getting Started" page shows on the GLFW3 website. It was NOT my intention to show how to port a full application, but rather to just create a working demonstration.

To compile this code:
- Make sure that Emscripten is added to your path
  - If you're on Linux or Mac, make sure that you `cd` to the root directory of "emsdk_portable"
  - Issue the following command `source ./emsdk_env.sh`
  - DO NOT CLOSE THE TERMINAL WINDOW
- Clone this directory wherever you want
  - Use the command `git clone "https://github.com/IcyTesseract/Emscripten-GLFW3-Basic-Program.git"`
- `cd` to the root of the newly cloned directory
- Make a build directory
  - `mkdir build`
- Compile using Emscripten
  - `emcc -O3 -s USE_GLFW=3 -s LEGACY_GL_EMULATION=1 src/main.c -o build/index.html`

Finally, you should go ahead and start a web server as some browsers do not support browser file access. The easiest way to do this is to launch Python (if you have it) using the following command:

`python -m SimpleHTTPServer 8080` then open your browser to `localhost:8080` (Firefox based browsers are best) and tada!