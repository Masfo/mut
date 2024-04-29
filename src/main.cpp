
#include <windows.h>

import std;
import Deckard;
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

struct CommandResult
{
	std::chrono::duration<float> process_time;
	std::optional<i32>           exit_code{};
};

CommandResult run_command(const std::string &command, fs::path folder = fs::current_path())
{
	CommandResult command_result;

	PROCESS_INFORMATION pi{};
	STARTUPINFOA        si = {sizeof(STARTUPINFO)};
	si.hStdOutput          = GetStdHandle(STD_OUTPUT_HANDLE);
	si.hStdInput           = GetStdHandle(STD_INPUT_HANDLE);
	si.hStdError           = GetStdHandle(STD_ERROR_HANDLE);

	std::string args = "cmd /c " + command;

	auto start = std::chrono::system_clock::now();
	if (auto result = CreateProcessA(nullptr, (LPSTR)args.c_str(), nullptr, nullptr, FALSE, 0, nullptr, folder.string().c_str(), &si, &pi);
		!result)
	{
		return command_result;
	}

	// TODO: Add timeout parameter
	WaitForSingleObject(pi.hProcess, INFINITE);

	auto end = std::chrono::system_clock::now();

	//
	DWORD exit_code = 0;
	if (GetExitCodeProcess(pi.hProcess, &exit_code) != 0)
		command_result.exit_code = exit_code;

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	command_result.process_time = end - start;

	return command_result;
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
	std::print("mut {} ({}), ", mut::version_string, mut::calver);
	std::println("deckard {} ({})", DeckardBuild::version_string, DeckardBuild::calver);
#endif

	// mut edit (opens current folders .mut file, creates if not)
	// mut

	auto result = run_command("sample.exe");
	std::println("Took: {} - {}", result.process_time, result.exit_code ? *result.exit_code : -1);

	result = run_command("sample2.exe");
	std::println("Took: {} - {}", result.process_time, result.exit_code ? *result.exit_code : -1);

	result = run_command("sample3.exe");
	std::println("Took: {} - {}", result.process_time, result.exit_code ? *result.exit_code : -1);

	for (int count = 0; count < argc; count++)
		std::println("  argv[{}]   {}", count, argv[count]);

	std::vector<std::string> params(argv + 1, argv + argc);
	std::string              joined_params;
	for (const auto &p : params | std::views::join_with(' '))
		joined_params += p;

	/*
	std::string lineInput;
	while (std::getline(std::cin, lineInput))
	{
		if (lineInput.empty())
			break;

		std::println("PIPED: {}", lineInput);
	}
	*/
	std::println("P: {}", joined_params);

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
