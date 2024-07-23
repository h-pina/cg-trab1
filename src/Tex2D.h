#include <GL/gl.h>
namespace CG{
	
	class Tex2D{
		public:
			Tex2D() = default;
			Tex2D(const char* path);
			void use();

			void remapTexCrop();
			float* getTexCrop();


		private:
			GLuint m_texId;
	};

}
