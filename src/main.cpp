#include <windows.h>
#include <shellapi.h>

import std;
import deckard;
#ifndef _DEBUG
import mut;
#endif

using namespace deckard;
using namespace std::chrono_literals;
namespace fs = std::filesystem;

std::string input(std::string_view ask)
{
	std::string ret;
	std::print("{}", ask);
	std::getline(std::cin, ret);
	return ret;
}



bool match(std::string_view pattern, std::string_view str)
{
	size_t i = 0, j = 0, iStar = 0, jStar = 0;

	while (i < str.length())
	{
		if (j < pattern.length() && (pattern[j] == str[i] || pattern[j] == '?'))
		{
			i++;
			j++;
		}
		else if (j < pattern.length() && pattern[j] == '*')
		{
			iStar = i;
			jStar = j;
			j++;
		}
		else if (iStar != -1)
		{
			i = iStar + 1;
			j = jStar + 1;
			iStar++;
		}
		else
		{
			return false;
		}
	}

	while (j < pattern.length() && pattern[j] == '*')
	{
		j++;
	}

	return j == pattern.length();
}

int main(int argc, char **argv)
{

	using namespace std::string_literals;

#ifndef _DEBUG
	std::print("mut {} ({}, {}), ", mut::build::version_string, mut::build::calver, mut::build::build_time_string);
	std::println(
		"deckard {} ({}, {})", deckard_build::build::version_string, deckard_build::build::calver, deckard_build::build::build_time_string);
#endif

	// mut edit (opens current folders .mut file, creates if not)
	// mut
	if (argv[1] == nullptr)
	{
		std::println(std::cerr, "mut needs program to run: mut <program>");
		return -1;
	}

	std::string arguments;
	 for (int i = 1; i < argc; i++)
	{
		arguments += argv[i];
		if (i < argc - 1)
			arguments += " ";
	}
	

	auto result = system::execute_process(arguments);
	std::println("Took: {} - exit result: {}", result.elapsed_time.count(), result.exit_code);

	for (int count = 0; count < argc; count++)
		std::println("  argv[{}]   {}", count, argv[count]);

	std::vector<std::string> params(argv + 1, argv + argc);
	std::string              joined_params;
	for (const auto &p : params | std::views::join_with(' '))
		joined_params += p;

	//std::string lineInput;
	//while (std::getline(std::cin, lineInput))
	//{
	//	if (lineInput.empty())
	//		break;
	//
	//	std::println("PIPED: {}", lineInput);
	//}
	//
	//std::println("P: {}", joined_params);

	// mut tests.exe "cls && tests"

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

	return 0;
}
