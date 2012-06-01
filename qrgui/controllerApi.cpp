#include "controllerApi.h"

#include "../mainwindow/mainWindow.h"

using namespace qReal;
using namespace qrRepo;

ControllerApi::ControllerApi(EditorManagerList &mgrl, MainWindow &mMW, const LogicalRepoApi &mLogicalApi)
	: mEditorManagerList(&mgrl)
	, mMainWindow(mMW)
	, mLogicalRepoApi(mLogicalApi)
	, activeEditorManagerIndex(0)
{
}

QList<QString> ControllerApi::getEditorsNames() const
{
	QList<QString> editorNames;
	foreach (Id editor, mEditorManagerList->at(activeEditorManagerIndex)->editors()){
		editorNames.append(mEditorManagerList->at(activeEditorManagerIndex)->friendlyName(editor));
	}
	return editorNames;
}

QMap<QString, QString> ControllerApi::getDiagramsNames() const
{
	QMap<QString, QString> diagramNames;
	foreach (Id editor, mEditorManagerList->at(activeEditorManagerIndex)->editors()){
		foreach (Id diagram, mEditorManagerList->at(activeEditorManagerIndex)->diagrams(editor)){
			diagramNames.insert(mEditorManagerList->at(activeEditorManagerIndex)->friendlyName(editor), mEditorManagerList->at(activeEditorManagerIndex)->friendlyName(diagram));
		}
	}
	return diagramNames;
}

QMap<QString, QString> ControllerApi::getElementsNames() const
{
	QMap<QString, QString> elementNames;
	foreach (Id editor, mEditorManagerList->at(activeEditorManagerIndex)->editors()){
		foreach (Id diagram, mEditorManagerList->at(activeEditorManagerIndex)->diagrams(editor)){
			foreach (Id element, mEditorManagerList->at(activeEditorManagerIndex)->elements(diagram)){
				elementNames.insert(mEditorManagerList->at(activeEditorManagerIndex)->friendlyName(diagram), mEditorManagerList->at(activeEditorManagerIndex)->friendlyName(element));
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
	return mEditorManagerList->at(activeEditorManagerIndex)->propertyDescription(id, propertyName);
}

QString ControllerApi::propertyDisplayedName(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->propertyDisplayedName(id, propertyName);
}

QStringList ControllerApi::getEnumValues(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->getEnumValues(id, propertyName);
}

QStringList ControllerApi::getPropertyNames(const qReal::Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->getPropertyNames(id);
}

QString ControllerApi::getTypeName(const qReal::Id &id, const QString &propertyName) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->getTypeName(id, propertyName);
}

QString ControllerApi::friendlyName(const qReal::Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->friendlyName(id);
}

QString ControllerApi::description(const qReal::Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->description(id);
}

QIcon ControllerApi::icon(const qReal::Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->icon(id);
}

/*void ControllerApi::setEditorManager(qReal::EditorManager &editorManager)
{
	mEditorManagerList[0] = &editorManager;
}*/

EditorManager *ControllerApi::getEditorManager(int index) const
{
	return mEditorManagerList->at(index);
}

void ControllerApi::setActiveEditorManagerIndex(int index)
{
	activeEditorManagerIndex = index;
}

IdList ControllerApi::editors() const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->editors();
}

IdList ControllerApi::diagrams(const qReal::Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->diagrams(id);
}

IdList ControllerApi::elements(const qReal::Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->elements(id);
}

QStringList ControllerApi::paletteGroups(const qReal::Id &editor, const qReal::Id &diagram) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->paletteGroups(editor,diagram);
}

QStringList ControllerApi::paletteGroupList(const qReal::Id &editor, const qReal::Id &diagram, const QString &group) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->paletteGroupList(editor, diagram, group);
}

QString ControllerApi::mouseGesture(const qReal::Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->mouseGesture(id);
}

IdList ControllerApi::getContainedTypes(const Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->getContainedTypes(id);
}

bool ControllerApi::isParentOf(Id const &child, Id const &parent) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->isParentOf(child, parent);
}

QStringList ControllerApi::getAllChildrenTypesOf(Id const &parent) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->getAllChildrenTypesOf(parent);
}

Element* ControllerApi::graphicalObject(Id const &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->graphicalObject(id);
}

IdList ControllerApi::getUsedTypes(const Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->getUsedTypes(id);
}

IdList ControllerApi::getConnectedTypes(const Id &id) const
{
	return mEditorManagerList->at(activeEditorManagerIndex)->getConnectedTypes(id);
}
