#pragma once

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QVariant>

#include "dialogControllerApi.h"
#include "mainWindowControllerApi.h"

#include "models/graphicalModelAssistApi.h"
#include "models/logicalModelAssistApi.h"

namespace qReal{

	namespace models {
		class GraphicalModelAssistApi;
		class LogicalModelAssistApi;
	 }
	class EditorManager;
}

class ViewControllerApi
{
public:

	virtual qReal::IdList getContainedTypes(const qReal::Id &id) const = 0; //editorViewScene
	virtual QString friendlyName(const qReal::Id &id) const = 0; //editorViewScene
	virtual bool isParentOf(qReal::Id const &child, qReal::Id const &parent) const = 0; //editorViewScene
	virtual QStringList getAllChildrenTypesOf(qReal::Id const &parent) const = 0; //editorViewScene
	virtual Element* graphicalObject(qReal::Id const &id) const = 0; //editorViewScene
	virtual qReal::IdList getUsedTypes(const qReal::Id &id) const = 0; //editorViewScene
	virtual qReal::IdList getConnectedTypes(const qReal::Id &id) const = 0; //editorViewScene

	virtual bool hasGraphicalAssistApi() const = 0; //editorViewScene
	virtual bool graphicalHasRootDiagrams() const = 0; //editorViewScene
	virtual void graphicalStackBefore(const qReal::Id &element, const qReal::Id &sibling) const = 0;//editorViewScene
	virtual qReal::Id graphicalCreateElement(qReal::Id const &parent, qReal::Id const &id, bool isFromLogicalModel, QString const &name, QPointF const &position) = 0;//editorViewScene
	virtual void graphicalSetTo(qReal::Id const &elem, qReal::Id const &newValue) = 0; //editorViewScene
	virtual void graphicalSetFrom(qReal::Id const &elem, qReal::Id const &newValue) = 0; //editorViewScene
	virtual QString name(qReal::Id const &id) const = 0; //editorViewScene
	virtual qReal::IdList logicalElements(qReal::Id const &type) const = 0; //editorViewScene
	virtual qReal::Id findElementByType(QString const &type) const = 0; //editorViewScene
	virtual qReal::IdList outgoingConnections(qReal::Id const &id) const = 0; //editorViewScene
	virtual qReal::IdList diagramsAbleToBeConnectedTo(qReal::Id const &element) const = 0; //editorViewScene
	virtual qReal::IdList incomingConnections(qReal::Id const &id) const = 0; //editorViewScene
	virtual qReal::IdList outgoingUsages(qReal::Id const &id) const = 0; //editorViewScene
	virtual qReal::IdList diagramsAbleToBeUsedIn(qReal::Id const &element) const = 0; //editorViewScene
	virtual qReal::IdList incomingUsages(qReal::Id const &id) const = 0; //editorViewScene
	virtual void createConnected(qReal::Id const &sourceElement, qReal::Id const &elementType) const = 0; //editorViewScene
	virtual void connect(qReal::Id const &source, qReal::Id const &destination) = 0; //editorViewScene
	virtual void disconnect(qReal::Id const &source, qReal::Id const &destination) = 0; //editorViewScene
	virtual void addUsage(qReal::Id const &source, qReal::Id const &destination) = 0; //editorViewScene
	virtual void deleteUsage(qReal::Id const &source, qReal::Id const &destination) = 0; //editorViewScene
	virtual void createUsed(qReal::Id const &sourceElement, qReal::Id const &elementType) = 0; //editorViewScene

};
