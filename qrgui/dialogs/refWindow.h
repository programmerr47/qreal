#pragma once

#include <QtGui>
#include <QWidget>
#include "../../qrrepo/repoApi.h"
#include "../mainwindow/mainWindow.h"
#include "ui_refWindow.h"
#include "../../qrkernel/ids.h"

#include "dialogcontrollerapi.h"

namespace Ui {
	class RefWindow;
}

class RefWindow : public QWidget
{
	Q_OBJECT

public:
	explicit RefWindow(qrRepo::LogicalRepoApi const &logicalRepoApi, QString const &name,
            int role, QModelIndex const &index, DialogControllerApi &mDCA);
	~RefWindow();

public slots:
	void setPropertyValue();
	void highlightElement(QListWidgetItem *item, bool bl = true);
	void cancel();

private:
	void keyPressEvent(QKeyEvent *event);

	Ui::RefWindow *mUi;
	qrRepo::LogicalRepoApi const &mApi;
	QString mTypeName;
	int mRole;
    QModelIndex const &mIndex;
	QListWidgetItem *mItem;
	QList<QListWidgetItem *> mElementList;
    DialogControllerApi &mDialogControllerApi;

private slots:
	void enableOkButton(QListWidgetItem* item);
	void setElementId();
};
