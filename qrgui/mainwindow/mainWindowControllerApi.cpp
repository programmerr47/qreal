#include "mainWindowControllerApi.h"

MainWindowControllerApi::MainWindowControllerApi(qReal::EditorManager &editorManager)
    : mEditorManager(editorManager)
{
}

QString MainWindowControllerApi::propertyDescription(const qReal::Id &id, const QString &propertyName) const
{
    return mEditorManager.propertyDescription(id, propertyName);
}

QString MainWindowControllerApi::propertyDisplayedName(const qReal::Id &id, const QString &propertyName) const
{
    return mEditorManager.propertyDisplayedName(id, propertyName);
}

QStringList MainWindowControllerApi::getEnumValues(const qReal::Id &id, const QString &propertyName) const
{
    return mEditorManager.getEnumValues(id, propertyName);
}

QStringList MainWindowControllerApi::getPropertyNames(const qReal::Id &id) const
{
    return mEditorManager.getPropertyNames(id);
}

QString MainWindowControllerApi::getTypeName(const qReal::Id &id, const QString &propertyName) const
{
    return mEditorManager.getTypeName(id, propertyName);
}
