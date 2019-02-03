#include "repo.h"


QString cmake(const QString &projectName)
{
const char *projectTemplate =
R"___(cmake_minimum_required(VERSION 3.5)

project(%1)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Core)

set(SRCS main.cpp)
set(HDRS )

qt5_wrap_cpp(MOCS ${HDRS} )

add_executable(%1 ${SRCS} ${MOCS} )
target_link_libraries(%1 Qt5::Core )
)___";

return QString::fromUtf8(projectTemplate).arg(projectName);
}

QString mainProg()
{

const char *mainTemplate =
R"___(#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    qWarning() << "hello World";
}
)___";
return QString::fromUtf8(mainTemplate);

}

QString gitIgnore()
{
const char *gitIgnoreTemplate =
R"___(build
CMakeLists.txt.user
)___";
return QString::fromUtf8(gitIgnoreTemplate);
}
