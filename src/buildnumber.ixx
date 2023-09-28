module;
#include <cstdint>

export module mut;
export namespace mut
{
	 // You can modify major and minor
	constexpr uint32_t major = 0;
	constexpr uint32_t minor = 0;

	 // Do not modify these
	constexpr uint32_t build = 135;
	
	constexpr uint32_t version = major * 10000 + minor * 1000 + build;
	constexpr uint64_t random_seed = 0xd00718b7466c06cd;
	
	constexpr char version_string[] = "v0.0.135";
	constexpr char build_time_string[] = "2023-09-28 16:24:10";
	constexpr char phrase[] = "girdle-impotence-congested";
	constexpr char calver[] = "2023.39.135";
	constexpr char uuid[] = "41DC437E-8C69-4AB3-A362-B0220E648671";

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
