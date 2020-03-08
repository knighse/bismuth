#ifndef BISMUTH_NODE
#define BISMUTH_NODE

#include <vector>
#include "Event.cpp"

using std::vector;

namespace bismuth {
	class Node {
		private:
			void event(Event *e) {
				//Remember to delete event pointers when making custom nodes
				delete e;
			}
			vector<Node> *children = new vector<Node>();
			Node *parent = nullptr;
		
		public:
			void addChild(Node *child) {
				children->push_back(*child);
			}
			
			Node() {
				parent = nullptr;
			}
			
			Node(Node *tparent) {
				parent = tparent;
				parent->addChild(this);
			}
			
			virtual ~Node() {
				delete parent;
				delete children;
			}
	
			void triggerCreate() {
				event(new Event(EVENT_CREATE));
				for (Node child : *children) {
					child.event(new Event(EVENT_CREATE));
				}
			}
			
			void triggerDestroy() {
				event(new Event(EVENT_DESTROY));
				for (Node child : *children) {
					child.event(new Event(EVENT_DESTROY));
				}
			}
			
			void triggerUpdate() {
				event(new Event(EVENT_UPDATE));
				for (Node child : *children) {
					child.event(new Event(EVENT_UPDATE));
				}
			}
	};
}

#endif
