#include <OpenGL/gl3.h>
#include "Window.h"


namespace QuantumPort {
	namespace playground {
		Window::~Window() {
			quit();
		}

		bool Window::show() {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			_window = SDL_CreateWindow("Playground", 0, 0, 1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); 
			if (!_window) {
				return false;
			}

			_context = SDL_GL_CreateContext(_window);
			if (!_context) {
				return false;
			}
			
			return true;
		}

		void Window::clear() {
			glClearColor(60, 0, 5, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::present() {
			if (_window) {
				SDL_GL_SwapWindow(_window);
			}
		}

		void Window::quit() {
			if (_window) {
				SDL_DestroyWindow(_window);
				_window = nullptr;
			}

			if (_context) {
				SDL_GL_DeleteContext(_context);
				_context = nullptr;
			}
		}
	}
}
