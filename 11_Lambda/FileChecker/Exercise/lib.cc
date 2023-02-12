#include <algorithm>
#include <array>
#include <filesystem>
#include <vector>

#include "lib.h"

int number_of_source_files(const FileVec &files)
{
	const std::array<std::string, 3> extensions = {".cpp", ".cc", ".c"};
	auto fileExists = [extensions](const fs::path& file){	
		return file_extension_check(extensions, file);
	};
	return std::count_if(files.begin(), files.end(), fileExists);

}

int number_of_header_files(const FileVec &files)
{
	const std::array<std::string, 4> extensions = {".hpp", ".h", ".hp", ".hh"};
	auto fileExists = [extensions](const fs::path& file){	
		return file_extension_check(extensions, file);
	};
	// count_if requires a function call with one parameter and a return type of booleans
	return std::count_if(files.begin(), files.end(), fileExists);

}

bool is_c_source_file(const fs::path &file)
{	
	const std::array<std::string, 1> extension = {".c"};
	return file_extension_check(extension, file);
}

bool is_cpp_source_file(const fs::path &file)
{
	const std::array<std::string, 1> extension = {".cc"};
	return file_extension_check(extension, file);
}

bool is_c_header_file(const fs::path &file)
{
	const std::array<std::string, 1> extension = {".h"};
	return file_extension_check(extension, file);
}

bool is_cpp_header_file(const fs::path &file)
{
	const std::array<std::string, 1> extension = {".hpp"};
	return file_extension_check(extension, file);
}
