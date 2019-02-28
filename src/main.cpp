#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 400, HEIGHT = 400;


// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.2" << std::endl;
    // Init GLFW
    glfwInit();

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);    
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    //将此设置为true，以便GLEW知道使用现代方法来检索函数指针和扩展
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }    

    const GLubyte* name = glGetString(GL_VENDOR); //返回负责当前OpenGL实现厂商的名字
    const GLubyte* biaoshifu = glGetString(GL_RENDERER); //返回一个渲染器标识符，通常是个硬件平台
    const GLubyte* OpenGLVersion =glGetString(GL_VERSION); //返回当前OpenGL实现的版本号
    const GLubyte* gluVersion= gluGetString(GLU_VERSION); //返回当前GLU工具库版本
    printf("OpenGL实现厂商的名字：%s\n", name);
    printf("渲染器标识符：%s\n", biaoshifu);
    printf("OpenGL实现的版本号：%s\n",OpenGLVersion );
    printf("GLU工具库版本：%s\n", gluVersion);
   
    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        /*---------------------------------------------*/
        /* Draw a triangle */
        //glBegin(GL_TRIANGLES);

        // glColor3f(1.0, 0.0, 0.0);    // Red
        // glVertex3f(0.0, 0.5, 0.0);

        // glColor3f(0.0, 1.0, 0.0);    // Green
        // glVertex3f(-0.5, 0.0, 0.0);

        // glColor3f(0.0, 0.0, 1.0);    // Blue
        // glVertex3f(1.0, 0.0, 0.0);
        /*---------------------------------------------*/
         /* Draw a triangle */
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        /*---------------------------------------------*/
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
