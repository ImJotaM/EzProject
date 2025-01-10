#pragma once
#include <wx/wx.h>
#include <wx/frame.h>

#include "ProjecHandler.h"

class MainFrame : public wxFrame {

public:

	MainFrame(const char* title);

private:

	ProjectHandler project;

	struct AppInputs {
		wxTextCtrl* projectName = nullptr;
		wxTextCtrl* projectDir = nullptr;
	} inputs;


	void OnCreateButton(wxCommandEvent& event);

};