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

		virtual void setPosition(qReal::Id const &elem, QPointF const &newValue) = 0; //edgeElement
		virtual QPointF position(qReal::Id const &elem) const = 0;

		virtual void setConfiguration(qReal::Id const &elem, QPolygon const &newValue) = 0; //edgeElement
		virtual QPolygon configuration(qReal::Id const &elem) const = 0;

		//need to unite logical and graphical calls in this one
		virtual void setFrom(qReal::Id const &logicalId, qReal::Id const &id, qReal::Id const &newValue, qReal::Id const &newGraphicalValue) = 0; //edgeElement
		virtual qReal::Id from(qReal::Id const &elem) const = 0;

		virtual void setFromPort(qReal::Id const &elem, qreal const &newValue) = 0; //edgeElement
		virtual qreal fromPort(qReal::Id const &elem) const = 0;

		virtual void setTo(qReal::Id const &logicalId, qReal::Id const &id, qReal::Id const &newValue, qReal::Id const &newGraphicalValue) = 0;
		virtual qReal::Id to(qReal::Id const &elem) const = 0;

		virtual void setToPort(qReal::Id const &elem, qreal const &newValue) = 0;
		virtual qreal toPort(qReal::Id const &elem) const = 0;

		virtual qReal::EditorInterface* editorInterface(QString const &editor) const = 0;//editor manager


	};
