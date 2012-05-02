#include "refWindow.h"
//#include "dialogcontrollerapi.h"

RefWindow::RefWindow(const QString &name, int role,
        const QModelIndex &index, DialogControllerApi &mDCA)
    : QWidget(NULL)
    , mUi(new Ui::RefWindow)
	, mTypeName(name)
    , mRole(role)
    , mIndex(index)
	, mItem(NULL)
    , mDialogControllerApi(mDCA)
{
	mUi->setupUi(this);
    mUi->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    QString const str = mIndex.data(mRole).toString();
    int sizeStr = str.count("$$");

    QList<QString> elementParentNames = mDCA.prepareParentNamesByType(mTypeName);
    int size = elementParentNames.size();

    QList<QVariant> elemetsData = mDCA.getElementsDataByType(mTypeName);

    for (int i = 0; i < size; ++i)
    {
        QString parentName = elementParentNames.at(i);
        if (parentName.contains("Diagram"))
        {
            QListWidgetItem *item = new QListWidgetItem();
            QString text = parentName + "::" + elementParentNames.at(i);
            item->setText(text);
            QVariant val = elemetsData.at(i);
            item->setData(Qt::ToolTipRole, val);
            mUi->listWidget->addItem(item);
            for (int k = 0; k < sizeStr; ++k)
            {
                if (val == str.section("$$", k, k))
                    item->setSelected(true);
            }
        }
    }

    /*
    qReal::IdList idList = mApi.elementsByType(mTypeName);
	int size = idList.size();

	for (int i = 0; i < size; ++i)
	{
		qReal::Id parentId = mApi.parent(idList[i]);
		QString parentName = mApi.name(parentId);
		if (parentName.contains("Diagram"))
		{
			QListWidgetItem *item = new QListWidgetItem();
			QString text = parentName + "::" + mApi.name(parentId);
			item->setText(text);
			QVariant val = idList[i].toString();
			item->setData(Qt::ToolTipRole, val);
			mUi->listWidget->addItem(item);
			for (int k = 0; k < sizeStr; ++k)
			{
				if (val == str.section("$$", k, k))
					item->setSelected(true);
			}
		}
	}
    */
	mUi->mButtonOk->setEnabled(false);
	connect(mUi->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this,
			SLOT(highlightElement(QListWidgetItem*)));
	connect(mUi->mButtonCancel, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(mUi->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this,
			SLOT(enableOkButton(QListWidgetItem*)));
	connect(mUi->mButtonOk, SIGNAL(clicked()), this, SLOT(setElementId()));
}

RefWindow::~RefWindow()
{
	delete mUi;
}

void RefWindow::keyPressEvent(QKeyEvent *event)
{
	if ((event->key()) == (Qt::Key_Escape))
	{
		if (mItem)
			highlightElement(mItem, false);
		close();
	}
	if (((event->key()) == (Qt::Key_Return)) && (mUi->mButtonOk->isEnabled()))
	{
		setPropertyValue();
		setElementId();
	}
}

void RefWindow::setPropertyValue()
{
	QList<QListWidgetItem *> itemList = mUi->listWidget->selectedItems();
	if (!itemList.isEmpty())
	{
		QString idStr;
		for (int i = 0; i < itemList.size(); ++i)
			idStr.append(itemList[i]->data(Qt::ToolTipRole).toString() + "$$");
		QAbstractItemModel *model = const_cast<QAbstractItemModel *>(mIndex.model());
		model->setData(mIndex, idStr, mRole);
	}
	close();
}

void RefWindow::highlightElement(QListWidgetItem *item, bool bl)
{
	Q_UNUSED(bl)
	mItem = item;
    bool isSelected = item->isSelected();

    mDialogControllerApi.activateItemOrDiagram(item->data(Qt::ToolTipRole).toString(), isSelected, false);
    if (isSelected){
        mElementList << item;
    }
    /*qReal::Id const id = qReal::Id::loadFromString(item->data(Qt::ToolTipRole).toString());
	if (item->isSelected()) {
		mMainWindow.activateItemOrDiagram(id, true, false);
		mElementList << item;
	}
	else {
		mMainWindow.activateItemOrDiagram(id, false, false);
    }*/
}

void RefWindow::cancel()
{
	QVariant data = mIndex.data(mRole);
	QAbstractItemModel *model = const_cast<QAbstractItemModel *>(mIndex.model());
	model->setData(mIndex, data, mRole);
	setElementId();
	close();
}

void RefWindow::enableOkButton(QListWidgetItem* item)
{
	Q_UNUSED(item);
	mUi->mButtonOk->setEnabled(true);
}

void RefWindow::setElementId()
{
	for (int i = 0; i < mElementList.size(); ++i)
	{
        mDialogControllerApi.activateItemOrDiagram(mElementList[i]->data(Qt::ToolTipRole).toString(), false, false);
        //qReal::Id const id = qReal::Id::loadFromString(mElementList[i]->data(Qt::ToolTipRole).toString());
        //mMainWindow.activateItemOrDiagram(id, false, false);
	}
    mDialogControllerApi.activateItemOrDiagram(mIndex, false);
    //mMainWindow.activateItemOrDiagram(mIndex, false);
}
