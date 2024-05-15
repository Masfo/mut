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

struct CommandResult
{
	std::chrono::duration<float> process_time;
	std::optional<i32>           exit_code{};
	std::string                  stdout_str;
	std::string                  stderr_str;
};

CommandResult run_command(const std::string &command, fs::path folder = fs::current_path())
{
	CommandResult command_result;

	// Create pipe and read stdout/stderr to string

	PROCESS_INFORMATION pi{};
	STARTUPINFOA        si = {sizeof(STARTUPINFO)};
	si.dwFlags             = STARTF_USESTDHANDLES;
	si.hStdOutput          = GetStdHandle(STD_OUTPUT_HANDLE);
	si.hStdInput           = GetStdHandle(STD_INPUT_HANDLE);
	si.hStdError           = GetStdHandle(STD_ERROR_HANDLE);

	// std::string args = "cmd /c " + command;
	std::string args = "cmd /c " + command;
	args             = "";

	if (command.empty())
	{
		std::println(std::cerr, "no executable set");
		return {};
	}

	std::println("");

	auto start = std::chrono::system_clock::now();

	// ExpandEnvironmentStringsA
	// When you use cmd.exe, it performs the expansion for you. CreateProcess
	// does not so you will need to do it before calling CreateProcess.
	// Alternatively you could use ShellExecute which will expand environment strings.

	// void *pEnv = nullptr;
	// char  cmd[4096];

	// strcpy(cmd,command);
	// ExpandEnvironmentStringsA(command.data(), cmd, sizeof(cmd) - 1);

	if (auto result = CreateProcessA(
			nullptr, (LPSTR)command.c_str(), nullptr, nullptr, TRUE, CREATE_UNICODE_ENVIRONMENT, 0, folder.string().c_str(), &si, &pi);
		result == 0)
	{
		command_result.exit_code = GetLastError();
		std::println(std::cerr, "Could not run '{}' - {}", command, *command_result.exit_code);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		return command_result;
	}

	// TODO: Add timeout parameter
	u32 timeout = 1000;
	if (auto wait = WaitForSingleObject(pi.hProcess, timeout); wait != 0)
	{
		std::println("");
		if (wait == WAIT_TIMEOUT)
		{
			std::println("Timeout: {:x}", GetLastError());
		}
		else
		{
			std::println("Failed: {:x}", GetLastError());
		}

		command_result.exit_code = GetLastError();
		return command_result;
	}

	auto end = std::chrono::system_clock::now();
	std::println("");

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
	std::print("mut {} ({}), ", mut::build::version_string, mut::build::calver);
	std::println("deckard {} ({})", deckard_build::build::version_string, deckard_build::build::calver);
#endif

	// mut edit (opens current folders .mut file, creates if not)
	// mut
	{
		archive::file f("sqlite3.db");
		f.exec("create table if not exists dummy(id integer primary  key, email TEXT not null unique)");
	}
	if (argv[1] == nullptr)
	{
		std::println(std::cerr, "mut needs program to run: mut <program>");
		return -1;
	}

	auto result = run_command(argv[1]);
	std::println("Took: {} - {}", result.process_time, result.exit_code ? *result.exit_code : 666);

	for (int count = 0; count < argc; count++)
		std::println("  argv[{}]   {}", count, argv[count]);

	std::vector<std::string> params(argv + 1, argv + argc);
	std::string              joined_params;
	for (const auto &p : params | std::views::join_with(' '))
		joined_params += p;

	std::string lineInput;
	while (std::getline(std::cin, lineInput))
	{
		if (lineInput.empty())
			break;

		std::println("PIPED: {}", lineInput);
	}

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
