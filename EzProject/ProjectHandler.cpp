#include "ProjectHandler.h"
#include <Windows.h>

ProjectHandler::ProjectHandler() {

	project.name = "DefaultProject";
	project.directory = fs::current_path();

}

std::string ProjectHandler::GetName() {
	return project.name;
}

void ProjectHandler::SetName(const char* name) {
	project.name = name;
}

fs::path ProjectHandler::GetDirectory() {
	return project.directory;
}

void ProjectHandler::SetDirectory(fs::path projectDir) {
	project.directory = projectDir;
}

void ProjectHandler::Create() {

	std::string command = ".\\premake\\premake5.exe vs2022 --file=premake/premake5.lua";

	command += " --projectName=" + project.name;
	command += " --projectDir=" + project.directory.native();
	
	command += " > output.log 2>&1";

	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;

	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcessA(
		NULL,
		const_cast<char*>(command.c_str()),
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	)) {

		wxMessageBox("Premake executado com sucesso!", "Sucesso", wxOK | wxICON_INFORMATION);

		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

	} else {
		wxMessageBox("Erro ao executar o Premake.", "Erro", wxOK | wxICON_ERROR);
	}

}
