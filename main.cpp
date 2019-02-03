#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QDir>
#include <stdlib.h>
#include "repo.h"


/*
 * Creates an empty c++ project
 * usage: pcreator projectName
 */

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("pcreate");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Creates an empty c++ project");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    parser.process(app);

    const QStringList args = parser.positionalArguments();

    if(args.isEmpty()){
        parser.showHelp();
    }
    QString projectName = args[0];

    QDir dir(QDir::currentPath());
    bool dirCreated = dir.mkdir(projectName);
    QString projectPath = dir.absoluteFilePath(projectName);

    if( !dirCreated){
        qWarning() << "unable to create directory: " << projectPath;
        return EXIT_FAILURE;
    }

    QFile cmakeFile(QDir(projectPath).absoluteFilePath("CMakeLists.txt"));
    cmakeFile.open(QIODevice::WriteOnly);
    cmakeFile.write(cmake(projectName).toUtf8());
    cmakeFile.close();


    QFile mainFile(QDir(projectPath).absoluteFilePath("main.cpp"));
    mainFile.open(QIODevice::WriteOnly);
    mainFile.write(mainProg().toUtf8());
    mainFile.close();


    QFile ignoreFile(QDir(projectPath).absoluteFilePath(".gitignore"));
    ignoreFile.open(QIODevice::WriteOnly);
    ignoreFile.write(gitIgnore().toUtf8());
    ignoreFile.close();

    QDir(projectPath).mkdir("build");

    return EXIT_SUCCESS;
}
