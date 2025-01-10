#include "Application.h"
wxIMPLEMENT_APP(App);

bool App::OnInit() {

	MainFrame* mainframe = new MainFrame("EzProject");
	mainframe->Show();
	return true;

}
