#include <GL/gl.h>
namespace CG{
	
	class Tex2D{
		public:
			Tex2D() = default;
			Tex2D(const char* path,float* coord);
			void use();

			void remapTexCrop(float* coord);
			float* getTexCrop();
			void defineTexCrop();

		private:
			float* texCoord;
		
			GLuint m_texId;
	};

}
