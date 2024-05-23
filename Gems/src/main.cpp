#include <main.hpp>

Board* board;
GLFWwindow* window;

int main() {
    
    board = new Board(GRIDWIDTH, GRIDHEIGHT);

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WIDTHWINDOW, HEIGHTWINDOW, "game", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_callback);


    while (!glfwWindowShouldClose(window)) {
        board->render();
    }
    

    glfwTerminate();
    return 0;
}
