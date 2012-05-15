#pragma once

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QVariant>

#include "dialogControllerApi.h"
#include "mainWindowControllerApi.h"

//#include "../pluginManager/editorManager.h"

namespace qReal{
	class MainWindow;
	class EditorManager;
}

namespace qrRepo{
	class LogicalRepoApi;
}

class ControllerApi : public DialogControllerApi, public MainWindowControllerApi
{
public:
	ControllerApi(qReal::EditorManager &mgr, qReal::MainWindow &mMW, const qrRepo::LogicalRepoApi &mLogicalApi);

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
	virtual QString friendlyName(const qReal::Id &id) const; //mainwindow
	virtual QString description(const qReal::Id &id) const; //mainwindow
	virtual QIcon icon(const qReal::Id &id) const; //mainwindow
	virtual void setEditorManager(qReal::EditorManager &editorManager); //mainwindow
	virtual qReal::IdList elements(const qReal::Id &id) const; //mainwindow
	virtual QStringList paletteGroups(const qReal::Id &editor, const qReal::Id &diagram) const; //mainwindow
	virtual QStringList paletteGroupList(const qReal::Id &editor, const qReal::Id &diagram, const QString &group) const; //mainwindow


private:
	qReal::MainWindow &mMainWindow;
	qReal::EditorManager *mEditorManager;
	const qrRepo::LogicalRepoApi &mLogicalRepoApi;
};
