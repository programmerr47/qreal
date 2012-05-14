#include "controllerApi.h"

#include "../mainwindow/mainWindow.h"

using namespace qReal;
using namespace qrRepo;

ControllerApi::ControllerApi(EditorManager &mgr, MainWindow &mMW, const LogicalRepoApi &mLogicalApi)
	: mEditorManager(mgr)
	, mMainWindow(mMW)
	, mLogicalRepoApi(mLogicalApi)
{
}

QList<QString> ControllerApi::getEditorsNames()
{
	QList<QString> editorNames;
	foreach (Id editor, mEditorManager.editors()){
		editorNames.append(mEditorManager.friendlyName(editor));
	}
	return editorNames;
}

QMap<QString, QString> ControllerApi::getDiagramsNames()
{
	QMap<QString, QString> diagramNames;
	foreach (Id editor, mEditorManager.editors()){
		foreach (Id diagram, mEditorManager.diagrams(editor)){
			diagramNames.insert(mEditorManager.friendlyName(editor), mEditorManager.friendlyName(diagram));
		}
	}
	return diagramNames;
}

QMap<QString, QString> ControllerApi::getElementsNames()
{
	QMap<QString, QString> elementNames;
	foreach (Id editor, mEditorManager.editors()){
		foreach (Id diagram, mEditorManager.diagrams(editor)){
			foreach (Id element, mEditorManager.elements(diagram)){
				elementNames.insert(mEditorManager.friendlyName(diagram), mEditorManager.friendlyName(element));
			}
		}
	}
	return elementNames;
}

void ControllerApi::activateItemOrDiagram(Id const &id, bool bl, bool isSetSel)
{
		mMainWindow.activateItemOrDiagram(id, bl, isSetSel);
}

void ControllerApi::activateItemOrDiagram(QModelIndex const &modelIndex, bool bl, bool isSetSel)
{
		mMainWindow.activateItemOrDiagram(modelIndex, bl, isSetSel);
}

QList<QString> ControllerApi::prepareParentNamesByType(QString mTypeName)
{
	qReal::IdList idList = mLogicalRepoApi.elementsByType(mTypeName);
	int size = idList.size();
	QList<QString> parentNames;

	for (int i = 0; i < size; ++i)
	{
		qReal::Id parentId = mLogicalRepoApi.parent(idList[i]);
		QString parentName = mLogicalRepoApi.name(parentId);
		parentNames.append(parentName);
	}

	return parentNames;
}

QList<QVariant> ControllerApi::getElementsDataByType(QString mTypeName)
{
	qReal::IdList idList = mLogicalRepoApi.elementsByType(mTypeName);
	int size = idList.size();
	QList<QVariant> elementData;

	for (int i = 0; i < size; ++i)
	{
		QVariant data = idList[i].toString();
		elementData.append(data);
	}

	return elementData;
}

QString ControllerApi::propertyDescription(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManager.propertyDescription(id, propertyName);
}

QString ControllerApi::propertyDisplayedName(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManager.propertyDisplayedName(id, propertyName);
}

QStringList ControllerApi::getEnumValues(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManager.getEnumValues(id, propertyName);
}

QStringList ControllerApi::getPropertyNames(const qReal::Id &id) const
{
	return mEditorManager.getPropertyNames(id);
}

QString ControllerApi::getTypeName(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManager.getTypeName(id, propertyName);
}
