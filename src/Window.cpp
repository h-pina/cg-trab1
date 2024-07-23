#include "Window.h"


namespace CG {
	Window::Window(const char* title, int width, int height )
		: m_windowConfig{title, width, height}
	{
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    m_window = glutCreateWindow(title); 
	}
	void Window::setWindowSize(int width, int height){
		glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -100, 100);

    float windowAspectRatio = ((float)width)/height;
    float worldAspectRatio = 1.0f;
    if (windowAspectRatio < worldAspectRatio) {
        float hViewport = width / worldAspectRatio;
        float yViewport = (height - hViewport)/2;
        glViewport(0, yViewport, width, hViewport);
    }
    else if (windowAspectRatio > worldAspectRatio) {
        float wViewport = ((float)height) * worldAspectRatio;
        float xViewport = (width - wViewport)/2;
        glViewport(xViewport, 0, wViewport, height);
    } else {
        glViewport(0, 0, width, height);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
		m_windowConfig.width = width;
		m_windowConfig.height = height;
	}

	int Window::getWidth(){
		return m_windowConfig.width;
	}

	int Window::getHeight(){
		return m_windowConfig.height;
	}
}
