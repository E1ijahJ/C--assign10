#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <map>
#include <string>
#include <filesystem>

std::map<std::string, std::filesystem::file_time_type> getFilesWithModifiedTimes(const std::string& directoryPath);

#endif