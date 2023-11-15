
#include <windows.h>

import std;
import Deckard;
#ifndef _DEBUG
import mut;
#endif

using namespace deckard;

std::string input(std::string_view ask)
{
	std::string ret;
	std::print("{}", ask);
	std::getline(std::cin, ret);
	return ret;
}

int main(int argc, char **argv)
{
	using namespace std::string_literals;

#ifndef _DEBUG
	std::println("mut {} ({})", mut::version_string, mut::build_time_string);
	std::println("\t * deckard {}", DeckardBuild::calver);
#endif

	std::vector<std::string> params(argv + 1, argv + argc);


	// mut - simple version first, just run command on filechange (just one file, no wildcard)
	// check if mut.txt has same entrys, directorys must have \ appended
	//				[data\] dir, all under data dir
	//				[data]  file

	// ignore = *.exe;*.txt;*.c;*.cpp;*.h
	// ignore = *.tmp ; add to ignore on another line
	//
	// [folder\] ; only files under folder
	// [folder\*] ; files and other folders
	//
	// [*.vs] ; vertex shaders
	// glslc -c ${name} -o stem.bin
	//
	// [*.fs] ; fragment shaders

	// [*.tga;*.bmp;*.png] ; any of these

	// [mut.exe]		;
	// call mut.exe   ; runs

	// [mut.exe:1]		; another cmd window run 'mut -m1', runs only marked 1, default is 0 for all
	// ls ${root}


	// ${file} - filename w/ extension
	// ${base} - filename w/o extension
	// ${path} - full path w/ file
	// ${root} - full path w/o file
	// ${ext}  - file extension

	// ShellExecuteA(nullptr, "open", ".test.mut", nullptr, nullptr, 1);
	// trace("{}", GetLastError());


	trace("this is debug 1  3 2 2");


	return 0;
}
