#ifndef BISMUTH_VECTOR3
#define BISMUTH_VECTOR3

namespace bismuth {
	class Vector3 {
		public:
			float x; //Coordinates of the vector
			float y;
			float z;
			
			Vector3(float tx, float ty, float tz)
			: x(tx), y(ty), z(tz) {
				
			}
	};
}

#endif
