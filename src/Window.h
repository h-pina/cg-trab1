#pragma once
#include <GL/freeglut.h>

namespace CG {

	struct WindowConfig{
		const char* title;
		int width;
		int height;
	};
	
	class Window {
		public:
			Window(const char* title, int width, int height );
			void setWindowSize(int width, int height);
			int getWidth();
			int getHeight();
		private:
			GLuint m_window;
			WindowConfig m_windowConfig;
			
	};
}
