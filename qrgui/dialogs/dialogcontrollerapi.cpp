#include "dialogcontrollerapi.h"

#include "../pluginManager/editorManager.h"

using namespace qReal;

DialogControllerApi::DialogControllerApi(const EditorManager &mgr)
{
    mEditorManager = mgr;
}

QList<QString> DialogControllerApi::getEditorsNames()
{
    QList<QString> editorNames();
    foreach (Id editor, mEditorManager.editors()){
        editorNames.append(mEditorManager.friendlyName(editor));
    }
    return editorNames();
}

QMap<QString, QString> DialogControllerApi::getDiagramsNames()
{
    QMap<QString, QString> diagramNames();
    foreach (Id editor, mEditorManager.editors()){
        foreach (Id diagram, mEditorManager.diagrams(editor)){
            diagramNames.insert(mEditorManager.friendlyName(editor), mEditorManager.friendlyName(diagram));
        }
    }
    return diagramNames;
}

QMap<QString, QString> DialogControllerApi::getElementsNames()
{
    QMap<QString, QString> elementNames();
    foreach (Id editor, mEditorManager.editors()){
        foreach (Id diagram, mEditorManager.diagrams(editor)){
            foreach (Id element, mEditorManager.elements(diagram)){
                elementNames.insert(mEditorManager.friendlyName(diagram), mEditorManager.friendlyName(element));
            }
        }
    }
    return elementNames;
}
