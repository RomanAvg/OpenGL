#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    GLFWwindow* window;
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Chapter 1: Simple GLFW Example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window); 
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = (float)width / (float)height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT); 
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float)glfwGetTime() * 50.f, 0.f, 1.f, 0.f);

        /*glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);*/

        /*glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();*/
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(0.f, 0.f, 1.f);
        glVertex3f(1.f, -1.f, 0.f);
        glVertex3f(1.f, 1.f, 0.f);
        glColor3f(1.f, 1.f, 0.f);
        glVertex3f(0.f, 0.f, 1.f);
        glVertex3f(1.f, 1.f, 0.f);
        glVertex3f(-1.f, 1.f, 0.f);
        glColor3f(1.f, 0.f, 1.f);
        glVertex3f(0.f, 0.f, 1.f);
        glVertex3f(-1.f, 1.f, 0.f);
        glVertex3f(-1.f, -1.f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.f, 0.f, 1.f);
        glVertex3f(-1.f, -1.f, 0.f);
        glVertex3f(1.f, -1.f, 0.f);
        glEnd();

        glBegin(GL_QUADS);        // Draw The Cube Using quads
        glColor3f(1.0f, 1.0f, 1.0f);    // Color Blue
        glVertex3f(-1.0f, 1.0f, 0.0f);    // Top Right Of The Quad (Top)
        glVertex3f(-1.0f, -1.0f, 0.0f);    // Top Left Of The Quad (Top)
        glVertex3f(1.0f, -1.0f, 0.0f);    // Bottom Left Of The Quad (Top)
        glVertex3f(1.0f, 1.0f, 0.0f);
        glEnd();

        //glBegin(GL_QUADS);        // Draw The Cube Using quads
        //glColor3f(0.0f, 1.0f, 0.0f);    // Color Blue
        //glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Top)
        //glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Top)
        //glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
        //glVertex3f(1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
        //glColor3f(1.0f, 0.5f, 0.0f);    // Color Orange
        //glVertex3f(1.0f, -1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
        //glVertex3f(-1.0f, -1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
        //glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Bottom)
        //glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Bottom)
        //glColor3f(1.0f, 0.0f, 0.0f);    // Color Red    
        //glVertex3f(1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
        //glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
        //glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
        //glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
        //glColor3f(1.0f, 1.0f, 0.0f);    // Color Yellow
        //glVertex3f(1.0f, -1.0f, -1.0f);    // Top Right Of The Quad (Back)
        //glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Left Of The Quad (Back)
        //glVertex3f(-1.0f, 1.0f, -1.0f);    // Bottom Left Of The Quad (Back)
        //glVertex3f(1.0f, 1.0f, -1.0f);    // Bottom Right Of The Quad (Back)
        //glColor3f(0.0f, 0.0f, 1.0f);    // Color Blue
        //glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
        //glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Left)
        //glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Left)
        //glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
        //glColor3f(1.0f, 0.0f, 1.0f);    // Color Violet
        //glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Right)
        //glVertex3f(1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
        //glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
        //glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Right)
        //glEnd();            // End Drawing The Cube

        glfwSwapBuffers(window);
        glfwPollEvents();


    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}