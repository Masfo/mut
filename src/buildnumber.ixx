module;
#include <cstdint>

export module mut;
export namespace mut
{
	 // You can modify major and minor
	constexpr uint32_t major = 0;
	constexpr uint32_t minor = 0;

	 // Do not modify these
	constexpr uint32_t build = 316;
	
	constexpr uint32_t version = major * 10000 + minor * 1000 + build;
	constexpr uint64_t random_seed = 0xac41c35f6d7b117;
	
	constexpr char version_string[] = "v0.0.316";
	constexpr char build_time_string[] = "2023-10-27 18:30:23";
	constexpr char phrase[] = "magnify-crepe-dubiously";
	constexpr char calver[] = "2023.43.316";
	constexpr char uuid[] = "C3E20645-4BD0-49FA-AC54-4DD4BDEF840F";

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
