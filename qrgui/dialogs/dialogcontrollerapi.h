#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QString>

#include "../pluginManager/editorManager.h"

namespace qReal {

    class EditorManager;

    class DialogControllerApi
    {
    public:
        DialogControllerApi(EditorManager &mgr);
        virtual QList<QString> getEditorsNames();
        virtual QMap<QString, QString> getDiagramsNames();
        virtual QMap<QString, QString> getElementsNames();

    private:
        EditorManager *mEditorManager;
    };

}
