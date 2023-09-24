module;
#include <cstdint>

export module mut;
export namespace mut
{
	 // You can modify major and minor
	constexpr uint32_t major = 0;
	constexpr uint32_t minor = 0;

	 // Do not modify these
	constexpr uint32_t build = 2;
	
	constexpr uint32_t version = major * 100 + minor * 10 + build;
	constexpr uint64_t random_seed = 0xf9c62361f72e3d2d;
	
	constexpr char version_string[] = "v0.0.2";
	constexpr char build_time_string[] = "2023-09-24 12:53:50";
	constexpr char phrase[] = "cyclist-encrypt-treading";
	constexpr char calver[] = "2023.38.2";
	constexpr char uuid[] = "B8340595-EE9D-42D8-BC46-13E6DA039916";

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
