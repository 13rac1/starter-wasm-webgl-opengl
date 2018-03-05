#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>

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

int main() {
  // Start GLFW
  if (!glfwInit()) {
    fprintf(stderr, "Error: GLFW Initialization failed.");
    exit(EXIT_FAILURE);
  }
  // Setup the Error handler
  glfwSetErrorCallback(error_callback);

  // Create the display window
  GLFWwindow* window = glfwCreateWindow(640, 480, "Demo", NULL, NULL);
  if (!window) {
    fprintf(stderr, "Error: GLFW Window Creation Failed");
    exit(EXIT_FAILURE);
  }
  // Setup the Key Press handler
  glfwSetKeyCallback(window, key_callback);
  // Select the window as the drawing destination
  glfwMakeContextCurrent(window);

  // Near white background
  glClearColor(0.9f, 0.9f, 0.9f, 0.0f);

  // Display the window until ESC is pressed
  while (!glfwWindowShouldClose(window)) {
    // Clear the window with the background color
    glClear(GL_COLOR_BUFFER_BIT);
    // Flip the double buffer
    glfwSwapBuffers(window);
    // Handle any events
    glfwPollEvents();
  }

  // Clean up
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
