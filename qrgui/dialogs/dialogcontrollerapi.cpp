#include "dialogcontrollerapi.h"

//#include "../pluginManager/editorManager.h"

using namespace qReal;

DialogControllerApi::DialogControllerApi(EditorManager &mgr, MainWindow &mMW)
        : mEditorManager(&mgr)
        , mMainWindow(mMW)
{
}

//PluginDialog
QList<QString> DialogControllerApi::getEditorsNames()
{
    QList<QString> editorNames;
    foreach (Id editor, mEditorManager->editors()){
        editorNames.append(mEditorManager->friendlyName(editor));
    }
    return editorNames;
}

QMap<QString, QString> DialogControllerApi::getDiagramsNames()
{
    QMap<QString, QString> diagramNames;
    foreach (Id editor, mEditorManager->editors()){
        foreach (Id diagram, mEditorManager->diagrams(editor)){
            diagramNames.insert(mEditorManager->friendlyName(editor), mEditorManager->friendlyName(diagram));
        }
    }
    return diagramNames;
}

QMap<QString, QString> DialogControllerApi::getElementsNames()
{
    QMap<QString, QString> elementNames;
    foreach (Id editor, mEditorManager->editors()){
        foreach (Id diagram, mEditorManager->diagrams(editor)){
            foreach (Id element, mEditorManager->elements(diagram)){
                elementNames.insert(mEditorManager->friendlyName(diagram), mEditorManager->friendlyName(element));
            }
        }
    }
    return elementNames;
}

//refWindow
void DialogControllerApi::activateItemOrDiagram(QString idIdentificator, bool bl, bool isSetSel)
{
    qReal::Id const id = qReal::Id::loadFromString(idIdentificator);
        mMainWindow.activateItemOrDiagram(id, bl, isSetSel);
}

void DialogControllerApi::activateItemOrDiagram(QModelIndex const &modelIndex, bool bl, bool isSetSel)
{
        mMainWindow.activateItemOrDiagram(modelIndex, bl, isSetSel);
}
