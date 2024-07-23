#include "Tex2D.h"
#include <iostream>
#include <SOIL/SOIL.h>

namespace CG {
	Tex2D::Tex2D(const char* path){
    m_texId = SOIL_load_OGL_texture(
                           path,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );
    if (m_texId == 0) {
			std::cout << "Erro do SOIL: '%s'\n" <<  SOIL_last_result() << std::endl;
    }
		
	}

	void Tex2D::use(){
    glBindTexture(GL_TEXTURE_2D, m_texId);
	}

	void Tex2D::remapTexCrop(){ }
	float* Tex2D::getTexCrop() { 
		return nullptr;
	}
}

