#include "buttonRefWindow.h"

#include "../models/logicalModelAssistApi.h"

ButtonRefWindow::ButtonRefWindow(QWidget *parent, QString const &typeName
		, qReal::models::LogicalModelAssistApi const &logicalModelAssistApi
		, int role, const QModelIndex &index
        , DialogControllerApi *mDCA)
	: QPushButton(parent)
	, mName(typeName)
	, mApi(logicalModelAssistApi.logicalRepoApi())
	, mRole(role)
	, mIndex(index)
    , mDialogControllerApi(mDCA)
{
	setText("Reference button");
	connect(this, SIGNAL(clicked()), this, SLOT(makeWindow()));
	show();
}

void ButtonRefWindow::makeWindow()
{
    RefWindow *window = new RefWindow(mName, mRole, mIndex, *mDialogControllerApi);
	window->setWindowModality(Qt::ApplicationModal);
	window->show();
}
