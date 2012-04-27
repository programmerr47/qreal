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

    /// Dialog Control Api is an interface that
    /// implements the initialisation of graphical part

    class DialogControllerApi
    {
    public:
        DialogControllerApi(qReal::EditorManager &mgr, qReal::MainWindow &mMW);

        //pligunDialog
        virtual QList<QString> getEditorsNames();
        virtual QMap<QString, QString> getDiagramsNames();
        virtual QMap<QString, QString> getElementsNames();

        //refWindow
        virtual void activateItemOrDiagram(QString idIdentificator, bool bl = true, bool isSetSel = true);
        virtual void activateItemOrDiagram(QModelIndex const &modelIndex, bool bl = true, bool isSetSel = true);

    private:
        qReal::MainWindow &mMainWindow;
        qReal::EditorManager *mEditorManager;
    };

//}
