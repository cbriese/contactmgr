// datedelegate.cpp
#include "datedelegate.h"

DateDelegate::DateDelegate(const QString &format, QObject *parent)
	: QStyledItemDelegate(parent), m_format(format) {}

QString DateDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
	if (value.typeId() == QMetaType::QDate) {
		QDate date = value.toDate();
		if (date.isValid()) {
			return(locale.toString(date, m_format));
		}
	}

	return QStyledItemDelegate::displayText(value, locale);
}

