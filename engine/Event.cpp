#ifndef BISMUTH_EVENT
#define BISMUTH_EVENT

#define EVENT_NONE 0
#define EVENT_CREATE 1
#define EVENT_DESTROY 2
#define EVENT_UPDATE 3

namespace bismuth {
	class Event {
	public:
			int type = EVENT_NONE;
			
			Event(int ttype) {
				type = ttype;
			}
	};
}

#endif
