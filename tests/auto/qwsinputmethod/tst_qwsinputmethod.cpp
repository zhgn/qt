/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtTest/QtTest>

#ifdef Q_WS_QWS

//TESTED_CLASS=
//TESTED_FILES=

#include <QWSInputMethod>

class tst_QWSInputMethod : public QObject
{
    Q_OBJECT

public:
    tst_QWSInputMethod() {}
    virtual ~tst_QWSInputMethod() {}

private slots:
    void createSubClass();
};

/*
    Dummy class just to make sure the QWSInputMethod header compiles.
*/
class MyInputMethod : public QWSInputMethod
{
public:
    MyInputMethod() : QWSInputMethod() {}
    ~MyInputMethod() {}
    bool filter(int, int, int, bool, bool) { return true; }
    bool filter(const QPoint &, int, int) { return true; }
    void mouseHandler(int, int) {}
    void queryResponse(int, const QVariant &) {}
    void reset() {}

    void updateHandler(int) {}
};

void tst_QWSInputMethod::createSubClass()
{
    MyInputMethod im;
}

QTEST_MAIN(tst_QWSInputMethod)

#include "tst_qwsinputmethod.moc"

#else // Q_WS_QWS
QTEST_NOOP_MAIN
#endif
