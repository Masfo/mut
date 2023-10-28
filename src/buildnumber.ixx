module;
#include <cstdint>

export module mut;
export namespace mut
{
	 // You can modify major and minor
	constexpr uint32_t major = 0;
	constexpr uint32_t minor = 0;

	 // Do not modify these
	constexpr uint32_t build = 324;
	
	constexpr uint32_t version = major * 10000 + minor * 1000 + build;
	constexpr uint64_t random_seed = 0xd0a20be387078d73;
	
	constexpr char version_string[] = "v0.0.324";
	constexpr char build_time_string[] = "2023-10-27 18:43:49";
	constexpr char phrase[] = "astronaut-silliness-alibi";
	constexpr char calver[] = "2023.43.324";
	constexpr char uuid[] = "B89539B8-EB08-42C2-AD80-E132B72426A5";

	// Copy paste to import to your project
	/*
		constexpr auto major = mut::major;
		constexpr auto minor = mut::minor;
		constexpr auto build = mut::build;
		constexpr auto version = mut::version;
		constexpr auto random_seed = mut::random_seed;
			
		constexpr auto version_string = mut::version_string;
		constexpr auto build_time_string = mut::build_time_string;
		constexpr auto phrase = mut::phrase;
		constexpr auto calver = mut::calver;
		constexpr auto uuid = mut::uuid;
	*/
}
