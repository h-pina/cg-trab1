#include <GL/gl.h>
namespace CG{
	
	class Tex2D{
		public:
			Tex2D() = default;
			Tex2D(const char* path,float* coord);
			void use();
			int getId();

			void remapTexCrop(float* coord);
			float* getTexCrop();
			void defineTexCrop(int x_index,int y_index);

		private:
			float texCoord[4];
		
			GLuint m_texId;
	};

}
