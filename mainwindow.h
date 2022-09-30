#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QVector>
#include <QMouseEvent>
#include <QPushButton>
#include <QGroupBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <math.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void ChooseColor();
    void ChooseModels(int);
    void updateHEX();
    void updateRGB();
    void updateCMYK();
    void updateHSV();
    void updateHSL();
    void updateXYZ();
    void updateLAB();
private:
    Ui::MainWindow *ui;
    QHBoxLayout *HBoxUp = new QHBoxLayout;
    QHBoxLayout *HBoxDown = new QHBoxLayout;
    QLabel* lbChosenColor = new QLabel(this);
    QWidget *Window = new QWidget();
    QPushButton *PbColor = new QPushButton("Choose color");
    QLineEdit *LeHEX = new QLineEdit;
    QSpinBox* RGBMass[3]{new QSpinBox,new QSpinBox,new QSpinBox};
    QDoubleSpinBox* CMYKMass[4]{new QDoubleSpinBox,new QDoubleSpinBox,new QDoubleSpinBox,new QDoubleSpinBox};
    QDoubleSpinBox* HSVMass[3]{new QDoubleSpinBox,new QDoubleSpinBox,new QDoubleSpinBox};
    QDoubleSpinBox* HSLMass[3]{new QDoubleSpinBox,new QDoubleSpinBox,new QDoubleSpinBox};
    QDoubleSpinBox* XYZMass[3]{new QDoubleSpinBox,new QDoubleSpinBox,new QDoubleSpinBox};
    QDoubleSpinBox* LABMass[3]{new QDoubleSpinBox,new QDoubleSpinBox,new QDoubleSpinBox};
    QGroupBox* GroupBoxMass[6]{new QGroupBox,new QGroupBox,new QGroupBox,new QGroupBox,new QGroupBox,new QGroupBox};
    QGroupBox* CurrentGBMass[3];
    QComboBox* Variant = new QComboBox(this);
    void paintEvent(QPaintEvent*);
    bool eventFilter(QObject *obj, QEvent *event);
    void setDataInputLayout();
    void groupBoxesSettings();
    void updateInfo();
    void spinBoxSettings();
    void allConnect();
    void allDisconnect();
    QColor chosenColor;
    math data;
};
#endif // MAINWINDOW_H
