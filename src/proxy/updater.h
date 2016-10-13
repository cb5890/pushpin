/*
 * Copyright (C) 2015 Fanout, Inc.
 *
 * This file is part of Pushpin.
 *
 * Pushpin is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Pushpin is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>

class ZhttpManager;

class Updater : public QObject
{
	Q_OBJECT

public:
	enum Mode
	{
		CheckMode,
		ReportMode
	};

	class Report
	{
	public:
		int connectionsMax;
		int connectionsMinutes;
		int messagesReceived;
		int messagesSent;
		int ops;

		Report() :
			connectionsMax(0),
			connectionsMinutes(0),
			messagesReceived(0),
			messagesSent(0),
			ops(0)
		{
		}
	};

	Updater(Mode mode, const QString &currentVersion, const QString &org, ZhttpManager *zhttp, QObject *parent = 0);
	~Updater();

	void setReport(const Report &report);

private:
	class Private;
	Private *d;
};

#endif
