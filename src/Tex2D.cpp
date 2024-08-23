#include "Tex2D.h"
#include <iostream>
#include <SOIL/SOIL.h>
#include <unistd.h> 
#include <cstring> 

namespace CG {
	Tex2D::Tex2D(const char* path, float* coord){
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            
        } else {
            perror("getcwd() error");
        }
        
        char fullPath[200]; // Certifique-se de que o buffer é grande o suficiente
        strcpy(fullPath, cwd);
        strcat(fullPath, "/");
        strcat(fullPath, path);


        
        
        
        m_texId = SOIL_load_OGL_texture(
                            fullPath,
                            SOIL_LOAD_AUTO,
                            SOIL_CREATE_NEW_ID,
                            SOIL_FLAG_INVERT_Y
                        );
        std::cout << path << "\t tex_id="<<m_texId << std::endl;
        if (m_texId == 0) {
                std::cout << "Erro do SOIL ao carregar: \"" << fullPath << "\"\n" <<  SOIL_last_result() << std::endl;
        }
        
        

        texCoord[0]=coord[0];
        texCoord[1]=coord[1];
        texCoord[2]=coord[2];
        texCoord[3]=coord[3];
        
	}

	void Tex2D::use(){
        
        glBindTexture(GL_TEXTURE_2D, m_texId);
        
	}

	void Tex2D::remapTexCrop(float* coord){ 
        texCoord[0]=coord[0];
        texCoord[1]=coord[1];
        texCoord[2]=coord[2];
        texCoord[3]=coord[3];
    }

    void Tex2D::defineTexCrop(int x_index,int y_index){

        glTexCoord2f(texCoord[x_index], texCoord[y_index+2]);

    }

	float* Tex2D::getTexCrop() { 
		return texCoord;
	}
    int Tex2D::getId(){
        return m_texId;
    }
}

