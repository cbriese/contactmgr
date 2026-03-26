// datedelegate.h
#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QStyledItemDelegate>
#include <QDate>
#include <QLocale>

class DateDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	DateDelegate(const QString &format, QObject *parent = nullptr);

	QString displayText(const QVariant &value, const QLocale &locale) const override;

private:
	QString m_format;
};

#endif // DATEDELEGATE_H
