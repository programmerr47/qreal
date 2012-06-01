#pragma once

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QVariant>

#include "dialogControllerApi.h"
#include "mainWindowControllerApi.h"

namespace qReal{
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


};
