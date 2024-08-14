#pragma once
#include "GameObject.h"

namespace CG {
	class Shoot : public GameObject { // Added 'public' keyword
		public:

			Shoot(
				float* vertices,
				const char* textureFile,
                int damage, 
				float SpeedY, 
				float SpeedX, 
				float* texcoord
			);

			//fill obj with default color and 
			//create at center
			Shoot(
                float* vertices,
                int damage
            ); 

			int getDamage(); // Getter for damage
			void setDamage(int damage); // Setter for damage
			int getStatus();
			void changeStatus();
			

		private:
			int m_damage; // Added damage attribute
			int m_active;
	};
}