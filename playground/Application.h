#pragma once
#include <memory>
#include "Window.h"

using namespace std;

namespace QuantumPort {
	namespace playground {
		class Application {
			public:
				Application();
				~Application();
				bool init();
				bool run(shared_ptr<Window> window);
			private:
				shared_ptr<Window> _window;
				bool _initialized;
		};
	}
}
