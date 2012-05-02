#pragma once

#include <QtGui>
#include <QWidget>
//#include "../../qrrepo/repoApi.h"
//#include "../mainwindow/mainWindow.h"
#include "ui_refWindow.h"
//#include "../../qrkernel/ids.h"
#include "dialogcontrollerapi.h"

namespace Ui {
	class RefWindow;
}

class RefWindow : public QWidget
{
	Q_OBJECT

public:
    explicit RefWindow(QString const &name,
            int role, QModelIndex const &index, DialogControllerApi &mDCA);
    // Previously got repoApi from buttonRefWindow
    // now thru dialogControlApi from mainWindow
    // look into it if bugs occur
	~RefWindow();

public slots:
	void setPropertyValue();
	void highlightElement(QListWidgetItem *item, bool bl = true);
	void cancel();

private:
	void keyPressEvent(QKeyEvent *event);

	Ui::RefWindow *mUi;
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
