
namespace CG {
	namespace Primitives {
		struct Point{
			float x;
			float y;
		};

		struct Color{
			float R;
			float G;
			float B;
		};
			
		void drawSquare(Color color, Point center, float lenght, float height);
		void drawTriangle(Color color, Point center, int sideLenght);
		void drawCircle(Color color, Point center, float radius, float resolution);
	}
}

