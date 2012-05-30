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

class GesturesControllerApi
{
public:

	virtual QString mouseGesture(const qReal::Id &id) const = 0;//mouse movement manager
	virtual qReal::IdList elements(const qReal::Id &id) const = 0; //mouse movement manager
};
