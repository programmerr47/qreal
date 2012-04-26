#pragma once

#include <QPushButton>
#include "../../qrrepo/repoApi.h"
#include "../../qrgui/dialogs/refWindow.h"

#include "../dialogs/dialogcontrollerapi.h"

class ButtonRefWindow : public QPushButton
{
	Q_OBJECT

public:
	ButtonRefWindow(QWidget *parent, QString const &typeName
			, qReal::models::LogicalModelAssistApi const &logicalModelAssistApi
            , int role, const QModelIndex &index, DialogControllerApi *mDCA);

private:
	QString mName;
	qrRepo::LogicalRepoApi const &mApi;
	int mRole;
	QPersistentModelIndex const mIndex;
    DialogControllerApi * const mDialogControllerApi;

private slots:
	void makeWindow();
};
