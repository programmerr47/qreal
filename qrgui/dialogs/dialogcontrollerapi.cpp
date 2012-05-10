#include "dialogcontrollerapi.h"

//#include "../pluginManager/editorManager.h"
#include "../mainwindow/mainWindow.h"
//#include "../qrrepo/logicalRepoApi.h"

using namespace qReal;
using namespace qrRepo;



DialogControllerApi::DialogControllerApi(EditorManager &mgr, MainWindow &mMW, const LogicalRepoApi &mLogicalApi)
        : mEditorManager(mgr)
        , mMainWindow(mMW)
        , mLogicalRepoApi(mLogicalRepoApi)
{
}

//PluginDialog
QList<QString> DialogControllerApi::getEditorsNames()
{
    QList<QString> editorNames;
    foreach (Id editor, mEditorManager.editors()){
        editorNames.append(mEditorManager.friendlyName(editor));
    }
    return editorNames;
}

QMap<QString, QString> DialogControllerApi::getDiagramsNames()
{
    QMap<QString, QString> diagramNames;
    foreach (Id editor, mEditorManager.editors()){
        foreach (Id diagram, mEditorManager.diagrams(editor)){
            diagramNames.insert(mEditorManager.friendlyName(editor), mEditorManager.friendlyName(diagram));
        }
    }
    return diagramNames;
}

QMap<QString, QString> DialogControllerApi::getElementsNames()
{
    QMap<QString, QString> elementNames;
    foreach (Id editor, mEditorManager.editors()){
        foreach (Id diagram, mEditorManager.diagrams(editor)){
            foreach (Id element, mEditorManager.elements(diagram)){
                elementNames.insert(mEditorManager.friendlyName(diagram), mEditorManager.friendlyName(element));
            }
        }
    }
    return elementNames;
}

//refWindow
void DialogControllerApi::activateItemOrDiagram(Id const &id, bool bl, bool isSetSel)
{
        mMainWindow.activateItemOrDiagram(id, bl, isSetSel);
}

void DialogControllerApi::activateItemOrDiagram(QModelIndex const &modelIndex, bool bl, bool isSetSel)
{
        mMainWindow.activateItemOrDiagram(modelIndex, bl, isSetSel);
}

QList<QString> DialogControllerApi::prepareParentNamesByType(QString mTypeName)
{
    qReal::IdList idList = mLogicalRepoApi.elementsByType(mTypeName);
    int size = idList.size();
    QList<QString> parentNames;

    for (int i = 0; i < size; ++i)
    {
        qReal::Id parentId = mLogicalRepoApi.parent(idList[i]);
        QString parentName = mLogicalRepoApi.name(parentId);
        parentNames.append(parentName);
    }

    return parentNames;
}

QList<QVariant> DialogControllerApi::getElementsDataByType(QString mTypeName)
{
    qReal::IdList idList = mLogicalRepoApi.elementsByType(mTypeName);
    int size = idList.size();
    QList<QVariant> elementData;

    for (int i = 0; i < size; ++i)
    {
        QVariant data = idList[i].toString();
        elementData.append(data);
    }

    return elementData;
}
