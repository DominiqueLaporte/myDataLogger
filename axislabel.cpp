/****************************************************************************
**
** Copyleft (C) 2015 Dominique Laporte <laporte.educnat@gmail.com>
**
** This file is part of the MyDataLogger
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/

#include <QtWidgets>

QString xAxisLabel(const int ms)
{
    int     day  = ms / (24 * 3600 * 1000);
    int     hour = (ms - day * (24 * 3600 * 1000)) / (3600 * 1000);
    int     min  = (ms - day * (24 * 3600 * 1000) - hour * (3600 * 1000)) / (60 * 1000);
    float   sec  = (float)(ms - day * (24 * 3600 * 1000) - hour * (3600 * 1000) - min * (60 * 1000)) / 1000;

    QString str = day ? QObject::tr("%1j ").arg(day) : "" ;
    str += hour ? QObject::tr("%1h ").arg(hour) : "" ;
    str += min ? QObject::tr("%1min ").arg(min) : "" ;
    str += sec ? QObject::tr("%1s").arg(sec, 2, 'f', 3) : "0" ;

    return str;
}
