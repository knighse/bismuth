#include "renderer/Renderer.cpp"

using bismuth::Renderer;
using bismuth::Vector3;
using bismuth::Tri;

int main(int argc, char** argv) {
	Renderer::getInstance().init(argc, argv);
	
	Tri t(Vector3(-3.0f, 0.0f, -10.0f), Vector3(3.0f, 0.0f, -10.0f), Vector3(0.0f, 3.0f, -10.0f));
	float val = 0.0f;
	while (true) {
		t.b = Vector3(val, 0.0f, -10.0f);
		val += 0.1f;
		if (val >= 3.0f) {
			val = 0.0f;
		}
		Renderer::getInstance().addTri(t, true);
		
		glutMainLoopEvent();
	}
	
	glutLeaveMainLoop();
}
