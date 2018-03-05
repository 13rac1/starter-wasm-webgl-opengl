#include <stdio.h>
#include <stdlib.h>

// Include the Emscripten library only if targetting WebAssembly
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#define GLFW_INCLUDE_ES3
#endif

#include <GLFW/glfw3.h>

GLFWwindow* window;

// Handle GLFW Errors
static void error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

// Handle key presses
static void key_callback(GLFWwindow* window, int key, int scancode, int action,
                         int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void force_exit() {
#ifdef __EMSCRIPTEN__
  emscripten_force_exit(EXIT_FAILURE);
#else
  exit(EXIT_FAILURE);
#endif
}

// Generate the frame data.
static void generate_frame() {
  // Clear the window with the background color
  glClear(GL_COLOR_BUFFER_BIT);
  // Flip the double buffer
  glfwSwapBuffers(window);
  // Handle any events
  glfwPollEvents();
}

int main() {
  // Setup the Error handler
  glfwSetErrorCallback(error_callback);

  // Start GLFW
  if (!glfwInit()) {
    fprintf(stderr, "Error: GLFW Initialization failed.");
    force_exit();
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  // Create the display window
  window = glfwCreateWindow(640, 480, "Demo", NULL, NULL);
  if (!window) {
    fprintf(stderr, "Error: GLFW Window Creation Failed");
    glfwTerminate();
    force_exit();
  }
  // Setup the Key Press handler
  glfwSetKeyCallback(window, key_callback);
  // Select the window as the drawing destination
  glfwMakeContextCurrent(window);

  // Near white background
  glClearColor(0.9f, 0.9f, 0.9f, 0.0f);

  // Run the loop correctly for the target environment
#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(generate_frame, 0, false);
#else
  // Display the window until ESC is pressed
  while (!glfwWindowShouldClose(window)) {
    generate_frame();
  }
  // Clean up
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
#endif
}
