#pragma once
#include <wx/wx.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class ProjectHandler {

public:

	ProjectHandler();

	std::string GetName();
	void SetName(const char* name);

	fs::path GetDirectory();
	void SetDirectory(fs::path projectDir);

	void Create();

private:

	struct ProjectData {

		std::string name = "";
		fs::path directory = "";

	} project;

};