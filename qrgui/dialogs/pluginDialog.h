#pragma once

#include <QDialog>
#include <QIcon>

class QLabel;
class QPushButton;
class QStringList;
class QTreeWidget;
class QTreeWidgetItem;

namespace qReal {

	class EditorManager;

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
