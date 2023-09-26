module;
#include <cstdint>

export module mut;
export namespace mut
{
	 // You can modify major and minor
	constexpr uint32_t major = 0;
	constexpr uint32_t minor = 0;

	 // Do not modify these
	constexpr uint32_t build = 69;
	
	constexpr uint32_t version = major * 1000 + minor * 100 + build;
	constexpr uint64_t random_seed = 0x6e400da2ce49d42d;
	
	constexpr char version_string[] = "v0.0.69";
	constexpr char build_time_string[] = "2023-09-27 21:00:03";
	constexpr char phrase[] = "excursion-wasting-rebound";
	constexpr char calver[] = "2023.39.69";
	constexpr char uuid[] = "0AFA3224-D75D-41D2-86C7-5B209C6BE86D";

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
