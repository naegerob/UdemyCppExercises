#pragma once

#include <array>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using FileVec = std::vector<fs::path>;

bool is_c_source_file(const fs::path &file);

bool is_cpp_source_file(const fs::path &file);

bool is_c_header_file(const fs::path &file);

bool is_cpp_header_file(const fs::path &file);

int number_of_source_files(const FileVec &files);

int number_of_header_files(const FileVec &files);

template <std::size_t N>
bool file_extension_check(const std::array<std::string, N> &allowed_extension,
						  const fs::path &file)
{
	/*std::any_of(file.begin(),
				file.end(),
				[file](const auto extension){
					return extension == file.extension();
				});

				*/

	// Noobie solution but suggested solution not supported with current builder version
	for (auto extension : allowed_extension)
	{
		if(extension == file.extension())
		{
			return true;
		}
	}
	return false;
}
