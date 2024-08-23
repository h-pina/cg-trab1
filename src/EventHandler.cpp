#include "Window.h"
#include "Renderer.h"

#include <GL/gl.h>
#include "EventHandler.h"

namespace CG {
	namespace EventHandler {
		Window* v_window = nullptr;
		Renderer* v_renderer = nullptr;

		void setInstances(Window* window, Renderer* renderer){
			v_window = window;
			v_renderer = renderer;
			
		}

		void windowResizeCallback(int width, int height){
			if(v_window != nullptr)
				v_window->setWindowSize(width, height);
		}

		void renderCallback(){
			if(v_renderer != nullptr)
				v_renderer->render();
		}
		void movePlayerWrapper(unsigned char key, int x, int y) {
			v_renderer->getScene()->getPlayer()->keyboardDown(key, x, y);
		}
		void restoreTexPos(unsigned char key, int x, int y) {
			v_renderer->getScene()->getPlayer()->keyboardUp(key, x, y);
		}
		
		void setupCallbacks(){
			glutReshapeFunc(windowResizeCallback);
			glutDisplayFunc(renderCallback);
			glutKeyboardFunc(movePlayerWrapper);
			glutKeyboardUpFunc(restoreTexPos);
		}
	}
}
