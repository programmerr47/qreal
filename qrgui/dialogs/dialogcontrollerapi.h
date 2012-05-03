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
        DialogControllerApi(qReal::EditorManager &mgr,
                            qReal::MainWindow &mMW,
                            qrRepo::LogicalRepoApi const &mLogicalApi);

        //pligunDialog
        virtual QList<QString> getEditorsNames();
        virtual QMap<QString, QString> getDiagramsNames();
        virtual QMap<QString, QString> getElementsNames();
        virtual QList<QString> prepareParentNamesByType(QString mTypeName);//refWindow
        virtual QList<QVariant> getElementsDataByType(QString mTypeName);//refWindow
        virtual void activateItemOrDiagram(const qReal::Id &id, bool bl = true, bool isSetSel = true);//refWindow
        virtual void activateItemOrDiagram(QModelIndex const &modelIndex, bool bl = true, bool isSetSel = true);//refWindow
    private:
        qReal::MainWindow &mMainWindow;
        qReal::EditorManager &mEditorManager;

        qrRepo::LogicalRepoApi &mLogicalRepoApi;
    };

//}
