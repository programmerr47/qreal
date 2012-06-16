#pragma once

#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QString>

#include "../pluginManager/editorManager.h"
//#include "../mainwindow/mainWindow.h"


namespace qrRepo{
	class LogicalRepoApi;
	class GraphicalRepoApi;
}

	class ElementControllerApi
	{
	public:
		virtual qReal::IdList graphicalIdsByLogicalId(qReal::Id const &logicalId) const = 0;
		virtual qReal::Id logicalId(qReal::Id const &elem) const = 0;
		virtual QString graphicalName(qReal::Id const &elem) const = 0;
		virtual QString toolTip(qReal::Id const &elem) const = 0;

		virtual QVariant propertyByRoleName(qReal::Id const &elem, QString const &roleName) const = 0; //logical
		virtual void setPropertyByRoleName(qReal::Id const &elem, QVariant const &newValue, QString const &roleName) = 0;

	};
