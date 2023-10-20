
import std;
import Deckard;

using namespace deckard;

using SuperValue = int;

int main(int, char**)
{
	using namespace std::string_literals;

	std::println("Hello world");

	// mut - simple version first, just run command on filechange (just one file, no wildcard)
	// new aoc template
	// Piku module: open a new win32 window, resize handler etc.

	trace("this is debug");
	dbgln("debug line");


	auto print = [](auto const& view)
	{
		// `view` is of std::views::lazy_split_view::__outer_iterator::value_type
		dbg("[ ");
		// std::ranges::for_each(view | std::views::lazy_split("\n"), [](auto const& c) { dbg("{} ", c); });


		dbgln("]");
	};

	{
		std::string t{"-One-Two-Three-Four-Five-Six-"};
		const auto  dash      = [](char x, char y) { return not(x == '-' or y == '-'); };
		const auto  dash3     = [](char x) { return x == '-'; };
		const auto  not_empty = [](auto x) { return not x.empty(); };


		auto words = t | std::views::lazy_split('-') | std::views::filter(not_empty) | std::ranges::to<std::vector<std::string>>();
		for (const auto& word : words)
		{
			dbgln("{}", word);
		}

		trace("hello");
	}

	std::string      text{"Hello\nC++\nWorld\n\n1 => 2\n2 => 3\n3 => 4"};
	std::string_view delim{"\n\n"};
	std::string_view delim2{"\n"};

	auto groups       = std::views::split(text, delim) | std::ranges::to<std::vector<std::string>>();
	auto instructions = std::views::split(groups[0], '\n') | std::ranges::to<std::vector<std::string>>();
	auto opcodes      = std::views::split(groups[1], '\n') | std::ranges::to<std::vector<std::string>>();

	for (const auto& [i, ops] : std::views::enumerate(opcodes))
	{
		dbgln("{}. {}", i, ops);
	}

	trace("hello");

#if 0
	std::ranges::for_each(text | std::views::lazy_split(delim),
						  [](auto const& group)
						  {
							  dbgln("{");


							  auto words = std::views::split(group, "\n"sv) | std::ranges::to<std::vector<std::string>>();

							  for (const auto& c : words)
							  {
								  // dbgln("{}", *c);
								  for (auto const& i : c)
									  dbg("{}", i);
								  dbgln();
							  }
							  //
							  // dbgln("word: {}", typeid(word).name());
							  // for (auto const& c : word)
							  //{
							  //   dbgln("word itr: {}", typeid(c).name());
							  //
							  //  // dbgln("{}", *c);
							  //
							  //  dbg("[");
							  //
							  //  for (auto const& i : c)
							  //	  dbg("{}", i);
							  //  dbgln("]");
							  //}
							  dbgln("}");
						  });
#endif

	return 0;
}
