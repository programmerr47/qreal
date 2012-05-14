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
};
