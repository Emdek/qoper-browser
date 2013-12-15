#include "SearchDelegate.h"

namespace Otter
{

SearchDelegate::SearchDelegate(QObject *parent) : QItemDelegate(parent)
{
}

void SearchDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	const int shortcutWidth = ((option.rect.width() > 150) ? 40 : 0);
	QRect decorationRectangle = option.rect;
	decorationRectangle.setRight(option.rect.height());

	QRect titleReactangle = option.rect;
	titleReactangle.setLeft(option.rect.height());

	if (shortcutWidth > 0)
	{
		titleReactangle.setRight(titleReactangle.right() - (shortcutWidth + 5));
	}

	drawBackground(painter, option, index);
	drawDecoration(painter, option, decorationRectangle, qvariant_cast<QIcon>(index.data(Qt::DecorationRole)).pixmap(option.rect.height(), option.rect.height()));
	drawDisplay(painter, option, titleReactangle, index.data(Qt::UserRole).toString());

	if (shortcutWidth > 0)
	{
		QRect shortcutReactangle = option.rect;
		shortcutReactangle.setLeft(option.rect.right() - 40);

		drawDisplay(painter, option, shortcutReactangle, index.data(Qt::UserRole + 2).toString());
	}
}

}
