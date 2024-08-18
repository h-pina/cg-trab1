#include "Application.h"

using namespace CG;

int main (int argc, char *argv[]) {
	CG::Application app =  CG::Application(&argc, argv);
	 app.run();
	return 0;
}
