/***********************************************************************
 *
 * Copyright (C) 2013 Graeme Gott <graeme@gottcode.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#include "txt_reader.h"

#include <QCoreApplication>
#include <QTextCursor>
#include <QTextStream>

//-----------------------------------------------------------------------------

void TxtReader::read(QIODevice* device, QTextDocument* document)
{
	QTextCursor cursor(document);
	read(device, cursor);
}

//-----------------------------------------------------------------------------

void TxtReader::read(QIODevice* device, QTextCursor& cursor)
{
	cursor.beginEditBlock();

	QTextStream stream(device);
	stream.setCodec("UTF-8");
	stream.setAutoDetectUnicode(true);

	while (!stream.atEnd()) {
		cursor.insertText(stream.read(0x4000));
		QCoreApplication::processEvents();
	}

	cursor.endEditBlock();
}

//-----------------------------------------------------------------------------
