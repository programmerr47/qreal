#pragma once

#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QString>

#include "../pluginManager/editorManager.h"
//#include "../mainwindow/mainWindow.h"

//ёрий, посоветую как лучше...может с помощью волн.скобочек?
namespace qReal{
	class MainWindow;
	class EditorManager;
}

namespace qrRepo{
	class LogicalRepoApi;
}
	/// Dialog Control Api is an interface that
	/// implements the initialisation of graphical part

	class DialogControllerApi
	{
	public:
		//pligunDialog
		virtual QList<QString> getEditorsNames() const = 0;
		virtual QMap<QString, QString> getDiagramsNames() const = 0;
		virtual QMap<QString, QString> getElementsNames() const = 0;
		virtual QList<QString> prepareParentNamesByType(QString mTypeName) const = 0;//refWindow
		virtual QList<QVariant> getElementsDataByType(QString mTypeName) const = 0;//refWindow
		virtual void activateItemOrDiagram(const qReal::Id &id, bool bl = true, bool isSetSel = true) const = 0;//refWindow
		virtual void activateItemOrDiagram(QModelIndex const &modelIndex, bool bl = true, bool isSetSel = true) const = 0;//refWindow
	};

//}
