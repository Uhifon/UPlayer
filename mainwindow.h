#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <play.h>
#include <QMainWindow>
#include <QTreeWidget>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    Play* myPlayer;
};

#endif // MAINWINDOW_H
