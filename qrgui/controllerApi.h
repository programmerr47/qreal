#pragma once

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QVariant>

#include "dialogControllerApi.h"
#include "gesturesControllerApi.h"
#include "mainWindowControllerApi.h"
#include "elementControllerApi.h"
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
		, public ElementControllerApi
{
public:
	ControllerApi(qReal::EditorManagerList &mgrl, qReal::MainWindow &mMW, const qrRepo::LogicalRepoApi &mLogicalApi,
				  qReal::models::GraphicalModelAssistApi *graphicalAssistApi,
				  qReal::models::LogicalModelAssistApi *logicalAssistApi);

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

	virtual bool hasGraphicalAssistApi() const; //editorViewScene
	virtual bool graphicalHasRootDiagrams() const; //editorViewScene
	virtual void graphicalStackBefore(const qReal::Id &element, const qReal::Id &sibling) const;//editorViewScene
	virtual qReal::Id graphicalCreateElement(qReal::Id const &parent, qReal::Id const &id, bool isFromLogicalModel, QString const &name, QPointF const &position);//editorViewScene
	virtual void graphicalSetTo(qReal::Id const &elem, qReal::Id const &newValue); //editorViewScene
	virtual void graphicalSetFrom(qReal::Id const &elem, qReal::Id const &newValue); //editorViewScene
	virtual QString name(qReal::Id const &id) const; //editorViewScene
	virtual qReal::IdList logicalElements(qReal::Id const &type) const; //editorViewScene
	virtual qReal::Id findElementByType(QString const &type) const; //editorViewScene
	virtual qReal::IdList outgoingConnections(qReal::Id const &id) const; //editorViewScene
	virtual qReal::IdList diagramsAbleToBeConnectedTo(qReal::Id const &element) const; //editorViewScene
	virtual qReal::IdList incomingConnections(qReal::Id const &id) const; //editorViewScene
	virtual qReal::IdList outgoingUsages(qReal::Id const &id) const; //editorViewScene
	virtual qReal::IdList diagramsAbleToBeUsedIn(qReal::Id const &element) const; //editorViewScene
	virtual qReal::IdList incomingUsages(qReal::Id const &id) const; //editorViewScene
	virtual void createConnected(qReal::Id const &sourceElement, qReal::Id const &elementType) const; //editorViewScene
	virtual void connect(qReal::Id const &source, qReal::Id const &destination); //editorViewScene
	virtual void disconnect(qReal::Id const &source, qReal::Id const &destination); //editorViewScene
	virtual void addUsage(qReal::Id const &source, qReal::Id const &destination); //editorViewScene
	virtual void deleteUsage(qReal::Id const &source, qReal::Id const &destination); //editorViewScene
	virtual void createUsed(qReal::Id const &sourceElement, qReal::Id const &elementType); //editorViewScene

	virtual qReal::IdList graphicalIdsByLogicalId(qReal::Id const &logicalId) const; // element
	virtual qReal::Id logicalId(qReal::Id const &elem) const;// element
	virtual QString graphicalName(qReal::Id const &elem) const;// element
	virtual QString toolTip(qReal::Id const &elem) const;// element
	virtual QVariant propertyByRoleName(qReal::Id const &elem, QString const &roleName) const;// element //logical
	virtual void setPropertyByRoleName(qReal::Id const &elem, QVariant const &newValue, QString const &roleName);// element

	virtual void setPosition(qReal::Id const &elem, QPointF const &newValue); //edgeElement
	virtual QPointF position(qReal::Id const &elem) const;//edgeElement

	virtual void setConfiguration(qReal::Id const &elem, QPolygon const &newValue); //edgeElement
	virtual QPolygon configuration(qReal::Id const &elem) const;//edgeElement

	//need to unite logical and graphical calls in this one
	virtual void setFrom(qReal::Id const &elem, qReal::Id const &newValue); //edgeElement
	virtual qReal::Id from(qReal::Id const &elem) const;//edgeElement

	virtual void setFromPort(qReal::Id const &elem, qreal const &newValue); //edgeElement
	virtual qreal fromPort(qReal::Id const &elem) const;//edgeElement

	virtual void setTo(qReal::Id const &elem, qReal::Id const &newValue); //edgeElement= 0;
	virtual qReal::Id to(qReal::Id const &elem) const;//edgeElement

	virtual void setToPort(qReal::Id const &elem, qreal const &newValue);//edgeElement
	virtual qreal toPort(qReal::Id const &elem) const;//edgeElement

	virtual qReal::EditorInterface* editorInterface(QString const &editor) const;//editor manager




private:
	int activeEditorManagerIndex;
	qReal::MainWindow &mMainWindow;
	//qReal::EditorManager *mEditorManager;
	qReal::EditorManagerList *mEditorManagerList;
	const qrRepo::LogicalRepoApi &mLogicalRepoApi;
	qReal::models::GraphicalModelAssistApi *mGraphicalApi;
	qReal::models::LogicalModelAssistApi *mLogicalApi;
};
