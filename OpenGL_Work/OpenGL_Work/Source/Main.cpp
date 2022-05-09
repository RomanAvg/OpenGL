#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
void Right_Side() 
{

}
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

    bool side = 0;
    int count = 0;
    while (!glfwWindowShouldClose(window))
    {
        
        if (!side) {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);

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
            glRotatef(/*(float)glfwGetTime() **/count/** 50.f*/, 0.f, 1.f, 0.f);


            glBegin(GL_TRIANGLES);
            glColor4f(0.f, 1.f, 0.f, 1.0f); //green
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(-1.f, -1.f, 0.f);
            glVertex3f(1.f, -1.f, 0.f);
            glColor4f(1.f, 1.f, 0.f, 1.0f); //yellow
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(1.f, 1.f, 0.f);
            glVertex3f(-1.f, 1.f, 0.f);

            glColor4f(1.f, 0.f, 0.f, 0.5f); //red
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(1.f, -1.f, 0.f);
            glVertex3f(1.f, 1.f, 0.f);
            glColor4f(1.f, 0.f, 1.f, 0.5f); //purpule
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(-1.f, 1.f, 0.f);
            glVertex3f(-1.f, -1.f, 0.f);


            glEnd();

            glBegin(GL_QUADS);        // Draw The Cube Using quads
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);    // Color white
            glVertex3f(-1.0f, 1.0f, 0.0f);    // Top Right Of The Quad (Top)
            glVertex3f(-1.0f, -1.0f, 0.0f);    // Top Left Of The Quad (Top)
            glVertex3f(1.0f, -1.0f, 0.0f);    // Bottom Left Of The Quad (Top)
            glVertex3f(1.0f, 1.0f, 0.0f);
            glEnd();


            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        else {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);

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
            glRotatef(/*(float)glfwGetTime() **/count /** 50.f*/, 0.f, 1.f, 0.f);


            glBegin(GL_QUADS);        // Draw The Cube Using quads
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);    // Color white
            glVertex3f(-1.0f, 1.0f, 0.0f);    // Top Right Of The Quad (Top)
            glVertex3f(-1.0f, -1.0f, 0.0f);    // Top Left Of The Quad (Top)
            glVertex3f(1.0f, -1.0f, 0.0f);    // Bottom Left Of The Quad (Top)
            glVertex3f(1.0f, 1.0f, 0.0f);
            glEnd();

            glBegin(GL_TRIANGLES);
            glColor4f(0.f, 1.f, 0.f, 1.0f); //green
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(-1.f, -1.f, 0.f);
            glVertex3f(1.f, -1.f, 0.f);
            glColor4f(1.f, 1.f, 0.f, 1.0f); //yellow
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(1.f, 1.f, 0.f);
            glVertex3f(-1.f, 1.f, 0.f);

            glColor4f(1.f, 0.f, 1.f, 0.5f); //purpule
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(-1.f, 1.f, 0.f);
            glVertex3f(-1.f, -1.f, 0.f);
            glColor4f(1.f, 0.f, 0.f, 0.5f); //red
            glVertex3f(0.f, 0.f, 1.f);
            glVertex3f(1.f, -1.f, 0.f);
            glVertex3f(1.f, 1.f, 0.f);

            glEnd();            

            glBegin(GL_LINE);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 1.0f);
            glEnd();


            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        count++;

        if ((count-90) % 180 == 0) {
            side = !side;
        }
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}