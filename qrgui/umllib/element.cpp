#include "element.h"

#include <QtGui>

using namespace qReal;

Element::Element()
	: mMoving(false)
	, mElementImpl(NULL)
	, mLogicalAssistApi(NULL)
	, mGraphicalAssistApi(NULL)
	, mControllerApi(NULL)
{
	setFlags(ItemIsSelectable | ItemIsMovable | ItemClipsChildrenToShape |
		ItemClipsToShape | ItemSendsGeometryChanges);
	setAcceptDrops(true);
	setCursor(Qt::PointingHandCursor);
}

void Element::setId(qReal::Id &id)
{
	mId = id;
	update();
}

Id Element::id() const
{
	return mId;
}

qReal::Id Element::logicalId() const
{
	return mControllerApi->logicalId(mId);
}

QString Element::name() const
{
	return mControllerApi->graphicalName(id());
}

void Element::updateData()
{
	setToolTip(mControllerApi->toolTip(id()));
}

QList<ContextMenuAction*> Element::contextMenuActions()
{
	return QList<ContextMenuAction*>();
}

QString Element::logicalProperty(QString const &roleName) const
{
	return mControllerApi->propertyByRoleName(logicalId(), roleName).toString();
}

void Element::setLogicalProperty(QString const &roleName, QString const &value)
{
	mControllerApi->setPropertyByRoleName(logicalId(), value, roleName);
}

void Element::setAssistApi(qReal::models::GraphicalModelAssistApi &graphicalAssistApi, qReal::models::LogicalModelAssistApi &logicalAssistApi,
                           ElementControllerApi &controllerApi)
{
    mGraphicalAssistApi = &graphicalAssistApi;
    mLogicalAssistApi = &logicalAssistApi;

    mControllerApi = &controllerApi;
}

void Element::initTitlesBy(QRectF const& contents)
{
	foreach (ElementTitle * const title, mTitles) {
		title->transform(contents);
	}
}

void Element::initTitles()
{
	initTitlesBy(boundingRect().adjusted(kvadratik, kvadratik, -kvadratik, -kvadratik));
}


void Element::singleSelectionState(const bool singleSelected) {
	if (singleSelected) {
		selectionState(true);
	}
	emit switchFolding(!singleSelected);
}

void Element::selectionState(const bool selected) {
	if (isSelected() != selected) {
		setSelected(selected);
	}
	if (!selected) {
		singleSelectionState(false);
	}
}
