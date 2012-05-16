#pragma once

#include <QtCore/QString>

#include "../pluginManager/editorManager.h"

class MainWindowControllerApi
{
public:
	virtual QString propertyDescription(const qReal::Id &id, const QString &propertyName) const =0;
	virtual QString propertyDisplayedName(const qReal::Id &id, const QString &propertyName) const =0;
	virtual QStringList getEnumValues(const qReal::Id &id, const QString &propertyName) const =0;
	virtual QStringList getPropertyNames(const qReal::Id &id) const =0;
	virtual QString getTypeName(const qReal::Id &id, const QString &propertyName) const =0;
	virtual QString friendlyName(const qReal::Id &id) const = 0;
	virtual QString description(const qReal::Id &id) const = 0;
	virtual QIcon icon(const qReal::Id &id) const = 0;
	virtual void setEditorManager(qReal::EditorManager *editorManager) = 0;
	virtual qReal::IdList elements(const qReal::Id &id) const = 0;
	virtual QStringList paletteGroups(const qReal::Id &editor, const qReal::Id &diagram) const = 0;
	virtual QStringList paletteGroupList(const qReal::Id &editor, const qReal::Id &diagram, const QString &group) const = 0;
};
