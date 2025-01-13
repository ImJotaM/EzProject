#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/app.h>
#include <dwmapi.h>

class MainFrame : public wxFrame {

public:

	MainFrame(const char* title) : wxFrame (nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {

		this->SetBackgroundColour(bgColor);

		wxPanel* panel_main = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300, 400));
		panel_main->SetBackgroundColour(bgColor);

		wxStaticText* label_projectName = new wxStaticText(panel_main, wxID_ANY, "Project name");
		wxTextCtrl* input_projectName = new wxTextCtrl(panel_main, wxID_ANY);

		wxStaticText* label_projectDirectory = new wxStaticText(panel_main, wxID_ANY, "Project directory");
		wxTextCtrl* input_projectDirectory = new wxTextCtrl(panel_main, wxID_ANY);
		wxButton* button_projectDirectory = new wxButton(panel_main, wxID_ANY, "...", wxDefaultPosition, wxSize(25, -1));

		wxBoxSizer* sizer_projectDirectory = new wxBoxSizer(wxHORIZONTAL);
		sizer_projectDirectory->Add(input_projectDirectory, 1, wxRIGHT, 5);
		sizer_projectDirectory->Add(button_projectDirectory);

		wxButton* button_createProject = new wxButton(panel_main, wxID_ANY, "Create");

		wxBoxSizer* sizer_main = new wxBoxSizer(wxVERTICAL);
		sizer_main->Add(label_projectName);
		sizer_main->AddSpacer(4);
		sizer_main->Add(input_projectName, 0, wxEXPAND);
		sizer_main->AddSpacer(8);
		sizer_main->Add(label_projectDirectory);
		sizer_main->AddSpacer(4);
		sizer_main->Add(sizer_projectDirectory, 0, wxEXPAND);
		sizer_main->AddStretchSpacer();
		sizer_main->Add(button_createProject, 0, wxALIGN_RIGHT | wxRIGHT | wxTOP, 5);
		panel_main->SetSizer(sizer_main);

		wxBoxSizer* sizer_global = new wxBoxSizer(wxVERTICAL);
		sizer_global->Add(panel_main, 0, wxALL, 8);
		this->SetSizerAndFit(sizer_global);

		this->Center();
	}

private:

	const wxColour bgColor = *wxWHITE;

};

class App : public wxApp {

public:

	bool OnInit() {

		MainFrame* mainframe = new MainFrame("EzProject");
		mainframe->Show();
		return true;

	}

};

wxIMPLEMENT_APP(App);
