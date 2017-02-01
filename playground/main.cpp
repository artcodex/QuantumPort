#include <memory>
#include <stdlib.h>
#include <thread>
#include "Window.h"
#include "Application.h"

using namespace QuantumPort::playground;
using namespace std;

int main(int argc, char **argv) {
	Application app;

	if (!app.init()) {
		exit(-1);
	}

	if (!app.run(make_shared<Window>())) {
		exit(-1);
	}
}
