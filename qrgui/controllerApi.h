#pragma once

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QVariant>

#include "dialogControllerApi.h"
#include "gesturesControllerApi.h"
#include "mainWindowControllerApi.h"
#include "viewControllerApi.h"

//#include "../pluginManager/editorManager.h"

namespace qReal{
	class MainWindow;
	class EditorManager;
}

namespace qrRepo{
	class LogicalRepoApi;
}

class ControllerApi : public DialogControllerApi, public MainWindowControllerApi
		, public GesturesControllerApi, public ViewControllerApi
{
public:
	ControllerApi(qReal::EditorManagerList &mgrl, qReal::MainWindow &mMW, const qrRepo::LogicalRepoApi &mLogicalApi);

	virtual QList<QString> getEditorsNames() const;//PluginDialog
	virtual QMap<QString, QString> getDiagramsNames() const;//PluginDialog
	virtual QMap<QString, QString> getElementsNames() const;//PluginDialog
	virtual QList<QString> prepareParentNamesByType(QString mTypeName) const;//refWindow
	virtual QList<QVariant> getElementsDataByType(QString mTypeName) const;//refWindow
	virtual void activateItemOrDiagram(const qReal::Id &id, bool bl = true, bool isSetSel = true) const;//refWindow
	virtual void activateItemOrDiagram(QModelIndex const &modelIndex, bool bl = true, bool isSetSel = true) const;//refWindow
	virtual QString propertyDescription(const qReal::Id &id, const QString &propertyName) const;//PropertyEditorModel
	virtual QString propertyDisplayedName(const qReal::Id &id, const QString &propertyName) const;//PropertyEditorModel
	virtual QStringList getEnumValues(const qReal::Id &id, const QString &propertyName) const;//PropertyEditorModel
	virtual QStringList getPropertyNames(const qReal::Id &id) const;//PropertyEditorModel
	virtual QString getTypeName(const qReal::Id &id, const QString &propertyName) const;//PropertyEditorModel
	virtual QString friendlyName(const qReal::Id &id) const; //mainwindow, editorViewScene
	virtual QString description(const qReal::Id &id) const; //mainwindow
	virtual QIcon icon(const qReal::Id &id) const; //mainwindow
//	virtual void setEditorManager(qReal::EditorManager &editorManager); //mainwindow
	virtual qReal::EditorManager* getEditorManager(int index) const; //mainwindow
	virtual void setActiveEditorManagerIndex(int index);
	virtual qReal::IdList editors() const; //palettetree
	virtual qReal::IdList diagrams(const qReal::Id &id) const; //palettetree
	virtual qReal::IdList elements(const qReal::Id &id) const; //mainwindow, mouse movement manager
	virtual QStringList paletteGroups(const qReal::Id &editor, const qReal::Id &diagram) const; //mainwindow
	virtual QStringList paletteGroupList(const qReal::Id &editor, const qReal::Id &diagram, const QString &group) const; //mainwindow
	virtual QString mouseGesture(const qReal::Id &id) const;//mouse movement manager
	virtual qReal::IdList getContainedTypes(const qReal::Id &id) const; //editorViewScene
	virtual bool isParentOf(qReal::Id const &child, qReal::Id const &parent) const; //editorViewScene
	virtual QStringList getAllChildrenTypesOf(qReal::Id const &parent) const; //editorViewScene
	virtual Element* graphicalObject(qReal::Id const &id) const; //editorViewScene
	virtual qReal::IdList getUsedTypes(const qReal::Id &id) const; //editorViewScene
	virtual qReal::IdList getConnectedTypes(const qReal::Id &id) const; //editorViewScene

private:
	int activeEditorManagerIndex;
	qReal::MainWindow &mMainWindow;
	//qReal::EditorManager *mEditorManager;
	qReal::EditorManagerList *mEditorManagerList;
	const qrRepo::LogicalRepoApi &mLogicalRepoApi;
};
