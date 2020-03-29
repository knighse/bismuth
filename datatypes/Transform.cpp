#ifndef BISMUTH_TRANSFORM
#define BISMUTH_TRANSFORM

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace bismuth {
	class Transform {
		public:
			vec3 pos;
			quat rotation;
			
			Transform(float tx, float ty, float tz)
			: x(tx), y(ty), z(tz) {
				
			}
	};
}

#endif
