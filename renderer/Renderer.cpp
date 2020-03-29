#ifndef BISMUTH_GLUT_INTERFACE
#define BISMUTH_GLUT_INTERFACE

#include <list>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "../datatypes/Tri.cpp"

using std::list;

namespace bismuth {
	class Renderer {
		private:
			list<Tri> dynamicTris;
			Tri staticTris[1000];
			int maxStaticTris = 0;
			bool staticEnabled = false;
			bool dynamicEnabled = false;
			
			void renderTri(Tri t) {
				glVertex3f(t.a.x, t.a.y, t.a.z);
				glVertex3f(t.b.x, t.b.y, t.b.z);
				glVertex3f(t.c.x, t.c.y, t.c.z);
			}
			
			void draw() {
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear screen and transformation matrix
				glLoadIdentity();
				
				glBegin(GL_TRIANGLES);
				
				if (staticEnabled) { //Iterate through static triangles if there are any
					for (int i = 0; i < maxStaticTris; i++) {
						renderTri(staticTris[i]);
					}
				}
				
				if (dynamicEnabled) { //Iterate through dynamic triangles if there are any
					list<Tri>::iterator it;
					for (it = dynamicTris.begin(); it != dynamicTris.end(); ++it) {
						renderTri(*it);
					}
				}
				
				glEnd();
			
				//Clear the dynamic triangles
				dynamicTris.clear();
			
				glutSwapBuffers(); //Swap this buffer to the display
				glutPostRedisplay(); //Continuously re-draw
			}
			
			void reshape(int width, int height) {
				if (height == 0) { //Could crash without these protections
					height = 1;
				}
				
				if (width == 0) {
					width = 1;
				}
				
				glMatrixMode(GL_PROJECTION); //Setup the projection matrix
				glLoadIdentity();
				
				glViewport(0, 0, width, height); //Update width and height
				
				float aspect = (float)width / (float)height; //Calculate the aspect ratio (floats for precision)
				gluPerspective(70, aspect, 1, 8000);
				
				glMatrixMode(GL_MODELVIEW);
			}
			
			//Stupid static functions, are, indeed stupid. Please ignore below workaround for C library limitations
			static void sdraw() {
				Renderer::getInstance().draw();
			}
			
			static void sreshape(int w, int h) {
				Renderer::getInstance().reshape(w, h);
			}
			
			//Singleton garbage, C libraries really stink don't they. Please ignore this.
			Renderer() : dynamicTris() {}
	        Renderer(Renderer const&);
	        void operator = (Renderer const&);
		
		public:
			void addTri(Tri t, bool dyn) {
				if (dyn) {
					dynamicEnabled = true;
					dynamicTris.push_back(t);
				} else {
					staticEnabled = true;
				}
			}
			
			void init(int argc, char** argv) { //regular GLUT init things
				glutInit(&argc, argv);
				
				glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
				glutInitWindowPosition(0, 0);
				glutInitWindowSize(480, 360);
				glutCreateWindow("Bismuth v0.0.1");
				
				glutDisplayFunc(sdraw);
				glutReshapeFunc(sreshape);
			}
			
			//More singleton stuff, ignore
			static Renderer& getInstance() {
	            static Renderer instance;
	            return instance;
	        }
	};
}

#endif
