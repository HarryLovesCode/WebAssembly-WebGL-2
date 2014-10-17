Emscripten GLFW3 Basic Program
==============================

Hello,

First off, I'll begin by saying that this is NOT a project. This is just a small example of GLFW3 running in Emscripten. You can find the tutorial page for GLFW3 [here](http://www.glfw.org/docs/latest/quick.html). 

To compile this code, use the following command (assuming you have Emscripten properly installed and added to your path):

```sh
emcc -O3 -s USE_GLFW=3 -s LEGACY_GL_EMULATION=1 test.cpp -o out.html
```

This will create a HTML file called `out.html` and 2 other files (JavaScript and memory file). Then you move to the directory where the output is located and run:

```sh
python -m SimpleHTTPServer 8080
```

Finally, open your web browser to `localhost:8080` and the code will run! 

#### WARNING!
This code runs much, much better in Firefox. Chromium web browsers take forever to ready the program.
