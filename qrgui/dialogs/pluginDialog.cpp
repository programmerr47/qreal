#include "pluginDialog.h"

using namespace qReal;

PluginDialog::PluginDialog(QList<QString> editors, QMap<QString, QString> diagrams, QMap<QString, QString> elements,
		QWidget *parent) :
	QDialog(parent),
	label(new QLabel),
	treeWidget(new QTreeWidget),
	okButton(new QPushButton(tr("OK")))
{
	treeWidget->setAlternatingRowColors(false);
	treeWidget->setSelectionMode(QAbstractItemView::NoSelection);
	treeWidget->setColumnCount(1);
	treeWidget->header()->hide();

	okButton->setDefault(true);

	connect(okButton, SIGNAL(clicked()), this, SLOT(close()));

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setColumnStretch(0, 1);
	mainLayout->setColumnStretch(2, 1);
	mainLayout->addWidget(label, 0, 0, 1, 3);
	mainLayout->addWidget(treeWidget, 1, 0, 1, 3);
	mainLayout->addWidget(okButton, 2, 1);
	setLayout(mainLayout);

	interfaceIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
			QIcon::Normal, QIcon::On);
	interfaceIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),
			QIcon::Normal, QIcon::Off);
	featureIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));

	setWindowTitle(tr("Plugin Information"));

    foreach (QString editor, editors) {
		QTreeWidgetItem *pluginItem = new QTreeWidgetItem(treeWidget);
        pluginItem->setText(0, editor);
		treeWidget->setItemExpanded(pluginItem, true);

		QFont boldFont = pluginItem->font(0);
		boldFont.setBold(true);
		pluginItem->setFont(0, boldFont);

        QMap<QString, QString>::const_iterator diagram = diagrams.find(editor);
        while (diagram != diagrams.end() && diagram.key() == editor){
            QTreeWidgetItem *interfaceItem = new QTreeWidgetItem(pluginItem);
            interfaceItem->setText(0, diagram.value());
            interfaceItem->setIcon(0, interfaceIcon);

            QMap<QString, QString>::const_iterator element = elements.find(diagram.value());
            while (element != elements.end() && element.key() == diagram.value()){
                QTreeWidgetItem *featureItem = new QTreeWidgetItem(interfaceItem);
                featureItem->setText(0, element.value());
                featureItem->setIcon(0, featureIcon);
                ++element;
            }
            ++diagram;
        }
	}
}
