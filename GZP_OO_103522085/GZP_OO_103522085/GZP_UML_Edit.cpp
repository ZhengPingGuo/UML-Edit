#include"GZP_UML_Edit.h"
#include"MyDocument.h"
#include"MyFrame.h"
#include"ButtonPanel.h"
#include"resource.h"


BOOL MyApp::InitInstance()
{
	CDocument *doc;
	CSingleDocTemplate *DocTemplate;
	DocTemplate = new CSingleDocTemplate(
		IDR_MENU1,
		RUNTIME_CLASS(MyDocument),
		RUNTIME_CLASS(MyFrame),
		RUNTIME_CLASS(ButtonPanel));

	AddDocTemplate(DocTemplate);
	doc = DocTemplate->CreateNewDocument();

	m_pMainWnd = DocTemplate->CreateNewFrame(doc, NULL);
	DocTemplate->InitialUpdateFrame((CFrameWnd*)m_pMainWnd, doc);
	m_pMainWnd->ShowWindow(SW_SHOW);

	return true;
}

MyApp my_app;