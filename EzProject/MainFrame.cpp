#include "MainFrame.h"

MainFrame::MainFrame(const char* title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {

	this->Center();
	this->SetClientSize(this->FromDIP(wxSize(350, 600)));

	wxPanel* panel = new wxPanel(this);

	//
	// Main vbox

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

	//
	// // Project name input with label

	wxStaticText* projectName_l = new wxStaticText(panel, wxID_ANY, "Project name:");
	vbox->Add(projectName_l, 0, wxLEFT | wxTOP | wxRIGHT, 10);

	inputs.projectName = new wxTextCtrl(panel, wxID_ANY, project.GetName());
	vbox->Add(inputs.projectName, 0, wxEXPAND | wxALL, 10);

	// // Project name input with label
	//
	

	//
	// // Search project directory

	wxBoxSizer* searchdir_b = new wxBoxSizer(wxHORIZONTAL);

	inputs.projecDir = new wxTextCtrl(panel, wxID_ANY, "...");
	searchdir_b->Add(inputs.projecDir, 0, wxEXPAND, 10);

	// // Search project directory
	//


	//
	// // Button to create the project

	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	wxButton* button = new wxButton(panel, wxID_ANY, "Create");
	button->Bind(wxEVT_BUTTON, &MainFrame::OnCreateButton, this);
	hbox->AddStretchSpacer(1);
	hbox->Add(button, 0, wxALIGN_BOTTOM | wxRIGHT, 10);

	// // Button to create the project
	// 
	 
	 
	// Main vbox
	//

	//
	// Adding all boxes to main vbox 

	vbox->Add(vbox, 0, wxEXPAND | wxALIGN_CENTER);
	vbox->Add(hbox, 0, wxALIGN_RIGHT | wxBOTTOM, 10);
	panel->SetSizer(vbox);
	
	// Adding all boxes to main vbox 
	//

}

void MainFrame::OnCreateButton(wxCommandEvent& event) {
	
	project.SetName(inputs.projectName->GetValue());

	project.Create();
}
