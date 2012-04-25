#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QString>

namespace qReal {

    class EditorManager;

    class DialogControllerApi
    {
    public:
        DialogControllerApi(const EditorManager &mgr);
        virtual QList<QString> getEditorsNames();
        virtual QMap<QString, QString> getDiagramsNames();
        virtual QMap<QString, QString> getElementsNames();

    private:
        EditorManager mEditorManager;
    };

}
