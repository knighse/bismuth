#ifndef BISMUTH_TRI
#define BISMUTH_TRI

#include <GL/gl.h>

namespace bismuth {
	class Tri {
		public:
			vec3 a; //Three points of the triangle
			vec3 b;
			vec3 c;
			
			Tri(vec3 ta, vec3 tb, vec3 tc)
			: a(ta), b(tb), c(tc) {
				
			}
			
			Tri()
			: a(0, 0, 0), b(0, 0, 0), c(0, 0, 0) {
				
			}
	};
}

#endif
