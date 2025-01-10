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
    vbox->Add(inputs.projectName, 0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 10);

    // // Project name input with label
    //

    //
    // // Search project directory

    wxBoxSizer* searchdir_b = new wxBoxSizer(wxHORIZONTAL);

    inputs.projectDir = new wxTextCtrl(panel, wxID_ANY, project.GetDirectory().native().c_str());
    searchdir_b->Add(inputs.projectDir, 1, wxEXPAND | wxTOP, 10);

    wxButton* browseButton = new wxButton(panel, wxID_ANY, "...");
    searchdir_b->Add(browseButton, 0, wxTOP, 10);

    vbox->Add(searchdir_b, 0, wxEXPAND | wxALL, 10);

    // // Search project directory
    //

    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    wxButton* button = new wxButton(panel, wxID_ANY, "Create");
    button->Bind(wxEVT_BUTTON, &MainFrame::OnCreateButton, this);
    hbox->AddStretchSpacer(1);
    hbox->Add(button, 0, wxALIGN_BOTTOM | wxRIGHT, 10);

    vbox->Add(hbox, 0, wxALIGN_RIGHT | wxBOTTOM, 10);

    panel->SetSizerAndFit(vbox);

}

void MainFrame::OnCreateButton(wxCommandEvent& event) {
	
	project.SetName(inputs.projectName->GetValue());

	project.Create();
}
