#include <QApplication>
#include "ui/main_window.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"
#include "directors/modeldirector.hpp"
#include "directors/defaultcamdirector.hpp"

int main(int argc, char *argv[])
{
    Solution solution;

    solution.registerDataRepository(DEFAULT_DATA_REPOSITORY,
        std::make_shared<DataRepository>());
    
    solution.registerObjectDirector(MODEL_DIRECTOR,
        std::shared_ptr<IObjectDirector>(new ModelDirector()));
    
    solution.registerObjectDirector(DEFAULT_CAMERA_DIRECTOR,
        std::shared_ptr<IObjectDirector>(new DefaultCameraDirector()));

    QApplication app(argc, argv);

    MainWindow mainWindow(solution);
    mainWindow.show();

    return app.exec();
}