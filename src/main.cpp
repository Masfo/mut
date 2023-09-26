
import std;
import ModuleTest;
import secret_module;

int main(int, char **)
{
	std::println("Hello world {} {}", ModuleTest::return_int(), secret::mul2(6));

	// PikuModules -> cmake and modules, git submodule thing
	// mut - simple version first, just run command on filechange (just one file, no wildcard)
	// new aoc template
	// Piku module: open a new win32 window, resize handler etc.

	return 0;
}
