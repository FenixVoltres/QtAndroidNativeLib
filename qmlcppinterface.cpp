#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QDebug>

#include "qmlcppinterface.h"

QmlCppInterface::QmlCppInterface(QObject *parent) :
    QObject(parent)
{
}

QString QmlCppInterface::getStringFromJava() const
{
    QAndroidJniObject resultString =
            QAndroidJniObject::callStaticObjectMethod("qt/android/java/OtherJavaClassWithOneMethodOnly",
                                                      "getMeSomeStringFromTheLibraryHey",
                                                      "()Ljava/lang/String;");

    QAndroidJniEnvironment env;
    if (env->ExceptionCheck())
    {
        env->ExceptionClear();

        qCritical() << "Something went wrong!";
        // Handle the exception
    }

    return resultString.toString();
}
