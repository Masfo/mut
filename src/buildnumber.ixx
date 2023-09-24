module;
#include <cstdint>

export module mut;
export namespace mut
{
	 // You can modify major and minor
	constexpr uint32_t major = 0;
	constexpr uint32_t minor = 0;

	 // Do not modify these
	constexpr uint32_t build = 3;
	
	constexpr uint32_t version = major * 100 + minor * 10 + build;
	constexpr uint64_t random_seed = 0x322a199d77c2f9ae;
	
	constexpr char version_string[] = "v0.0.3";
	constexpr char build_time_string[] = "2023-09-24 15:15:37";
	constexpr char phrase[] = "faucet-grope-private";
	constexpr char calver[] = "2023.38.3";
	constexpr char uuid[] = "15C5171C-5AE3-4ED7-AB1E-ED4DD58EA6BB";

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
