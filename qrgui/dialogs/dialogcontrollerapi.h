#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QString>

#include "../pluginManager/editorManager.h"
#include "../mainwindow/mainWindow.h"

//ёрий, посоветую как лучше...может с помощью волн.скобочек?
using namespace qReal;

    class MainWindow;

    /// Dialog Control Api is an interface that
    /// implements the initialisation of graphical part

    class DialogControllerApi
    {
    public:
        DialogControllerApi(EditorManager &mgr, MainWindow &mMW);

        //pligunDialog
        virtual QList<QString> getEditorsNames();
        virtual QMap<QString, QString> getDiagramsNames();
        virtual QMap<QString, QString> getElementsNames();

        //refWindow
        virtual void activateItemOrDiagram(QString idIdentificator, bool bl = true, bool isSetSel = true);
        virtual void activateItemOrDiagram(QModelIndex modelIndex, bool bl = true, bool isSetSel = true);

    private:
        MainWindow &mMainWindow;
        EditorManager *mEditorManager;
    };

//}
