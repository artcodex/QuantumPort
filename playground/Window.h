#pragma once
#include <SDL.h>

namespace QuantumPort {
	namespace playground {
		class Window {
			public:
				bool show();
				void quit();
				void clear();
				void present();
				~Window();
			private:
				bool _showFPS;
				SDL_Window *_window;
				SDL_GLContext _context;
		};
	}
}
