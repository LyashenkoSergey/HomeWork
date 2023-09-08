

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool flag=false;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void turn(bool flag);
    bool isEmpty();
    bool firstTurn();



private:
    Ui::MainWindow *ui;
};
