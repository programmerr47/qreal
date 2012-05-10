#ifndef MAINWINDOWCONTROLLERAPI_H
#define MAINWINDOWCONTROLLERAPI_H

#include <QtCore/QString>

#include "../pluginManager/editorManager.h"

class MainWindowControllerApi
{
public:
    MainWindowControllerApi(qReal::EditorManager &editorManager);
    QString propertyDescription(const qReal::Id &id, const QString &propertyName) const;
    QString propertyDisplayedName(const qReal::Id &id, const QString &propertyName) const;
    QStringList getEnumValues(const qReal::Id &id, const QString &propertyName) const;
    QStringList getPropertyNames(const qReal::Id &id) const;
    QString getTypeName(const qReal::Id &id, const QString &propertyName) const;

private:
    qReal::EditorManager &mEditorManager;
};

#endif // MAINWINDOWCONTROLLERAPI_H
