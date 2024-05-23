#include <moveGem.hpp>

int prevRow = -1, prevCol = -1;

void mouse_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        int row = static_cast<int>(ypos / SQUAREHEIGHT);
        int col = static_cast<int>(xpos / SQUAREWIDTH);

        if ((prevRow != -1 && prevCol != -1) && (abs(prevRow-row) <= 1 && abs(prevCol - col) <= 1 && !(abs(prevRow-row) == 1 && abs(prevCol - col) == 1))) {
            board->swap(prevRow, prevCol, row, col);
            prevRow = -1;
            prevCol = -1;
        }else{
            prevRow = row;
            prevCol = col;
        }
    }
}