#pragma once
#include <QtGui/QLabel>
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QTreeWidgetItem>
#include <QtGui/QHeaderView>
#include <QtGui/QDialog>
#include <QtGui/QIcon>

#include <QtCore/QtDebug>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QString>

namespace qReal {

	class PluginDialog : public QDialog
	{
		Q_OBJECT

	public:
        PluginDialog(QList<QString> editors, QMap<QString, QString> diagrams, QMap<QString, QString> elements, QWidget *parent = 0);

	private:
		QLabel *label;
		QTreeWidget *treeWidget;
		QPushButton *okButton;
		QIcon interfaceIcon;
		QIcon featureIcon;
	};

}
