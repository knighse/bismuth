#ifndef BISMUTH_BASE_NODE
#define BISMUTH_BASE_NODE

#include <fstream>
#include <string>
#include "Node.cpp"

using std::string;

namespace bismuth {
	class BaseNode : public Node {
		public:
			BaseNode(string fileName) {
			}
	};
}

#endif
