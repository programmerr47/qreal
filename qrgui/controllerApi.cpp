#include "controllerApi.h"

#include "../mainwindow/mainWindow.h"

using namespace qReal;
using namespace qrRepo;

ControllerApi::ControllerApi(EditorManager &mgr, MainWindow &mMW, const LogicalRepoApi &mLogicalApi)
	: mEditorManager(&mgr)
	, mMainWindow(mMW)
	, mLogicalRepoApi(mLogicalApi)
{
}

QList<QString> ControllerApi::getEditorsNames() const
{
	QList<QString> editorNames;
	foreach (Id editor, mEditorManager->editors()){
		editorNames.append(mEditorManager->friendlyName(editor));
	}
	return editorNames;
}

QMap<QString, QString> ControllerApi::getDiagramsNames() const
{
	QMap<QString, QString> diagramNames;
	foreach (Id editor, mEditorManager->editors()){
		foreach (Id diagram, mEditorManager->diagrams(editor)){
			diagramNames.insert(mEditorManager->friendlyName(editor), mEditorManager->friendlyName(diagram));
		}
	}
	return diagramNames;
}

QMap<QString, QString> ControllerApi::getElementsNames() const
{
	QMap<QString, QString> elementNames;
	foreach (Id editor, mEditorManager->editors()){
		foreach (Id diagram, mEditorManager->diagrams(editor)){
			foreach (Id element, mEditorManager->elements(diagram)){
				elementNames.insert(mEditorManager->friendlyName(diagram), mEditorManager->friendlyName(element));
			}
		}
	}
	return elementNames;
}

void ControllerApi::activateItemOrDiagram(Id const &id, bool bl, bool isSetSel) const
{
		mMainWindow.activateItemOrDiagram(id, bl, isSetSel);
}

void ControllerApi::activateItemOrDiagram(QModelIndex const &modelIndex, bool bl, bool isSetSel) const
{
		mMainWindow.activateItemOrDiagram(modelIndex, bl, isSetSel);
}

QList<QString> ControllerApi::prepareParentNamesByType(QString mTypeName) const
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

QList<QVariant> ControllerApi::getElementsDataByType(QString mTypeName) const
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
	return mEditorManager->propertyDescription(id, propertyName);
}

QString ControllerApi::propertyDisplayedName(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManager->propertyDisplayedName(id, propertyName);
}

QStringList ControllerApi::getEnumValues(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManager->getEnumValues(id, propertyName);
}

QStringList ControllerApi::getPropertyNames(const qReal::Id &id) const
{
	return mEditorManager->getPropertyNames(id);
}

QString ControllerApi::getTypeName(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManager->getTypeName(id, propertyName);
}

QString ControllerApi::friendlyName(const qReal::Id &id) const
{
	return mEditorManager->friendlyName(id);
}

QString ControllerApi::description(const qReal::Id &id) const
{
	return mEditorManager->description(id);
}

QIcon ControllerApi::icon(const qReal::Id &id) const
{
	return mEditorManager->icon(id);
}

void ControllerApi::setEditorManager(qReal::EditorManager &editorManager)
{
	mEditorManager = &editorManager;
}

IdList ControllerApi::elements(const qReal::Id &id) const
{
	return mEditorManager->elements(id);
}

QStringList ControllerApi::paletteGroups(const qReal::Id &editor, const qReal::Id &diagram) const
{
	return mEditorManager->paletteGroups(editor,diagram);
}

QStringList ControllerApi::paletteGroupList(const qReal::Id &editor, const qReal::Id &diagram, const QString &group) const
{
	return mEditorManager->paletteGroupList(editor, diagram, group);
}
