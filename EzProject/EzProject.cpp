#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/app.h>

class MainFrame : public wxFrame {

public:

	MainFrame(const char* title) : wxFrame (nullptr, wxID_ANY, title) {

		wxBoxSizer* mainsizer = new wxBoxSizer(wxVERTICAL);
		wxPanel* mainpanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(350, 500));

		wxBoxSizer* mainpanel_sizer = new wxBoxSizer(wxVERTICAL);

		wxStaticText* l_projectName = new wxStaticText(mainpanel, wxID_ANY, "Project name: ");

		mainsizer->Add(mainpanel, 1, wxEXPAND);
		this->SetSizerAndFit(mainsizer);

	}

private:

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
