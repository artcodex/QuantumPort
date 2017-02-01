#include <SDL.h>
#include <iostream>
#include "Application.h"


namespace QuantumPort {
	namespace playground {
		Application::Application() :
			_window(nullptr),
			_initialized(false)
		{ }

		bool Application::init() {
			if (SDL_Init(SDL_INIT_VIDEO) < 0) {
				cout << "playground: error initialing SDL (" << SDL_GetError() << ")" << endl;
				return false;
			}

			_initialized = true;
			return true;
		}

		Application::~Application() {
			if (_initialized) {
				SDL_Quit();
			}
		}

		bool Application::run(shared_ptr<Window> window) {
			if (!window) {
				cout << "playground: Invalid window class" << endl;
				return false;
			}

			_window = window;
			if (!_window->show()) {
				cout << "playground: unable to load SDL window (" << SDL_GetError() << ")" << endl;
				return false;
			}

			bool quit = false;
			SDL_Event currentEvent;

			while(!quit) {
				SDL_PollEvent(&currentEvent);

				switch(currentEvent.type) {
					case SDL_QUIT:
						quit = true;
						_window->quit();
						break;
				}

				_window->clear();
				_window->present();
				SDL_Delay(1);
			}

			return true;
		}
	}
}
